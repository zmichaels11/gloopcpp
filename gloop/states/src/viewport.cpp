/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "viewport.hpp"

#include <iostream>
#include <stack>

#include "../exception/invalid_operation_exception.hpp"
#include "../gloop_throw.hpp"
#include "../wrapper/states.hpp"
#include "depth_range.hpp"

namespace gloop {
    namespace states {
        std::stack<viewport> viewport::VIEWPORT_STACK;
        viewport viewport::CURRENT_VIEWPORT({0, 0}, {0, 0});
        
        void viewport::push() {
            VIEWPORT_STACK.push(CURRENT_VIEWPORT);
        }
        
        viewport viewport::pop() {
            if (VIEWPORT_STACK.empty()) {
                gloop_throw(gloop::exception::invalid_operation_exception("Attempted to pop empty stack!"));
            } else {
                viewport current = CURRENT_VIEWPORT;
                viewport restore = VIEWPORT_STACK.top();
                
                VIEWPORT_STACK.pop();
                
                restore();
                return current;
            }
        }
        
        const viewport& viewport::getCurrentViewport() {
            return CURRENT_VIEWPORT;
        }
        
        std::ostream& operator<<(std::ostream& os, const viewport::offset& o) {
            return os << "offset: <" << o.x << ", " << o.y << ">";
        }

        std::ostream& operator<<(std::ostream& os, const viewport::size& s) {
            return os << "size: <"
                    << s.width
                    << ", "
                    << s.height
                    << ">";
        }

        std::ostream& operator<<(std::ostream& os, const viewport& v) {
            return os << "viewport: ["
                    << v._offset
                    << ", " << v._size
                    << ", " << v._depthRange
                    << "]";
        }

        viewport viewport::withOffset(const offset offset) const {
            return viewport(offset, _size, _depthRange);
        }

        viewport viewport::withSize(const size sz) const {
            return viewport(_offset, sz, _depthRange);
        }

        viewport viewport::withDepthRange(const depth_range depthRange) const {
            return viewport(_offset, _size, depthRange);
        }

        const viewport::offset& viewport::getOffset() const {
            return _offset;
        }

        const viewport::size& viewport::getSize() const {
            return _size;
        }

        const depth_range& viewport::getDepthRange() const {
            return _depthRange;
        }

        void viewport::apply() const {
            CURRENT_VIEWPORT = *this;
            gloop::wrapper::viewport(_offset.x, _offset.y, _size.width, _size.height);
            _depthRange();
        }
    }
}