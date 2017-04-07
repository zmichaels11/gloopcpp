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
            return clear(mask, _red, _green, _blue, _alpha, _depth, _stencil);
        }

        clear clear::withColor(
                const gloop::float_t red,
                const gloop::float_t green,
                const gloop::float_t blue,
                const gloop::float_t alpha) const {

            return clear(_mask, red, green, blue, alpha, _depth, _stencil);
        }

        clear clear::withDepth(const gloop::double_t depth) const {
            return clear(_mask, _red, _green, _blue, _alpha, depth, _stencil);
        }

        clear clear::withStencil(const gloop::int_t stencil) const {
            return clear(_mask, _red, _green, _blue, _alpha, _depth, stencil);
        }

        gloop::double_t clear::getClearDepth() const {
            return _depth;
        }

        gloop::int_t clear::getClearStencil() const {
            return _stencil;
        }

        bitfields::clear_mask clear::getClearMask() const {
            return _mask;
        }

        void clear::apply() const {
            if (maskHasColor(_mask)) {
                glClearColor(_red, _green, _blue, _alpha);
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