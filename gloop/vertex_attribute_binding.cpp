/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vertex_attribute_binding.hpp"

#include "buffer.hpp"

#include "enums/buffer_target.hpp"
#include "exception/invalid_enum_exception.hpp"
#include "glint.hpp"
#include "gloop_throw.hpp"
#include "wrapper/gl.hpp"
#include "wrapper/vertex_arrays.hpp"

namespace gloop {
    namespace {

        struct SizedType {
            gloop::int_t size;
            gloop::enum_t type;
        };

        static SizedType vertexAttributeTypeSize(const gloop::enums::vertex_attribute_type type) {
            switch (type) {
                case gloop::enums::vertex_attribute_type::FLOAT:
                    return { 1, gloop::wrapper::FLOAT};
                case gloop::enums::vertex_attribute_type::INT:
                    return { 1, gloop::wrapper::INT};
                case gloop::enums::vertex_attribute_type::UINT:
                    return { 1, gloop::wrapper::UNSIGNED_INT};
                case gloop::enums::vertex_attribute_type::IVEC2:
                    return { 2, gloop::wrapper::INT};
                case gloop::enums::vertex_attribute_type::IVEC3:
                    return { 3, gloop::wrapper::INT};
                case gloop::enums::vertex_attribute_type::IVEC4:
                    return { 4, gloop::wrapper::INT};
                case gloop::enums::vertex_attribute_type::UVEC2:
                    return { 2, gloop::wrapper::UNSIGNED_INT};
                case gloop::enums::vertex_attribute_type::UVEC3:
                    return { 3, gloop::wrapper::UNSIGNED_INT};
                case gloop::enums::vertex_attribute_type::UVEC4:
                    return { 4, gloop::wrapper::UNSIGNED_INT};
                case gloop::enums::vertex_attribute_type::VEC2:
                    return { 2, gloop::wrapper::FLOAT};
                case gloop::enums::vertex_attribute_type::VEC3:
                    return { 3, gloop::wrapper::FLOAT};
                case gloop::enums::vertex_attribute_type::VEC4:
                    return { 4, gloop::wrapper::FLOAT};
                default:
                    gloop_throw(gloop::exception::invalid_enum_exception("Unsupported vertex attribute type!"));
            }
        }
    }
    
    gloop::uint_t vertex_attribute_binding::getAttributeId() const {
        return _id;
    }
    
    const buffer * vertex_attribute_binding::getBuffer() const {
        return _buffer;
    }
    
    enums::vertex_attribute_type vertex_attribute_binding::getType() const {
        return _type;
    }
    
    gloop::sizei_t vertex_attribute_binding::getStride() const {
        return _stride;
    }
    
    const void * vertex_attribute_binding::getPointer() const {
        return _ptr;
    }
    
    gloop::uint_t vertex_attribute_binding::getDivisor() const {
        return _divisor;
    }
    
    void vertex_attribute_binding::apply() const {
        const auto sizedType = vertexAttributeTypeSize(_type);
        
        _buffer->bind(gloop::enums::buffer_target::ARRAY);
        
        if (_divisor) {
            gloop::wrapper::vertexAttribDivisor(_id, _divisor);
        }
        
        if (sizedType.type == gloop::wrapper::FLOAT) {
            gloop::wrapper::vertexAttribPointer(_id, sizedType.size, sizedType.type, gloop::wrapper::FALSE, _stride, _ptr);
        } else {
            gloop::wrapper::vertexAttribIPointer(_id, sizedType.size, sizedType.type, _stride, _ptr);
        }
    }
}