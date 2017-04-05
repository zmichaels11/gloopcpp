/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sized_type.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:05 AM
 */

#ifndef SIZED_TYPE_HPP
#define SIZED_TYPE_HPP

#include "type.hpp"

namespace gloop {
    struct sized_type {
        type type;
        GLint size;
    };
}

#endif /* SIZED_TYPE_HPP */

