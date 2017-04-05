/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_ivec4_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:11 AM
 */

#ifndef UNIFORM_IVEC4_BINDING_HPP
#define UNIFORM_IVEC4_BINDING_HPP

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

#endif /* UNIFORM_IVEC4_BINDING_HPP */

