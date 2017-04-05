/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

#include "uniform_binding.hpp"

namespace gloop {
    struct uniform_vec4_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat w;

        uniform_vec4_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat x = 0.0F, const GLfloat y = 0.0F, const GLfloat z = 0.0F, const GLfloat w = 0.0F) :
        pId(pId), loc(loc), x(x), y(y), z(z), w(w) {            
        }

        virtual void apply() const;
    };
}