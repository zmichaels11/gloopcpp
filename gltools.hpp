/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gl_util.hpp
 * Author: zmichaels
 *
 * Created on March 20, 2017, 2:35 PM
 */

#ifndef GLTOOLS_HPP
#define GLTOOLS_HPP

#include <GL/glew.h>
#include <cstddef>

namespace gltools {
    GLuint createShader(const GLenum shaderType, const char * fileName);
    
    GLuint createProgram(const GLuint * shaders, const std::size_t count);
}

#endif /* GL_UTIL_HPP */

