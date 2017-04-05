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

#include <memory>
#include <vector>

#include <GL/glew.h>

#include "buffer.hpp"
#include "vertex_attribute_binding.hpp"
#include "vertex_attributes.hpp"

namespace gloop {
    class vertex_array {
    private:
        std::shared_ptr<GLuint> _id;
        std::vector<vertex_attribute_binding> _bindings;
        buffer _indexBuffer;
        
        void init();
        
    public:
        vertex_array& operator<<(const vertex_attribute_binding& binding);        
        
        operator GLuint();
        
        operator bool() const;
        
        GLuint getId();
        
        void addBinding(const vertex_attribute_binding& binding);
        
        void setIndexBuffer(const buffer& buffer);
        
        const buffer& getIndexBuffer() const;
        
        const std::vector<vertex_attribute_binding> getBindings() const;
        
        void free();
        
        void bind();
        
        bool isInitialized() const;
    };
}