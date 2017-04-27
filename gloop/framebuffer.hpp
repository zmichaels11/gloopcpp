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
#include <iostream>
#include <map>

#include "glint.hpp"

namespace gloop {

    namespace enums {
        enum class framebuffer_attachment : gloop::enum_t;
        enum class framebuffer_target : gloop::enum_t;
    }

    class renderbuffer;
    class texture2D;

    class framebuffer {
    private:
        static framebuffer * CURRENT_FRAMEBUFFER;

    public:
        static framebuffer * getCurrentFramebuffer();
        static framebuffer * getDefaultFramebuffer();

    public:

        enum class attachment_type {
            UNKNOWN,
            RENDERBUFFER,
            TEXTURE
        };

        friend std::ostream& operator<<(std::ostream& os, attachment_type type);

        struct attachment {
            attachment_type type;

            union {
                texture2D * tex;
                renderbuffer * rb;
            };

            friend std::ostream& operator<<(std::ostream& os, const attachment& a);
        };
    private:
        gloop::uint_t _id;
        bool _externalInit;

        std::map<enums::framebuffer_attachment, attachment> _attachments;

    public:

        framebuffer(gloop::uint_t id) :
        _id(id),
        _externalInit(true) {
        }

        framebuffer() :
        _id(0),
        _externalInit(false) {
        }

        ~framebuffer();

        framebuffer(const framebuffer&) = delete;

        framebuffer(framebuffer&&) = default;

        framebuffer& operator=(const framebuffer&) = delete;

        framebuffer& operator=(framebuffer&&) = default;

        void bind(const enums::framebuffer_target target = static_cast<enums::framebuffer_target> (0x8D40));

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