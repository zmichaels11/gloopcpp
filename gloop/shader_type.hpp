/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shader_type.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:37 AM
 */

#ifndef SHADER_TYPE_HPP
#define SHADER_TYPE_HPP

#include <GL/glew.h>

namespace gloop {
    enum class shader_type : GLenum {
        UNKNOWN = 0,
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER,
        GEOMETRY = GL_GEOMETRY_SHADER,
        TESSELLATION_EVALUATION = GL_TESS_EVALUATION_SHADER,
        TESSELLATION_CONTROL = GL_TESS_CONTROL_SHADER,
        COMPUTE = GL_COMPUTE_SHADER
    };
}

#endif /* SHADER_TYPE_HPP */

