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

#include <iostream>
#include <vector>

#include "buffer.hpp"
#include "glint.hpp"
#include "vertex_attribute_binding.hpp"
#include "vertex_attributes.hpp"

namespace gloop {

    class vertex_array {
    private:
        gloop::uint_t _id;
        std::vector<vertex_attribute_binding> _bindings;
        const buffer * _indexBuffer;

        void init();

    public:

        vertex_array() :
        _id(0),
        _indexBuffer(nullptr) {
        }
        
        ~vertex_array();

        vertex_array(const vertex_array&) = delete;

        vertex_array(vertex_array&&) = default;
        
        vertex_array& operator=(const vertex_array&) = delete;
        
        vertex_array& operator=(vertex_array&&) = default;

        vertex_array& operator<<(const vertex_attribute_binding& binding);
        
        inline friend std::ostream& operator<<(std::ostream& os, const vertex_array& va) {
            os << "vertex_array: [";
            
            if (va) {
                os << "id: " << va._id;
                
                if (va._indexBuffer) {
                    os << ", index buffer id: " << va._indexBuffer->getId();
                }
                
                os << ", bindings: [";
                
                int i = 0;
                for (auto it = va._bindings.begin(); it != va._bindings.end(); it++) {
                    os << *it;
                    
                    if (i < va._bindings.size() - 1) {
                        os << ", ";
                    }
                }
                
                os << "]";
            } else {
                os << "UNINITIALIZED]";
            }
            
            return os;
        }

        operator bool() const;

        gloop::uint_t getId();

        void addBinding(const vertex_attribute_binding& binding);

        void setIndexBuffer(const buffer * buffer);

        const buffer * getIndexBuffer() const;

        const std::vector<vertex_attribute_binding> getBindings() const;

        void free();

        void bind();

        bool isInitialized() const;
    };
}