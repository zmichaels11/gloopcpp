/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_parameters.hpp
 * Author: zmichaels
 *
 * Created on April 4, 2017, 11:33 AM
 */

#ifndef TEXTURE_PARAMETERS_HPP
#define TEXTURE_PARAMETERS_HPP

#include <GL/glew.h>

namespace gloop {
    enum class texture_compare_func : GLint {
        LEQUAL = GL_LEQUAL,
        GEQUAL = GL_GEQUAL,
        LESS = GL_LESS,
        GREATER = GL_GREATER,
        EQUAL = GL_EQUAL,
        NOTEQUAL = GL_NOTEQUAL,
        ALWAYS = GL_ALWAYS,
        NEVER = GL_NEVER
    };
    
    enum class texture_compare_mode : GLint {
        NONE = GL_NONE,
        COMPARE_REF_TO_TEXTURE = GL_COMPARE_REF_TO_TEXTURE
    };
    
    enum class texture_min_filter : GLint {
        NEAREST = GL_NEAREST,
        LINEAR = GL_LINEAR,
        NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
        LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST,
        NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR,
        LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR
    };
    
    enum class texture_mag_filter : GLint {
        NEAREST = GL_NEAREST,
        LINEAR = GL_LINEAR
    };
    
    enum class texture_swizzle_color : GLint {
        RED = GL_RED,
        GREEN = GL_GREEN,
        BLUE = GL_BLUE,
        ALPHA = GL_ALPHA
    };
    
    enum class texture_wrap : GLint {
        CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
        CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,
        MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
        REPEAT = GL_REPEAT,
        MIRROR_CLAMP_TO_EDGE = GL_MIRROR_CLAMP_TO_EDGE
    };
    
    class texture_parameters {    
    private:
        GLint baseLevel;
        texture_compare_mode compareMode;
        texture_compare_func compareFunc;
        GLfloat lodBias;
        texture_min_filter minFilter;
        texture_mag_filter magFilter;
        GLfloat minLOD;
        GLfloat maxLOD;
        GLint maxLevel;
        texture_swizzle_color swizzleR;
        texture_swizzle_color swizzleG;
        texture_swizzle_color swizzleB;
        texture_swizzle_color swizzleA;
        texture_wrap wrapS;
        texture_wrap wrapT;
        texture_wrap wrapR;
        
    public:
    };
}

#endif /* TEXTURE_PARAMETERS_HPP */

