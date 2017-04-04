/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   draw_calls.hpp
 * Author: zmichaels
 *
 * Created on April 4, 2017, 12:38 PM
 */

#ifndef DRAW_CALLS_HPP
#define DRAW_CALLS_HPP

#include <GL/glew.h>

namespace gloop {
    namespace draw {                
        enum class mode : GLenum {
            POINTS = GL_POINTS,
            LINE_STRIP = GL_LINE_STRIP,
            LINE_LOOP = GL_LINE_LOOP,
            LINES = GL_LINES,
            LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY,
            LINES_ADJACENCY = GL_LINES_ADJACENCY,
            TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
            TRIANGLE_FAN = GL_TRIANGLE_FAN,
            TRIANGLES = GL_TRIANGLES,
            TRIANGLE_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
            TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY,
            PATCHES = GL_PATCHES
        };
        
        struct draw_call {
            virtual void draw() const = 0;
            
            inline void operator()() const {
                draw();
            }
        };

        struct arrays : draw_call {            
            mode drawMode;
            GLint first;
            GLsizei count;

            arrays(
                    const mode mode = mode::TRIANGLES,
                    const GLint first = 0, const GLsizei count = 0)
            : drawMode(mode), first(first), count(count) {
            }
            
            virtual void draw() const;
        };

        enum class index_type : GLenum {
            UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
            UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
            UNSIGNED_INT = GL_UNSIGNED_INT
        };

        struct elements : draw_call {        
            mode drawMode;
            GLsizei count;
            index_type indexType;
            const GLvoid * indices;        

            elements(
                    const mode mode = mode::POINTS,
                    const GLsizei count = 0,
                    const index_type type = index_type::UNSIGNED_INT,
                    const GLvoid * indices = nullptr) :
            drawMode(mode), count(count), indexType(type), indices(indices) {
            }

            virtual void draw() const;
        };

        struct elements_instanced : draw_call {
            mode drawMode;
            GLsizei count;
            index_type indexType;
            const void * indices;
            GLsizei primitiveCount;
            
            elements_instanced (
                    const mode mode = mode::POINTS,
                    const GLsizei count = 0,
                    const index_type type = index_type::UNSIGNED_INT,
                    const void * indices = nullptr,
                    GLsizei primcount = 1) :
            drawMode(mode), count(count), indexType(type), indices(indices), primitiveCount(primcount) {}
            
            virtual void draw() const;
        };
        
        struct arrays_instanced : draw_call {
            mode drawMode;
            GLint first;
            GLsizei count;
            GLsizei primitiveCount;
            
            arrays_instanced (
                    const mode mode = mode::POINTS,
                    const GLint first = 0,
                    const GLsizei count = 0,
                    const GLsizei primcount = 1) :
            drawMode(mode), first(first), count(count), primitiveCount(primcount) {}
            
            virtual void draw() const;
        };
        
        struct elements_base_vertex : draw_call {
            mode drawMode;
            GLsizei count;
            index_type indexType;
            const GLvoid * indices;
            GLint baseVertex;
            
            elements_base_vertex (
                    const mode mode = mode::POINTS,
                    const GLsizei count = 0,
                    const index_type type = index_type::UNSIGNED_INT,
                    const GLvoid * indices = nullptr,
                    const GLint basevertex = 0) :
            drawMode(mode), count(count), indexType(type), indices(indices), baseVertex(basevertex) {}
            
            virtual void draw() const;
        };
        
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
            drawMode(mode), start(start), end(end), indexType(type), indices(indices) {}
            
            virtual void draw() const;
        };                
    }
}

#endif /* DRAW_CALLS_HPP */

