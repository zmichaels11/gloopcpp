/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arrays.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:36 AM
 */

#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <GL/glew.h>

#include "call.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {
        struct arrays : draw_call {            
            mode drawMode;
            GLint first;
            GLsizei count;            
            
            virtual void draw() const;
        };
    }
}

#endif /* ARRAYS_HPP */

