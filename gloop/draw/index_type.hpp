/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   index_type.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:38 AM
 */

#ifndef INDEX_TYPE_HPP
#define INDEX_TYPE_HPP

#include <GL/glew.h>

namespace gloop {
    namespace draw {
        enum class index_type : GLenum {
            UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
            UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
            UNSIGNED_INT = GL_UNSIGNED_INT
        };
    }
}

#endif /* INDEX_TYPE_HPP */

