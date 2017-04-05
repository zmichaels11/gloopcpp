/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   range_elements.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:43 AM
 */

#ifndef RANGE_ELEMENTS_HPP
#define RANGE_ELEMENTS_HPP

#include <GL/glew.h>

#include "call.hpp"
#include "index_type.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {

        struct range_elements {
            mode drawMode;
            GLuint start;
            GLuint end;
            GLsizei count;
            index_type indexType;
            const GLvoid * indices;

            range_elements(
                    const mode mode = mode::POINTS,
                    const GLuint start = 0,
                    const GLuint end = 0,
                    const GLsizei count = 0,
                    const index_type type = index_type::UNSIGNED_INT,
                    const GLvoid * indices = nullptr) :
            drawMode(mode), start(start), end(end), indexType(type), indices(indices) {
            }

            virtual void draw() const;
        };
    }
}

#endif /* RANGE_ELEMENTS_HPP */

