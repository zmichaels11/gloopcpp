/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "framebuffer.hpp"

#include <cstddef>

#include "enums/framebuffer_target.hpp"
#include "glint.hpp"
#include "gloop_throw.hpp"

#include "wrapper/framebuffer_objects.hpp"
#include "wrapper/gl.hpp"
#include "exception/invalid_enum_exception.hpp"

namespace gloop {

    framebuffer::~framebuffer() {
        free();
    }

    void framebuffer::bind(const enums::framebuffer_target target) {
        wrapper::bindFramebuffer(static_cast<gloop::enum_t> (target), getId());
    }

    bool framebuffer::isValid() const {
        return _id != 0;
    }

    gloop::uint_t framebuffer::getId() {
        if (!isValid()) {
            gloop::uint_t glId = 0;

            wrapper::createFramebuffers(1, &glId);

            for (auto it = _attachments.begin(); it != _attachments.end(); it++) {
                const auto glEnum = static_cast<gloop::enum_t> (it->first);
                
                if (it->second.type == attachment_type::RENDERBUFFER) {                    
                    wrapper::namedFramebufferRenderbuffer(glId, glEnum, wrapper::RENDERBUFFER, it->second.rb->getId());
                } else if (it->second.type == attachment_type::TEXTURE) {
                    wrapper::namedFramebufferTexture(glId, glEnum, wrapper::TEXTURE_2D, it->second.tex->getId());
                } else {
                    gloop_throw(gloop::exception::invalid_enum_exception("Unknown attachment type!"));
                }
            }

            _id = glId;
        }

        return _id;
    }

    std::size_t framebuffer::getAttachmentCount() const {
        return _attachments.size();
    }

    bool framebuffer::hasAttachment(const enums::framebuffer_attachment attachment) const {
        for (auto it = _attachments.begin(); it != _attachments.end(); it++) {
            if (it->first == attachment) {
                return true;
            }
        }

        return false;
    }

    framebuffer::attachment framebuffer::getAttachment(const enums::framebuffer_attachment attachment) const {
        for (auto it = _attachments.begin(); it != _attachments.end(); it++) {
            if (it->first == attachment) {
                return it->second;
            }
        }

        framebuffer::attachment out;

        out.type = framebuffer::attachment_type::UNKNOWN;

        return out;
    }

    void framebuffer::attach(const enums::framebuffer_attachment attachment, texture2D* texture) {        
        framebuffer::attachment storage;

        storage.type = framebuffer::attachment_type::TEXTURE;
        storage.tex = texture;

        _attachments[attachment] = storage;

        if (isValid()) {
            wrapper::namedFramebufferTexture(_id, static_cast<gloop::enum_t> (attachment), texture->getId(), 0);
        }
    }

    void framebuffer::attach(const enums::framebuffer_attachment attachment, renderbuffer* renderbuffer) {        
        framebuffer::attachment storage;

        storage.type = framebuffer::attachment_type::RENDERBUFFER;
        storage.rb = renderbuffer;

        _attachments[attachment] = storage;

        if (isValid()) {
            wrapper::namedFramebufferRenderbuffer(_id, static_cast<gloop::enum_t> (attachment), wrapper::RENDERBUFFER, renderbuffer->getId());
        }
    }

    framebuffer::attachment framebuffer::detach(const enums::framebuffer_attachment attachment) {
        for (auto it = _attachments.begin(); it != _attachments.end(); it++) {
            if (it->first == attachment) {
                _attachments.erase(it);

                return it->second;
            }
        }

        framebuffer::attachment out;

        out.type = framebuffer::attachment_type::UNKNOWN;

        return out;
    }

    void framebuffer::free() {
        if (isValid()) {
            wrapper::deleteFramebuffers(1, &_id);
            _id = 0;
        }

        _attachments.clear();
    }
}