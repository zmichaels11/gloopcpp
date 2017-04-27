/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "clear.hpp"

#include <iostream>

#include "../bitfields/clear_mask.hpp"
#include "../exception/invalid_operation_exception.hpp"
#include "../glint.hpp"
#include "../gloop_throw.hpp"
#include "../wrapper/states.hpp"

namespace gloop {
    namespace {
        static bool maskHasColor(bitfields::clear_mask mask) {
            return (mask & bitfields::clear_mask::COLOR) == bitfields::clear_mask::COLOR;
        }
        
        static bool maskHasDepth(bitfields::clear_mask mask) {
            return (mask & bitfields::clear_mask::DEPTH) == bitfields::clear_mask::DEPTH;
        }
        
        static bool maskHasStencil(bitfields::clear_mask mask) {
            return (mask & bitfields::clear_mask::STENCIL) == bitfields::clear_mask::STENCIL;
        }
    }
    
    namespace states {
        std::stack<clear> clear::CLEAR_STACK;
        clear clear::CURRENT_CLEAR;
        
        void clear::push() {
            CLEAR_STACK.push(CURRENT_CLEAR);
        }
        
        clear clear::pop() {
            if (CLEAR_STACK.empty()) {
                gloop_throw(gloop::exception::invalid_operation_exception("Attempted to pop empty stack!"));
            } else {
                clear current = CURRENT_CLEAR;
                clear restore = CLEAR_STACK.top();
                
                CLEAR_STACK.pop();
                
                restore();
                return current;
            }
        }
        
        const clear& clear::getCurrentClear() {
            return CURRENT_CLEAR;
        }
        
        std::ostream& operator<<(std::ostream& os, clear c) {
            return os << "clear: ["
                    << c._color
                    << ", depth: " << c._depth
                    << ", stencil: " << c._stencil
                    << ", mask: " << c._mask
                    << "]";
        }

        std::ostream& operator<<(std::ostream& os, clear::color c) {
            return os << "color: <"
                    << c.red << ", "
                    << c.green << ", "
                    << c.blue << ", "
                    << c.alpha << ">";
        }
        
        clear::clear() {
            _mask = bitfields::clear_mask::COLOR;
            _color = clear::color({0.0F, 0.0F, 0.0F, 0.0F});
            _depth = 1.0F;
            _stencil = 0;
        }

        clear clear::withMask(const bitfields::clear_mask mask) const {
            return clear(mask, _color, _depth, _stencil);
        }

        clear clear::withColor(const clear::color color) const {
            return clear(_mask, color, _depth, _stencil);
        }
        
        clear clear::withColor(
                const gloop::float_t red,
                const gloop::float_t green,
                const gloop::float_t blue,
                const gloop::float_t alpha) const {

            return clear(_mask, {red, green, blue, alpha}, _depth, _stencil);
        }

        clear clear::withDepth(const gloop::double_t depth) const {
            return clear(_mask, _color, depth, _stencil);
        }

        clear clear::withStencil(const gloop::int_t stencil) const {
            return clear(_mask, _color, _depth, stencil);
        }

        gloop::double_t clear::getClearDepth() const {
            return _depth;
        }

        gloop::int_t clear::getClearStencil() const {
            return _stencil;
        }
        
        const clear::color& clear::getClearColor() const {
            return _color;
        }

        bitfields::clear_mask clear::getClearMask() const {
            return _mask;
        }

        void clear::apply() const {
            CURRENT_CLEAR = *this;
            
            if (maskHasColor(_mask)) {
                gloop::wrapper::clearColor(_color.red, _color.green, _color.blue, _color.alpha);
            }

            if (maskHasDepth(_mask)) {
                gloop::wrapper::clearDepth(_depth);
            }

            if (maskHasStencil(_mask)) {
                gloop::wrapper::clearStencil(_stencil);
            }

            gloop::wrapper::clear(static_cast<gloop::bitfield_t> (_mask));            
        }
    }
}