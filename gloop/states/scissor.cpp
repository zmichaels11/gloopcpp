/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "scissor.hpp"

#include <GL/glew.h>

namespace gloop {
    namespace states {

        scissor scissor::withEnable(const bool enable) const {
            return scissor(enable, _offset, _size);
        }

        scissor scissor::withOffset(const offset offset) const {
            return scissor(_enable, offset, _size);
        }

        scissor scissor::withSize(const size size) const {
            return scissor(_enable, _offset, size);
        }

        const scissor::offset& scissor::getOffset() const {
            return _offset;
        }

        const scissor::size& scissor::getSize() const {
            return _size;
        }

        bool scissor::isEnabled() const {
            return _enable;
        }

        void scissor::apply() const {
            if (_enable) {
                glEnable(GL_SCISSOR_TEST);
                glScissor(_offset.x, _offset.y, _size.width, _size.height);
            } else {
                glDisable(GL_SCISSOR_TEST);
            }
        }
    }
}