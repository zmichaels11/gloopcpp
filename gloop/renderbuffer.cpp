/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "renderbuffer.hpp"

#include <iostream>

#include "enums/renderbuffer_internal_format.hpp"
#include "glint.hpp"
#include "tools.hpp"
#include "wrapper/framebuffer_objects.hpp"

namespace gloop {

    gloop::uint_t renderbuffer::getId() {
        if (!isValid()) {
            gloop::uint_t glId = 0;

            wrapper::createRenderbuffers(1, &glId);
            wrapper::namedRenderbufferStorage(glId, static_cast<gloop::enum_t> (_format), _size.width, _size.height);

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

        _size.width = 0;
        _size.height = 0;
        _format = static_cast<gloop::enums::renderbuffer_internal_format> (0);
    }

    const gloop::renderbuffer::size& renderbuffer::getSize() const {
        return _size;
    }

    enums::renderbuffer_internal_format renderbuffer::getInternalFormat() const {
        return _format;
    }

    std::ostream& operator<<(std::ostream& os, const renderbuffer& rb) {
        os << "renderbuffer: [";

        if (rb.isValid()) {
            os << "id: " << rb._id;
            os << " format:" << rb._format;
            os << " " << rb._size;
            os << "]";
        } else {
            os << "UNINITIALIZED]";
        }

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const renderbuffer::size& s) {
        return os << "size: <"
                << s.width
                << ", "
                << s.height
                << ">";
    }
}