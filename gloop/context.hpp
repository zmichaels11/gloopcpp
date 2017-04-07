/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "glint.hpp"

#include "states/blend.hpp"
#include "states/clear.hpp"
#include "states/scissor.hpp"
#include "states/viewport.hpp"

namespace gloop {

    struct context {
        states::blend currentBlend;
        states::scissor currentScissor;
        states::viewport currentViewport;
        states::clear currentClear;

        context(
                const gloop::sizei_t width = 0,
                const gloop::sizei_t height = 0) :
        currentScissor(false,{0, 0}, 
        {
            width, height
        }),
        currentViewport({0, 0},
        {
width, height
        }) {
        }
    };
}