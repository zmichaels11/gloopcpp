/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "draw_calls.hpp"

#include "wrapper/drawing_commands.hpp"

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

    void draw::arrays_indirect::draw() const {
        wrapper::drawArraysIndirect(
                static_cast<gloop::enum_t> (drawMode),
                indirect);
    }

    void draw::elements_indirect::draw() const {
        wrapper::drawElementsIndirect(
                static_cast<gloop::enum_t> (drawMode),
                static_cast<gloop::enum_t> (type),
                indirect);
    }

    void draw::compute::execute() const {

        wrapper::dispatchCompute(numGroupsX, numGroupsY, numGroupsZ);
    }

    void draw::compute_indirect::execute() const {
        wrapper::dispatchComputeIndirect(indirect);
    }
}