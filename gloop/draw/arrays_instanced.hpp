/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arrays_instanced.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:41 AM
 */

#ifndef ARRAYS_INSTANCED_HPP
#define ARRAYS_INSTANCED_HPP

#include <GL/glew.h>

#include "call.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {

        struct arrays_instanced : draw_call {
            mode drawMode;
            GLint first;
            GLsizei count;
            GLsizei primitiveCount;

            virtual void draw() const;
        };
    }
}

#endif /* ARRAYS_INSTANCED_HPP */

