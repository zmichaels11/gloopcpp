/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_int_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:03 AM
 */

#ifndef UNIFORM_INT_BINDING_HPP
#define UNIFORM_INT_BINDING_HPP

#include "uniform_binding.hpp"

#include <GL/glew.h>

namespace gloop {
    struct uniform_int_binding : uniform_binding {
        GLuint pId;
        GLuint loc;
        GLint value;

        uniform_int_binding(
                const GLuint pId = 0, const GLuint loc = 0,
                const GLint value = 0) :
        pId(pId), loc(loc), value(value) {
        }

        virtual void apply() const;
    };
}

#endif /* UNIFORM_INT_BINDING_HPP */

