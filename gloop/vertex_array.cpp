/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vertex_array.hpp"

#include <algorithm>
#include <iostream>
#include <memory>

#include "buffer.hpp"
#include "enums/buffer_target.hpp"
#include "exception/invalid_operation_exception.hpp"
#include "gloop_throw.hpp"
#include "tools.hpp"
#include "vertex_attribute_binding.hpp"
#include "wrapper/vertex_arrays.hpp"
#include "wrapper/states.hpp"

namespace gloop {

    vertex_array::~vertex_array() {
        free();
    }

    void vertex_array::init() {
        // dont bother initializing if there are no bindings and no element buffer
        if (this->_numBindings == 0 && !this->_indexBuffer) {               
            return;
        }

        gloop::uint_t glId = 0;

        gloop::wrapper::createVertexArrays(1, &glId);
        gloop::wrapper::bindVertexArray(glId);


        if (this->_indexBuffer) {
            this->_indexBuffer->bind(gloop::enums::buffer_target::ELEMENT_ARRAY);
        }

        for (int i = 0; i < _numBindings; i++) {            
            wrapper::enableVertexAttribArray(_bindings[i]->getAttributeId());
            _bindings[i]->apply();
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
        this->_bindings[this->_numBindings] = std::make_unique<vertex_attribute_binding> (binding);
        this->_numBindings++;
    }

    const std::array<std::unique_ptr<vertex_attribute_binding>, vertex_array::MAX_VERTEX_ATTRIBUTES>& vertex_array::getBindings() const {
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

    std::ostream& operator<<(std::ostream& os, const vertex_array& va) {
        os << "vertex_array: [";

        if (va) {
            os << "id: " << va._id;

            if (va._indexBuffer) {
                os << ", index buffer id: " << va._indexBuffer->getId();
            }

            os << ", bindings: [";
            
            for (int i = 0; i < va._numBindings; i++) {
                os << *(va._bindings[i]);
                
                if (i < va._numBindings - 1) {
                    os << ", ";
                }
            }

            os << "]";
        } else {
            os << "UNINITIALIZED]";
        }

        return os;
    }
}