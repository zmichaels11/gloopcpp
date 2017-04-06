/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

#include "uniform_binding.hpp"

namespace gloop {
    namespace uniform {

        struct uniform_vec4_binding : uniform_binding {
            GLuint pId;
            GLuint loc;

            struct vec4 {
                GLfloat x;
                GLfloat y;
                GLfloat z;
                GLfloat w;
            } value;

            virtual void apply() const;
        };
    }
}