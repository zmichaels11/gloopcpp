/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vertex_attribute_type.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:04 AM
 */

#ifndef VERTEX_ATTRIBUTE_TYPE_HPP
#define VERTEX_ATTRIBUTE_TYPE_HPP

namespace gloop {
    enum class vertex_attribute_type {
        FLOAT,
        INT,
        UINT,
        VEC2,
        VEC3,
        VEC4,
        IVEC2,
        IVEC3,
        IVEC4,
        UVEC2,
        UVEC3,
        UVEC4
    };
}


#endif /* VERTEX_ATTRIBUTE_TYPE_HPP */

