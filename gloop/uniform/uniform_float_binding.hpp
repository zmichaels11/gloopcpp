/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "uniform_binding.hpp"

#include <GL/glew.h>

namespace gloop {

    struct uniform_float_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLfloat value;

        uniform_float_binding(
                const GLuint pId = 0,
                const GLuint loc = 0,
                const GLfloat value = 0.0F) :
        pId(pId), loc(loc), value(value) {
        }

        virtual void apply() const;
    };
}