/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_float_array_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:03 AM
 */

#ifndef UNIFORM_FLOAT_ARRAY_BINDING_HPP
#define UNIFORM_FLOAT_ARRAY_BINDING_HPP

#include "uniform_binding.hpp"

#include <GL/glew.h>

namespace gloop {
    struct uniform_float_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLfloat * values;

        uniform_float_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLfloat * values = nullptr,
                const GLsizei count = 1) :
        pId(pId), loc(loc), count(count), values(values) {
        }

        virtual void apply() const;
    };
}

#endif /* UNIFORM_FLOAT_ARRAY_BINDING_HPP */

