/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

#include "blend.hpp"
#include "clear.hpp"
#include "scissor.hpp"
#include "viewport.hpp"

namespace gloop {
    struct context {        
        blend currentBlend;
        scissor currentScissor;
        viewport currentViewport;
        clear currentClear;
        
        context(const GLsizei width = 0, const GLsizei height = 0)
                : currentScissor(false, {0, 0}, {width, height}), currentViewport({0, 0}, {width, height}) {}
    };
}