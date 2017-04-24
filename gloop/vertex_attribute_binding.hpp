/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <iostream>

#include "glint.hpp"

namespace gloop {
    namespace enums {
        enum class vertex_attribute_type : gloop::enum_t;
    }
    
    class buffer;

    class vertex_attribute_binding {
    private:
        gloop::uint_t _id;
        const buffer * _buffer;
        enums::vertex_attribute_type _type;
        gloop::sizei_t _stride;
        const void * _ptr;
        gloop::uint_t _divisor;

    public:

        vertex_attribute_binding() :
        vertex_attribute_binding(0, nullptr, static_cast<enums::vertex_attribute_type> (0)) {
        }

        vertex_attribute_binding(
                const gloop::uint_t id, const buffer * buffer,
                const enums::vertex_attribute_type type,
                const gloop::sizei_t stride = 0, const void * ptr = nullptr,
                const gloop::uint_t divisor = 0) :

        _id(id), _buffer(buffer),
        _type(type),
        _stride(stride), _ptr(ptr),
        _divisor(divisor) {
        }

        friend std::ostream& operator<<(std::ostream& os, const vertex_attribute_binding& vab);

        gloop::uint_t getAttributeId() const;

        const buffer * getBuffer() const;

        enums::vertex_attribute_type getType() const;

        gloop::sizei_t getStride() const;

        const void * getPointer() const;

        gloop::uint_t getDivisor() const;

        void apply() const;

        inline void operator()() const {
            apply();
        }
    };
}