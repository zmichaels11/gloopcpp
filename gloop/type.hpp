/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   type.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:05 AM
 */

#ifndef TYPE_HPP
#define TYPE_HPP

#include <GL/glew.h>

namespace gloop {
    enum class type : GLenum {
        UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
        BYTE = GL_BYTE,
        UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
        SHORT = GL_SHORT,
        UNSIGNED_INT = GL_UNSIGNED_INT,
        INT = GL_INT,
        FLOAT = GL_FLOAT,
        DOUBLE = GL_DOUBLE
    };
}

#endif /* TYPE_HPP */

