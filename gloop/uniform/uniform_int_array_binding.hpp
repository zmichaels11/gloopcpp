/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_int_array_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:05 AM
 */

#ifndef UNIFORM_INT_ARRAY_BINDING_HPP
#define UNIFORM_INT_ARRAY_BINDING_HPP

#include "uniform_binding.hpp"

#include <GL/glew.h>

namespace gloop {
    struct uniform_int_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLint * values;

        uniform_int_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), values(values), count(count) {
        }

        virtual void apply() const;
    };
}

#endif /* UNIFORM_INT_ARRAY_BINDING_HPP */

