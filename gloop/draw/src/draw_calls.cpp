/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "arrays.hpp"
#include "arrays_indirect.hpp"
#include "arrays_instanced.hpp"
#include "compute.hpp"
#include "compute_indirect.hpp"
#include "elements.hpp"
#include "elements_base_vertex.hpp"
#include "elements_indirect.hpp"
#include "elements_instanced.hpp"
#include "range_elements.hpp"

#include <type_traits>

#include "../exception/invalid_operation_exception.hpp"
#include "../gloop_throw.hpp"
#include "../wrapper/drawing_commands.hpp"

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

    namespace {
#define GLEW 1
#define GLES2 2
#define GLES3 3
#ifndef GL
#define __GL_NOT_DEFINED
#define GL 0
#endif        

        static constexpr bool supports_draw_indirect = (GL == GLEW || GL == GLES3);
        static constexpr bool supports_compute_shaders = (GL == GLEW || GL == GLES3);

#ifdef __GL_NOT_DEFINED
#undef GL
#undef __GL_NOT_DEFINED
#endif

#undef GLES3
#undef GLES2
#undef GLES1

        template<bool isSupported = supports_draw_indirect, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __drawArraysIndirect(
                gloop::enum_t mode,
                const void * indirect) {

            wrapper::drawArraysIndirect(mode, indirect);
        }

        template<bool isSupported = supports_draw_indirect, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __drawArraysIndirect(...) {

            gloop_throw(gloop::exception::invalid_operation_exception("Draw Indirect is not supported!"));
        }

        template<bool isSupported = supports_draw_indirect, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __drawElementsIndirect(
                gloop::enum_t mode,
                gloop::enum_t type,
                const void * indirect) {

            wrapper::drawElementsIndirect(
                    static_cast<gloop::enum_t> (mode),
                    static_cast<gloop::enum_t> (type),
                    indirect);
        }

        template<bool isSupported = supports_draw_indirect, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __drawElementsIndirect(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("drawElementsIndirect is not supported!"));
        }

        template<bool isSupported = supports_compute_shaders, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __dispatchCompute(
                gloop::uint_t numGroupsX,
                gloop::uint_t numGroupsY,
                gloop::uint_t numGroupsZ) {

            wrapper::dispatchCompute(numGroupsX, numGroupsY, numGroupsZ);
        }

        template<bool isSupported = supports_compute_shaders, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __dispatchCompute(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("Compute Shaders are not supported!"));
        }

        template<bool isSupported = supports_compute_shaders, typename std::enable_if<isSupported, void * >::type = nullptr>
        static inline void __dispatchComputeIndirect(gloop::intptr_t indirect) {
            wrapper::dispatchComputeIndirect(indirect);
        }

        template<bool isSupported = supports_compute_shaders, typename std::enable_if<!isSupported, void * >::type = nullptr>
        static inline void __dispatchComputeIndirect(...) {
            gloop_throw(gloop::exception::invalid_operation_exception("Compute Shaders are not supported!"));
        }
    }

    void draw::arrays_indirect::draw() const {
        __drawArraysIndirect<supports_draw_indirect>(static_cast<gloop::enum_t> (drawMode), indirect);
    }

    void draw::elements_indirect::draw() const {
        __drawElementsIndirect(
                static_cast<gloop::enum_t> (drawMode),
                static_cast<gloop::enum_t> (type),
                indirect);
    }

    void draw::compute::execute() const {
        __dispatchCompute(numGroupsX, numGroupsY, numGroupsZ);
    }

    void draw::compute_indirect::execute() const {
        __dispatchComputeIndirect(indirect);
    }
}
