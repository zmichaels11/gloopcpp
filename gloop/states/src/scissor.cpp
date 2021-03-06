/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "scissor.hpp"

#include <iostream>
#include <stack>

#include "../exception/invalid_operation_exception.hpp"
#include "../gloop_throw.hpp"
#include "../wrapper/states.hpp"

namespace gloop {
    namespace states {
        std::stack<scissor> scissor::SCISSOR_STACK;
        scissor scissor::CURRENT_SCISSOR(false, {0, 0}, {0, 0});
        
        void scissor::push() {
            SCISSOR_STACK.push(CURRENT_SCISSOR);
        }
        
        scissor scissor::pop() {
            if (SCISSOR_STACK.empty()) {
                gloop_throw(gloop::exception::invalid_operation_exception("Attempted to pop empty stack!"));
            } else {
                scissor current = CURRENT_SCISSOR;
                scissor restore = SCISSOR_STACK.top();
                
                SCISSOR_STACK.pop();
                
                restore();
                return current;
            }
        }
        
        const scissor& scissor::getCurrentScissor() {
            return CURRENT_SCISSOR;
        }

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
            CURRENT_SCISSOR = *this;
            
            if (_enable) {
                gloop::wrapper::enable(gloop::wrapper::SCISSOR);
                gloop::wrapper::scissor(_offset.x, _offset.y, _size.width, _size.height);
            } else {
                gloop::wrapper::disable(gloop::wrapper::SCISSOR);
            }
        }

        std::ostream& operator<<(std::ostream& os, const scissor::offset& o) {
            return os << "offset: <"
                    << o.x
                    << ", "
                    << o.y
                    << ", "
                    << ">";
        }

        std::ostream& operator<<(std::ostream& os, const scissor::size& s) {
            return os << "size: <"
                    << s.width
                    << ", "
                    << s.height
                    << ">";
        }

        std::ostream& operator<<(std::ostream& os, const scissor& s) {
            return os << "scissor: ["
                    << "enabled: " << (s._enable ? "true" : "false")
                    << ", "
                    << s._offset
                    << ", "
                    << s._size
                    << "]";
        }
    }
}