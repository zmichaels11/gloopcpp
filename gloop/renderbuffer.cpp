/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "renderbuffer.hpp"

#include "enums/renderbuffer_internal_format.hpp"
#include "glint.hpp"
#include "wrapper/framebuffer_objects.hpp"
#include "tools.hpp"

namespace gloop {

    gloop::uint_t renderbuffer::getId() {
        if (!isValid()) {
            gloop::uint_t glId = 0;

            wrapper::createRenderbuffers(1, &glId);
            wrapper::namedRenderbufferStorage(glId, static_cast<gloop::enum_t> (_format), _width, _height);

            _id = glId;

            tools::assertGLError("Error creating renderbuffer!");
        }

        return _id;
    }

    bool renderbuffer::isValid() const {
        return _id != 0;
    }

    renderbuffer::~renderbuffer() {
        free();
    }

    void renderbuffer::free() {
        if (isValid()) {
            wrapper::deleteFramebuffers(1, &_id);
            _id = 0;
        }

        _width = 0;
        _height = 0;
        _format = static_cast<gloop::enums::renderbuffer_internal_format> (0);
    }

    gloop::sizei_t renderbuffer::getWidth() const {
        return _width;
    }

    gloop::sizei_t renderbuffer::getHeight() const {
        return _height;
    }

    enums::renderbuffer_internal_format renderbuffer::getInternalFormat() const {
        return _format;
    }
}