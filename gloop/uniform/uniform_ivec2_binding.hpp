/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_ivec2_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:09 AM
 */

#ifndef UNIFORM_IVEC2_BINDING_HPP
#define UNIFORM_IVEC2_BINDING_HPP

#include <GL/glew.h>

#include "uniform_binding.hpp"

namespace gloop {
    struct uniform_ivec2_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLint x;
        GLint y;

        uniform_ivec2_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint x = 0, const GLint y = 0) :
        pId(pId), loc(loc), x(x), y(y) {
        }

        virtual void apply() const;
    };
}

#endif /* UNIFORM_IVEC2_BINDING_HPP */

