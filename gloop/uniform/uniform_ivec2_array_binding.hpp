/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_ivec2_array_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:11 AM
 */

#ifndef UNIFORM_IVEC2_ARRAY_BINDING_HPP
#define UNIFORM_IVEC2_ARRAY_BINDING_HPP

#include <GL/glew.h>

#include "uniform_binding.hpp"

namespace gloop {
    struct uniform_ivec2_array_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLsizei count;
        const GLint * values;

        uniform_ivec2_array_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint * values = nullptr, const GLsizei count = 1) :
        pId(pId), loc(loc), count(count), values(values) {
        }

        virtual void apply() const;
    };
}

#endif /* UNIFORM_IVEC2_ARRAY_BINDING_HPP */

