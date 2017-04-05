/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_vec2_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:04 AM
 */

#ifndef UNIFORM_VEC2_BINDING_HPP
#define UNIFORM_VEC2_BINDING_HPP

#include "uniform_binding.hpp"

#include <GL/glew.h>

namespace gloop {
    struct uniform_vec2_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLfloat x;
        GLfloat y;

        uniform_vec2_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat x = 0.0F, const GLfloat y = 0.0F) :
        pId(pId), loc(loc), x(x), y(y) {
        }

        virtual void apply() const;
    };
}

#endif /* UNIFORM_VEC2_BINDING_HPP */

