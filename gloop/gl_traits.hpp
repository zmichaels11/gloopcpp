/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gl_traits.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 10:40 AM
 */

#pragma once

namespace gloop {
#define GLEW 1
#define GLES2 2
#define GLES3 3
    
#ifndef GL
#define __GL_NOT_DEFINED
#define GL 0
#endif
    
    constexpr bool isGLEW = (GL == GLEW);
    constexpr bool isGLES2 = (GL == GLES2);
    constexpr bool isGLES3 = (GL == GLES3);
    constexpr bool isGL = isGLEW;
    constexpr bool isGLES = isGLES2 || isGLES3;    
    
#ifdef __GL_NOT_DEFINED
#undef GL
#undef __GL_NOT_DEFINED
#endif
    
#undef GLES3
#undef GLES2
#undef GLEW
}