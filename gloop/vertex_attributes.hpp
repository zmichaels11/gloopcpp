/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vertex_attributes.hpp
 * Author: zmichaels
 *
 * Created on April 3, 2017, 11:21 AM
 */

#ifndef VERTEX_ATTRIBUTES_HPP
#define VERTEX_ATTRIBUTES_HPP

#include <string>
#include <map>

#include <GL/glew.h>

#include "buffer.hpp"

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

    // for older opengl

    class vertex_attribute_binding {
    private:
        const GLuint _id;
        const buffer _buffer;
        const vertex_attribute_type _type;
        const GLsizei _stride;
        const void * _ptr;
        const GLuint _divisor;

    public:

        vertex_attribute_binding(
                const GLuint id, const buffer& buffer,
                const vertex_attribute_type type,
                const GLsizei stride = 0, const void * ptr = nullptr,
                const GLuint divisor = 0) :

        _id(id), _buffer(buffer),
        _type(type),
        _stride(stride), _ptr(ptr),
        _divisor(divisor) {
        }
        
        GLuint getAttributeId() const;
        
        const buffer& getBuffer() const;
        
        vertex_attribute_type getType() const;
        
        GLsizei getStride() const;
        
        const void * getPointer() const;
        
        GLuint getDivisor() const;
        
        void operator()() const;
    };

    class vertex_attribute {
    private:
        const GLint _id;

    public:

        vertex_attribute(GLint id) : _id(id) {
        };

        GLint getId() const;

        operator GLint() const;

        vertex_attribute_binding bindBuffer(
                const buffer& bufId, 
                const vertex_attribute_type, 
                const GLsizei stride = 0, const void * ptr = nullptr, 
                const GLuint divisor = 0) const;

        void enable() const;

        void disable() const;
    };

    class vertex_attributes {
    private:
        std::map<std::string, GLint> _nameMap;

    public:
        void setLocation(std::string name, GLint index);

        GLint getLocation(const std::string& name) const;

        bool hasAttribute(const std::string& name) const;

        void bindAttributes(GLuint program) const;

        void enableAttributes() const;

        void disableAttributes() const;

        const vertex_attribute operator[](const std::string& name) const;
    };
}

#endif /* VERTEX_ATTRIBUTES_HPP */

