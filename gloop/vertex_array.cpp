/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vertex_array.hpp"

#include <memory>
#include <vector>

#include "enums/buffer_target.hpp"
#include "tools.hpp"
#include "wrapper/vertex_arrays.hpp"

namespace gloop {

    vertex_array::~vertex_array() {
        free();
    }

    void vertex_array::init() {
        // dont bother initializing if there are no bindings and no element buffer
        if (this->_bindings.size() == 0 && !this->_indexBuffer) {
            return;
        }

        gloop::uint_t glId = 0;

        gloop::wrapper::createVertexArrays(1, &glId);
        gloop::wrapper::bindVertexArray(glId);

        if (this->_indexBuffer) {
            this->_indexBuffer->bind(gloop::enums::buffer_target::ELEMENT_ARRAY);
        }

        for (auto it = this->_bindings.begin(); it != this->_bindings.end(); it++) {
            vertex_attribute_binding binding = *it;

            gloop::wrapper::enableVertexAttribArray(binding.getAttributeId());
            binding();
        }

        gloop::wrapper::bindVertexArray(0);

        this->_id = glId;
    }

    vertex_array::operator bool() const {
        return this->isInitialized();
    }

    gloop::uint_t vertex_array::getId() {
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

    void vertex_array::addBinding(const vertex_attribute_binding& binding) {
        this->_bindings.push_back(binding);
    }

    vertex_array& vertex_array::operator<<(const vertex_attribute_binding& binding) {
        this->addBinding(binding);
        return *this;
    }

    const std::vector<vertex_attribute_binding> vertex_array::getBindings() const {
        return this->_bindings;
    }

    void vertex_array::free() {
        if (this->isInitialized()) {
            gloop::wrapper::deleteVertexArrays(1, &_id);
            this->_id = 0;
        }
    }

    void vertex_array::bind() {
        // this will bind vertex array 0 if the vertex array has no attached buffers
        gloop::wrapper::bindVertexArray(getId());
    }

    bool vertex_array::isInitialized() const {
        return _id != 0;
    }

    void vertex_array::setIndexBuffer(const buffer * buffer) {
        this->_indexBuffer = buffer;
    }

    const buffer * vertex_array::getIndexBuffer() const {
        return this->_indexBuffer;

    }
}