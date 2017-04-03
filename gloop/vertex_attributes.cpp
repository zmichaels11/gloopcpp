/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vertex_attributes.hpp"
#include "vertex_array.hpp"
#include "exception.hpp"

#include <iostream>
#include <string>
#include <map>

#include <GL/glew.h>

#include "buffer.hpp"

void gloop::vertex_attributes::setLocation(std::string name, GLint index) {
    this->_nameMap[name] = index;
}

GLint gloop::vertex_attributes::getLocation(const std::string& name) const {
    const auto it = this->_nameMap.find(name);

    if (it == this->_nameMap.end()) {
        return -1;
    } else {
        return it->second;
    }
}

bool gloop::vertex_attributes::hasAttribute(const std::string& name) const {
    return (this->_nameMap.find(name) != this->_nameMap.end());
}

void gloop::vertex_attributes::bindAttributes(GLuint program) const {
    for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
        glBindAttribLocation(program, it->second, it->first.c_str());
    }
}

void gloop::vertex_attributes::enableAttributes() const {
    for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
        glEnableVertexAttribArray(it->second);
    }
}

void gloop::vertex_attributes::disableAttributes() const {
    for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
        glDisableVertexAttribArray(it->second);
    }
}

namespace {

    struct SizedType {
        GLint size;
        GLenum type;
    };

    static SizedType vertexAttributeTypeSize(const gloop::vertex_attribute_type type) {
        switch (type) {
            case gloop::vertex_attribute_type::FLOAT:
                return { 1, GL_FLOAT};
            case gloop::vertex_attribute_type::INT:
                return { 1, GL_INT};
            case gloop::vertex_attribute_type::UINT:
                return { 1, GL_UNSIGNED_INT};
            case gloop::vertex_attribute_type::IVEC2:
                return { 2, GL_INT};
            case gloop::vertex_attribute_type::IVEC3:
                return { 3, GL_INT};
            case gloop::vertex_attribute_type::IVEC4:
                return { 4, GL_INT};
            case gloop::vertex_attribute_type::UVEC2:
                return { 2, GL_UNSIGNED_INT};
            case gloop::vertex_attribute_type::UVEC3:
                return { 3, GL_UNSIGNED_INT};
            case gloop::vertex_attribute_type::UVEC4:
                return { 4, GL_UNSIGNED_INT};
            case gloop::vertex_attribute_type::VEC2:
                return { 2, GL_FLOAT};
            case gloop::vertex_attribute_type::VEC3:
                return { 3, GL_FLOAT};
            case gloop::vertex_attribute_type::VEC4:
                return { 4, GL_FLOAT};
            default:
                throw gloop::invalid_enum_exception("Unsupported vertex attribute type!");
        }
    }
}

gloop::vertex_attribute_binding gloop::vertex_attribute::bindBuffer(
        const gloop::buffer& buffer, 
        const gloop::vertex_attribute_type type, 
        const GLsizei stride, const void* ptr, 
        const GLuint divisor) const {
    
    return gloop::vertex_attribute_binding(this->_id, buffer, type, stride, ptr, divisor);
}

const gloop::vertex_attribute gloop::vertex_attributes::operator[](const std::string& name) const {
    return gloop::vertex_attribute(this->getLocation(name));
}

void gloop::vertex_attribute::disable() const {
    glDisableVertexAttribArray(this->_id);
}

void gloop::vertex_attribute::enable() const {
    glEnableVertexAttribArray(this->_id);
}

GLint gloop::vertex_attribute::getId() const {
    return this->_id;
}

gloop::vertex_attribute::operator GLint() const {
    return this->_id;
}

GLuint gloop::vertex_attribute_binding::getAttributeId() const {
    return this->_id;
}

const gloop::buffer& gloop::vertex_attribute_binding::getBuffer() const {
    return this->_buffer;
}

gloop::vertex_attribute_type gloop::vertex_attribute_binding::getType() const {
    return this->_type;
}

GLsizei gloop::vertex_attribute_binding::getStride() const {
    return this->_stride;
}

const void * gloop::vertex_attribute_binding::getPointer() const {
    return this->_ptr;
}

GLuint gloop::vertex_attribute_binding::getDivisor() const {
    return this->_divisor;
}

void gloop::vertex_attribute_binding::operator()() const {
    const auto sizedType = vertexAttributeTypeSize(this->_type);
    
    this->_buffer.bind(gloop::buffer_target::ARRAY);

    if (this->_divisor > 0) {
        glVertexAttribDivisor(this->_id, this->_divisor);
    }

    if (sizedType.type == GL_FLOAT) {
        glVertexAttribPointer(this->_id, sizedType.size, sizedType.type, GL_FALSE, this->_stride, this->_ptr);
    } else {
        glVertexAttribIPointer(this->_id, sizedType.size, sizedType.type, this->_stride, this->_ptr);
    }
}