/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#pragma once

#include "uniform_binding.hpp"

#include <GL/glew.h>

namespace gloop {
    namespace uniform {

        struct uniform_vec2_binding : uniform_binding {
            GLuint pId;
            GLuint loc;

            struct vec2 {
                GLfloat x;
                GLfloat y;
            } value;

            virtual void apply() const;
        };
    }
}