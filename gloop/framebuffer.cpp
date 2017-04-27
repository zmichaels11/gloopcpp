/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "framebuffer.hpp"

#include <cstddef>
#include <iostream>
#include <stack>

#include "enums/framebuffer_attachment.hpp"
#include "enums/framebuffer_target.hpp"
#include "glint.hpp"
#include "gloop_throw.hpp"
#include "renderbuffer.hpp"
#include "texture2D.hpp"

#include "wrapper/framebuffer_objects.hpp"
#include "wrapper/gl.hpp"
#include "exception/invalid_enum_exception.hpp"

namespace gloop {

    std::ostream& operator<<(std::ostream& os, framebuffer::attachment_type type) {
        switch (type) {
            case framebuffer::attachment_type::RENDERBUFFER:
                os << "RENDERBUFFER";
                break;
            case framebuffer::attachment_type::TEXTURE:
                os << "TEXTURE";
                break;
            default:
                os << "UNKNOWN";
                break;
        }

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const framebuffer::attachment& a) {
        os << "attachment: [";
        os << "type: " << a.type;

        switch (a.type) {
            case framebuffer::attachment_type::TEXTURE:
                if (a.tex) {
                    os << ", " << *(a.tex);
                } else {
                    os << ", texture2D: [null]";
                }
                break;
            case framebuffer::attachment_type::RENDERBUFFER:
                if (a.rb) {
                    os << ", " << *(a.rb);
                } else {
                    os << ", renderbuffer: [null]";
                }
                break;
            default:
                // nothing to do
                break;
        }

        return os << "]";
    }

    framebuffer::~framebuffer() {
        free();
    }
    
    framebuffer * framebuffer::getCurrentFramebuffer() {
        return CURRENT_FRAMEBUFFER;
    } 
    
    namespace {
        static framebuffer DEFAULT_FRAMEBUFFER(0);
    }
    
    framebuffer * framebuffer::CURRENT_FRAMEBUFFER = &DEFAULT_FRAMEBUFFER;
    std::stack<framebuffer * > framebuffer::FB_STACK;
    
    framebuffer * framebuffer::getDefaultFramebuffer() {
        return &DEFAULT_FRAMEBUFFER;
    }
    
    void framebuffer::push() {
        FB_STACK.push(CURRENT_FRAMEBUFFER);
    }
    
    framebuffer * framebuffer::pop() {
        if (FB_STACK.empty()) {
            gloop_throw(gloop::exception::invalid_operation_exception("Attempted to pop empty stack!"));
        }
        
        auto * current = CURRENT_FRAMEBUFFER;
        auto * restore = FB_STACK.top();
        
        FB_STACK.pop();
        
        restore->bind();
        return current;
    }

    void framebuffer::bind(const enums::framebuffer_target target) {
        wrapper::bindFramebuffer(static_cast<gloop::enum_t> (target), getId());
        CURRENT_FRAMEBUFFER = this;
    }

    bool framebuffer::isValid() const {
        if (_externalInit) {
            return true;
        } else {
            return _id != 0;
        }
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