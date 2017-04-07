/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <GL/glew.h>

#include "buffer.hpp"
#include "vertex_attribute_type.hpp"

namespace gloop {
    class vertex_attribute_binding {
    private:
        const GLuint _id;
        const buffer * _buffer;
        const vertex_attribute_type _type;
        const GLsizei _stride;
        const void * _ptr;
        const GLuint _divisor;

    public:

        vertex_attribute_binding(
                const GLuint id, const buffer * buffer,
                const vertex_attribute_type type,
                const GLsizei stride = 0, const void * ptr = nullptr,
                const GLuint divisor = 0) :

        _id(id), _buffer(buffer),
        _type(type),
        _stride(stride), _ptr(ptr),
        _divisor(divisor) {
        }
        
        GLuint getAttributeId() const;
        
        const buffer * getBuffer() const;
        
        vertex_attribute_type getType() const;
        
        GLsizei getStride() const;
        
        const void * getPointer() const;
        
        GLuint getDivisor() const;
        
        void apply() const;
        
        inline void operator()() const {
            apply();
        }
    };
}