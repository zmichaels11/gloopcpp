/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vertex_array.hpp
 * Author: zmichaels
 *
 * Created on April 3, 2017, 2:40 PM
 */

#pragma once

#include <array>
#include <iostream>
#include <memory>

#include "glint.hpp"

namespace gloop {

    class buffer;
    class vertex_attribute_binding;
    
    class vertex_array {
    public:
        static constexpr unsigned int MAX_VERTEX_ATTRIBUTES = 16;
    private:
        gloop::uint_t _id;
        std::array<std::unique_ptr<vertex_attribute_binding>, MAX_VERTEX_ATTRIBUTES> _bindings;
        unsigned int _numBindings;
        const buffer * _indexBuffer;

        void init();

    public:

        vertex_array() :
        _id(0),
		_numBindings(0),
        _indexBuffer(nullptr) {}
        
        ~vertex_array();

        vertex_array(const vertex_array&) = delete;

        vertex_array(vertex_array&&) = default;
        
        vertex_array& operator=(const vertex_array&) = delete;
        
        vertex_array& operator=(vertex_array&&) = default;        
        
        friend std::ostream& operator<<(std::ostream& os, const vertex_array& va);

        operator bool() const;

        gloop::uint_t getId();

        void addBinding(const vertex_attribute_binding& binding);

        void setIndexBuffer(const buffer * buffer);

        const buffer * getIndexBuffer() const;

        const std::array<std::unique_ptr<vertex_attribute_binding>, MAX_VERTEX_ATTRIBUTES>& getBindings() const;

        void free();

        void bind();

        bool isInitialized() const;
    };
}
