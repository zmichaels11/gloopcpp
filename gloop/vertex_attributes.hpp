/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <string>
#include <map>

#include "buffer.hpp"
#include "glint.hpp"
#include "vertex_attribute_binding.hpp"

namespace gloop {
    class vertex_attribute {
    private:
        const gloop::uint_t _id;

    public:

        vertex_attribute(gloop::uint_t id) : _id(id) {
        };

        gloop::uint_t getId() const;        

        vertex_attribute_binding bindBuffer(
                const buffer * bufId, 
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