/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   blend_func.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:43 AM
 */

#pragma once

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class blend_func : gloop::enum_t {
        ZERO = GL_ZERO,
        ONE = GL_ONE,
        SRC_COLOR = GL_SRC_COLOR,
        ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
        DST_COLOR = GL_DST_COLOR,
        ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
        SRC_ALPHA = GL_SRC_ALPHA,
        ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
        DST_ALPHA = GL_DST_ALPHA,
        ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
        CONSTANT_COLOR = GL_CONSTANT_COLOR,
        ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
        CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
        ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA
    };
    }
}