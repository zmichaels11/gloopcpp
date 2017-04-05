/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

#include "uniform_binding.hpp"

namespace gloop {
    struct uniform_ivec4_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLint x;
        GLint y;
        GLint z;
        GLint w;

        uniform_ivec4_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint x = 0, const GLint y = 0, const GLint z = 0, const GLint w = 0) :
        pId(pId), loc(loc), x(x), y(y), z(z), w(w) {
        }

        virtual void apply() const;
    };
}