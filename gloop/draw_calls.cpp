/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "draw_calls.hpp"

#include "exception/invalid_operation_exception.hpp"
#include "gloop_throw.hpp"
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
#define GLES2 2
#if GL == GLES2
        gloop_throw(gloop::exception::invalid_operation_exception("drawArraysIndirect is not supported!"));
#else
        wrapper::drawArraysIndirect(
                static_cast<gloop::enum_t> (drawMode),
                indirect);
#endif
#undef GLES2
    }

    void draw::elements_indirect::draw() const {
#define GLES2 2
#if GL == GLES2
        gloop_throw(gloop::exception::invalid_operation_exception("drawElementsIndirect is not supported!"));
#else
        wrapper::drawElementsIndirect(
                static_cast<gloop::enum_t> (drawMode),
                static_cast<gloop::enum_t> (type),
                indirect);
#endif
#undef GLES2
    }

    void draw::compute::execute() const {
#define GLES2 2
#if GL == GLES2
        gloop_throw(gloop::exception::invalid_operation_exception("dispatchCompute is not supported!"));
#else
        wrapper::dispatchCompute(numGroupsX, numGroupsY, numGroupsZ);
#endif
#undef GLES2
    }

    void draw::compute_indirect::execute() const {
#define GLES2 2
#if GL == GLES2
        gloop_throw(gloop::exception::invalid_operation_exception("dispatchComputeIndirect is not supported!"));
#else        
        wrapper::dispatchComputeIndirect(indirect);
#endif
#undef GLES2
    }
}