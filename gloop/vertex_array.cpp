/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vertex_array.hpp"

#include <memory>
#include <vector>

#include <GL/glew.h>

#include "tools.hpp"

namespace gloop {
    vertex_array::~vertex_array() {
        free();
    }        
}

void gloop::vertex_array::init() {
    // dont bother initializing if there are no bindings and no element buffer
    if (this->_bindings.size() == 0 && !this->_indexBuffer) {
        return;
    }

    GLuint glId = 0;

    glGenVertexArrays(1, &glId);
    glBindVertexArray(glId);    

    if (this->_indexBuffer) {
        this->_indexBuffer->bind(gloop::buffer_target::ELEMENT_ARRAY);
    }

    for (auto it = this->_bindings.begin(); it != this->_bindings.end(); it++) {
        vertex_attribute_binding binding = *it;

        glEnableVertexAttribArray(binding.getAttributeId());
        binding();
    }

    glBindVertexArray(0);

    this->_id = glId;
}

gloop::vertex_array::operator GLuint() {
    return this->getId();
}

gloop::vertex_array::operator bool() const {
    return this->isInitialized();
}

GLuint gloop::vertex_array::getId() {
    // initialize the vertex_array if it needs to be initialized
    if (!this->isInitialized()) {
        this->init();
    }

    // check again if its initialized
    if (this->isInitialized()) {
        return _id;
    } else {
        return 0;
    }
}

void gloop::vertex_array::addBinding(const vertex_attribute_binding& binding) {
    this->_bindings.push_back(binding);
}

gloop::vertex_array& gloop::vertex_array::operator<<(const vertex_attribute_binding& binding) {
    this->addBinding(binding);
    return *this;
}

const std::vector<gloop::vertex_attribute_binding> gloop::vertex_array::getBindings() const {
    return this->_bindings;
}

void gloop::vertex_array::free() {
    if (this->isInitialized()) {
        glDeleteVertexArrays(1, &_id);
        this->_id = 0;
    }
}

void gloop::vertex_array::bind() {
    // this will bind vertex array 0 if the vertex array has no attached buffers
    glBindVertexArray(this->getId());
}

bool gloop::vertex_array::isInitialized() const {
    return _id != 0;
}

void gloop::vertex_array::setIndexBuffer(const buffer * buffer) {
    this->_indexBuffer = buffer;
}

const gloop::buffer * gloop::vertex_array::getIndexBuffer() const {
    return this->_indexBuffer;
}