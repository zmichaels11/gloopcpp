/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "clear.hpp"

#include "../bitfields/clear_mask.hpp"
#include "../glint.hpp"

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
            if (maskHasColor(_mask)) {
                glClearColor(_color.red, _color.green, _color.blue, _color.alpha);
            }

            if (maskHasDepth(_mask)) {
                glClearDepth(_depth);
            }

            if (maskHasStencil(_mask)) {
                glClearStencil(_stencil);
            }

            glClear(static_cast<gloop::bitfield_t> (_mask));
        }
    }
}