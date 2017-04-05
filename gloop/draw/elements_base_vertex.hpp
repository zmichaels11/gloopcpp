/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   elements_base_vertex.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:42 AM
 */

#ifndef ELEMENTS_BASE_VERTEX_HPP
#define ELEMENTS_BASE_VERTEX_HPP

#include <GL/glew.h>

#include "call.hpp"
#include "index_type.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {
        struct elements_base_vertex : draw_call {
            mode drawMode;
            GLsizei count;
            index_type indexType;
            const GLvoid * indices;
            GLint baseVertex;            

            virtual void draw() const;
        };
    }
}

#endif /* ELEMENTS_BASE_VERTEX_HPP */

