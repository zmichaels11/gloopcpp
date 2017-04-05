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

void gloop::vertex_attributes::setLocation(std::string name, GLint index) {
    this->_nameMap[name] = index;
}

GLint gloop::vertex_attributes::getLocation(const std::string& name) const {
    const auto it = this->_nameMap.find(name);

    if (it == this->_nameMap.end()) {
        return -1;
    } else {
        return it->second;
    }
}

bool gloop::vertex_attributes::hasAttribute(const std::string& name) const {
    return (this->_nameMap.find(name) != this->_nameMap.end());
}

void gloop::vertex_attributes::bindAttributes(GLuint program) const {
    for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
        glBindAttribLocation(program, it->second, it->first.c_str());
    }
}

void gloop::vertex_attributes::enableAttributes() const {
    for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
        glEnableVertexAttribArray(it->second);
    }
}

void gloop::vertex_attributes::disableAttributes() const {
    for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
        glDisableVertexAttribArray(it->second);
    }
}

gloop::vertex_attribute_binding gloop::vertex_attribute::bindBuffer(
        const gloop::buffer& buffer, 
        const gloop::vertex_attribute_type type, 
        const GLsizei stride, const void* ptr, 
        const GLuint divisor) const {
    
    return gloop::vertex_attribute_binding(this->_id, buffer, type, stride, ptr, divisor);
}

const gloop::vertex_attribute gloop::vertex_attributes::operator[](const std::string& name) const {
    return gloop::vertex_attribute(this->getLocation(name));
}

void gloop::vertex_attribute::disable() const {
    glDisableVertexAttribArray(this->_id);
}

void gloop::vertex_attribute::enable() const {
    glEnableVertexAttribArray(this->_id);
}

GLint gloop::vertex_attribute::getId() const {
    return this->_id;
}

gloop::vertex_attribute::operator GLint() const {
    return this->_id;
}