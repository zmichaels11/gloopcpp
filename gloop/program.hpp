/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   program.hpp
 * Author: zmichaels
 *
 * Created on April 3, 2017, 10:53 AM
 */

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <string>
#include <memory>

#include <GL/glew.h>

#include "shader.hpp"
#include "exception.hpp"
#include "vertex_attributes.hpp"

namespace gloop {
    class program_link_exception : public exception {
    public:
        program_link_exception(std::string msg) : exception(msg) {}
    };        
    
    class program {
    private:
        std::shared_ptr<GLuint> _id;
        vertex_attributes _attribs;
        
    public:
        program() : _id(nullptr) {}
        
        void setVertexAttributes(const vertex_attributes attribs);
        
        void linkShaders(shader * const shaders, const std::size_t count);
        
        GLuint getId() const;
        
        bool isInitialized() const;
        
        void use() const;
        
        void free();
        
        operator bool() const;
        
        operator GLuint() const;
    };
}

#endif /* PROGRAM_HPP */

