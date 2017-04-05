/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vertex_attributes.hpp"
#include "vertex_array.hpp"
#include "exception.hpp"

#include <iostream>
#include <string>
#include <map>

#include <GL/glew.h>

#include "buffer.hpp"
#include "vertex_attribute_binding.hpp"
#include "vertex_attribute_type.hpp"

namespace gloop {

    void vertex_attributes::setLocation(std::string name, GLint index) {
        this->_nameMap[name] = index;
    }

    GLint vertex_attributes::getLocation(const std::string& name) const {
        const auto it = this->_nameMap.find(name);

        if (it == this->_nameMap.end()) {
            return -1;
        } else {
            return it->second;
        }
    }

    bool vertex_attributes::hasAttribute(const std::string& name) const {
        return (this->_nameMap.find(name) != this->_nameMap.end());
    }

    void vertex_attributes::bindAttributes(GLuint program) const {
        for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
            glBindAttribLocation(program, it->second, it->first.c_str());
        }
    }

    void vertex_attributes::enableAttributes() const {
        for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
            glEnableVertexAttribArray(it->second);
        }
    }

    void vertex_attributes::disableAttributes() const {
        for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
            glDisableVertexAttribArray(it->second);
        }
    }

    vertex_attribute_binding vertex_attribute::bindBuffer(
            const buffer& buffer,
            const vertex_attribute_type type,
            const GLsizei stride, const void* ptr,
            const GLuint divisor) const {

        return vertex_attribute_binding(this->_id, buffer, type, stride, ptr, divisor);
    }

    const vertex_attribute vertex_attributes::operator[](const std::string& name) const {
        return gloop::vertex_attribute(this->getLocation(name));
    }

    void vertex_attribute::disable() const {
        glDisableVertexAttribArray(this->_id);
    }

    void vertex_attribute::enable() const {
        glEnableVertexAttribArray(this->_id);
    }

    GLint vertex_attribute::getId() const {
        return this->_id;
    }

    vertex_attribute::operator GLint() const {
        return this->_id;
    }
}