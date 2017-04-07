/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   blend_eq.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:44 AM
 */

#pragma once

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class blend_eq : gloop::enum_t {
            ADD = GL_FUNC_ADD,
            SUBTRACT = GL_FUNC_SUBTRACT,
            REVERSE_SUBTRACT = GL_FUNC_REVERSE_SUBTRACT,
            MIN = GL_MIN,
            MAX = GL_MAX
        };
    }
}