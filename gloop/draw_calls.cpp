/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "draw_calls.hpp"

#include "glwrapper.hpp"

namespace gloop {

    void draw::elements::draw() const {
        wrapper::drawElements(
                static_cast<gloop::enum_t> (drawMode),
                count,
                static_cast<gloop::enum_t> (indexType),
                indices);
    }

    void draw::arrays::draw() const {
        wrapper::drawArrays(
                static_cast<gloop::enum_t> (drawMode),
                first,
                count);
    }

    void draw::elements_instanced::draw() const {
        wrapper::drawElementsInstanced(
                static_cast<gloop::enum_t> (drawMode),
                count,
                static_cast<gloop::enum_t> (indexType),
                indices,
                primitiveCount);
    }

    void draw::arrays_instanced::draw() const {
        wrapper::drawArraysInstanced(
                static_cast<gloop::enum_t> (drawMode),
                first,
                count,
                primitiveCount);
    }

    void draw::elements_base_vertex::draw() const {
        throw "unsupported operation";
    }

    void draw::range_elements::draw() const {
        throw "unsupported operation";
    }
}