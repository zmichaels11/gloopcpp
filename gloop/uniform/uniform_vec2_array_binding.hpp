/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_vec2_array_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:06 AM
 */

#ifndef UNIFORM_VEC2_ARRAY_BINDING_HPP
#define UNIFORM_VEC2_ARRAY_BINDING_HPP

#include <GL/glew.h>

#include "uniform_binding.hpp"

namespace gloop {
    struct uniform_vec2_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_vec2_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };
}

#endif /* UNIFORM_VEC2_ARRAY_BINDING_HPP */

