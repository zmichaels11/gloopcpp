/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vertex_attribute_binding.hpp"

#include "buffer.hpp"

#include "invalid_enum_exception.hpp"

namespace gloop {
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
    
    GLuint vertex_attribute_binding::getAttributeId() const {
        return _id;
    }
    
    const buffer& vertex_attribute_binding::getBuffer() const {
        return _buffer;
    }
    
    vertex_attribute_type vertex_attribute_binding::getType() const {
        return _type;
    }
    
    GLsizei vertex_attribute_binding::getStride() const {
        return _stride;
    }
    
    const void * vertex_attribute_binding::getPointer() const {
        return _ptr;
    }
    
    GLuint vertex_attribute_binding::getDivisor() const {
        return _divisor;
    }
    
    void vertex_attribute_binding::apply() const {
        const auto sizedType = vertexAttributeTypeSize(_type);
        
        _buffer.bind(gloop::buffer_target::ARRAY);
        
        if (_divisor) {
            glVertexAttribDivisor(_id, _divisor);
        }
        
        if (sizedType.type == GL_FLOAT) {
            glVertexAttribPointer(_id, sizedType.size, sizedType.type, GL_FALSE, _stride, _ptr);
        } else {
            glVertexAttribIPointer(_id, sizedType.size, sizedType.type, _stride, _ptr);
        }
    }
}