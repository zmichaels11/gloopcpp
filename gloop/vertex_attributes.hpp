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

namespace gloop {
    // for older opengl
    class vertex_attribute {
    private:
        const GLint _id;
        
    public:
        vertex_attribute(GLint id) : _id(id) {};        
        
        GLint getId() const;
        
        operator GLint() const;
        
        void bindBuffer(GLuint bufId, GLint size, GLenum type, GLboolean normalized = GL_FALSE, GLsizei stride = 0, const void * ptr = nullptr) const;
        
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

