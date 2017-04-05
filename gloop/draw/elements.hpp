/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   elements.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:39 AM
 */

#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <GL/glew.h>

#include "call.hpp"
#include "index_type.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {
        struct elements : draw_call {
            mode drawMode;
            GLsizei count;
            index_type indexType;
            const GLvoid * indices;                        
            
            virtual void draw() const;
        };
    }
}

#endif /* ELEMENTS_HPP */

