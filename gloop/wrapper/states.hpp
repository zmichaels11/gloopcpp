/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   states.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 4:52 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        constexpr gloop::enum_t BLEND = 0x0BE2;
        constexpr gloop::enum_t SCISSOR = 0x0C11;

        void enable(gloop::enum_t state);

        void disable(gloop::enum_t state);

        void blendFuncSeparate(
                gloop::enum_t srcRGB, gloop::enum_t dstRGB,
                gloop::enum_t srcAlpha, gloop::enum_t dstAlpha);

        void blendEquationSeparate(
                gloop::enum_t eqRGB,
                gloop::enum_t eqAlpha);

        void clear(gloop::bitfield_t clearMask);

        void depthRange(
                gloop::double_t near,
                gloop::double_t far);

        void scissor(
                gloop::int_t x, gloop::int_t y,
                gloop::sizei_t width, gloop::sizei_t height);

        void viewport(
                gloop::int_t x, gloop::int_t y,
                gloop::sizei_t width, gloop::sizei_t height);

        void clearColor(
                gloop::float_t red,
                gloop::float_t green,
                gloop::float_t blue,
                gloop::float_t alpha);

        void clearDepth(gloop::double_t depth);

        void clearStencil(gloop::int_t stencil);
        
    }
}