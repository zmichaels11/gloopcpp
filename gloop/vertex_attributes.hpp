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

#include "vertex_attribute_binding.hpp"

namespace gloop {
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

