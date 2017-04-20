/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   framebuffer.hpp
 * Author: zmichaels
 *
 * Created on April 18, 2017, 2:58 PM
 */

#pragma once

#include <cstddef>
#include <map>

#include "enums/framebuffer_attachment.hpp"
#include "enums/framebuffer_target.hpp"
#include "glint.hpp"
#include "renderbuffer.hpp"
#include "texture2D.hpp"

namespace gloop {

    class framebuffer {
    public:

        enum class attachment_type {
            UNKNOWN,
            RENDERBUFFER,
            TEXTURE
        };

        struct attachment {
            attachment_type type;

            union {
                texture2D * tex;
                renderbuffer * rb;
            };
        };
    private:
        gloop::uint_t _id;

        std::map<enums::framebuffer_attachment, attachment> _attachments;

    public:

        framebuffer() :
        _id(0) {
        }
        
        framebuffer(const framebuffer&) = delete;
        
        framebuffer(framebuffer&&) = default;
        
        ~framebuffer();


        void bind(const enums::framebuffer_target target = enums::framebuffer_target::FRAMEBUFFER);
        
        bool isValid() const;

        gloop::uint_t getId();

        std::size_t getAttachmentCount() const;

        bool hasAttachment(const enums::framebuffer_attachment attachment) const;

        attachment getAttachment(const enums::framebuffer_attachment attachment) const;

        void attach(const enums::framebuffer_attachment attachment, texture2D * texture);

        void attach(const enums::framebuffer_attachment attachment, renderbuffer * renderbuffer);

        attachment detach(const enums::framebuffer_attachment attachment);

        void free();
    };
}