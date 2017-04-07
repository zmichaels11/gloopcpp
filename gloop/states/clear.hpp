/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include "../glint.hpp"
#include "../bitfields/clear_mask.hpp"

namespace gloop {
    namespace states {

        class clear {
        private:
            bitfields::clear_mask _mask;
            gloop::float_t _red;
            gloop::float_t _green;
            gloop::float_t _blue;
            gloop::float_t _alpha;
            gloop::double_t _depth;
            gloop::int_t _stencil;

        public:

            clear() :
            _mask(bitfields::clear_mask::COLOR),
            _red(0.0F), _green(0.0F), _blue(0.0F), _alpha(0.0F),
            _depth(1.0F), _stencil(0) {
            }

            clear(
                    const bitfields::clear_mask mask,
                    const gloop::float_t red, const gloop::float_t green, const gloop::float_t blue, const gloop::float_t alpha,
                    const gloop::double_t depth, const gloop::int_t stencil) :
            _mask(mask),
            _red(red), _green(green), _blue(blue), _alpha(alpha),
            _depth(depth), _stencil(stencil) {
            }

            clear withMask(const bitfields::clear_mask mask) const;

            clear withColor(
                const gloop::float_t red,
                const gloop::float_t green,
                const gloop::float_t blue,
                const gloop::float_t alpha) const;

            clear withDepth(const gloop::double_t depth) const;

            clear withStencil(const gloop::int_t stencil) const;

            gloop::float_t getClearRed() const;

            gloop::float_t getClearGreen() const;

            gloop::float_t getClearBlue() const;

            gloop::float_t getClearAlpha() const;

            gloop::double_t getClearDepth() const;

            gloop::int_t getClearStencil() const;

            bitfields::clear_mask getClearMask() const;

            void apply() const;

            inline void operator()() const {
                this->apply();
            }
        };
    }
}