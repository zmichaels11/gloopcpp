/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <iostream>
#include <stack>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {
        enum class clear_mask : gloop::bitfield_t;
    }
    
    namespace states {

        class clear {
        private:
            static std::stack<clear> CLEAR_STACK;
            static clear CURRENT_CLEAR;
            
        public:
            static void push();
            static clear pop();
            static const clear& getCurrentClear();
            
        public:

            struct color {
                gloop::float_t red;
                gloop::float_t green;
                gloop::float_t blue;
                gloop::float_t alpha;

                friend std::ostream& operator<<(std::ostream& os, color c);
            };

        private:
            bitfields::clear_mask _mask;
            color _color;
            gloop::double_t _depth;
            gloop::int_t _stencil;

        public:

            clear();

            clear(
                    const bitfields::clear_mask mask,
                    const color color,
                    const gloop::double_t depth, const gloop::int_t stencil) :
            _mask(mask),
            _color(color),
            _depth(depth), _stencil(stencil) {
            }

            clear withMask(const bitfields::clear_mask mask) const;

            clear withColor(const color color) const;

            clear withColor(
                    const gloop::float_t red,
                    const gloop::float_t green,
                    const gloop::float_t blue,
                    const gloop::float_t alpha) const;

            clear withDepth(const gloop::double_t depth) const;

            clear withStencil(const gloop::int_t stencil) const;

            const color& getClearColor() const;

            gloop::double_t getClearDepth() const;

            gloop::int_t getClearStencil() const;

            bitfields::clear_mask getClearMask() const;

            void apply() const;

            inline void operator()() const {
                this->apply();
            }
            
            friend std::ostream& operator<<(std::ostream& os, clear c);
        };
    }
}