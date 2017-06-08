#include "drawing_commands.hpp"

#include <GLES3/gl3.h>

#include "../exception/invalid_operation_exception.hpp"
#include "../glint.hpp"
#include "../gloop_throw.hpp"
#include "gl_gles3.hpp"

namespace gloop {
    namespace wrapper {

        void drawArrays(
                gloop::enum_t mode,
                gloop::int_t first,
                gloop::sizei_t count) {

            glDrawArrays(mode, first, count);
        }

        void drawElements(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices) {

            glDrawElements(mode, count, type, indices);
        }

        void drawArraysInstanced(
                gloop::enum_t mode,
                gloop::int_t first,
                gloop::sizei_t count,
                gloop::sizei_t instanceCount) {

            glDrawArraysInstanced(mode, first, count, instanceCount);
        }

        void drawElementsInstanced(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices,
                gloop::sizei_t instanceCount) {

            glDrawElementsInstanced(mode, count, type, indices, instanceCount);
        }

        void drawArraysIndirect(
                gloop::enum_t mode,
                const void * indices) {

            if (GLES31) {
                (*GLES31.drawArraysIndirect)(mode, indices);
            } else {
                gloop_throw(gloop::exception::invalid_operation_exception("drawArraysIndirect is not available!"));
            }
        }

        void drawElementsIndirect(
                gloop::enum_t mode,
                gloop::enum_t type,
                const void * indices) {

            if (GLES31) {
                (*GLES31.drawElementsIndirect)(mode, type, indices);
            } else {
                gloop_throw(gloop::exception::invalid_operation_exception("drawElementsIndirect is not available!"));
            }
        }

        void dispatchCompute(
                gloop::uint_t numGroupsX,
                gloop::uint_t numGroupsY,
                gloop::uint_t numGroupsZ) {

            if (GLES32) {
                (*GLES32.dispatchCompute)(numGroupsX, numGroupsY, numGroupsZ);
            } else {
                gloop_throw(gloop::exception::invalid_operation_exception("dispatchCompute is not available!"));
            }
        }
        
        void dispatchComputeIndirect(gloop::intptr_t indirect) {
            if (GLES32) {
                (*GLES32.dispatchComputeIndirect) (indirect);
            } else {
                gloop_throw(gloop::exception::invalid_operation_exception("dispatchComputeIndirect is not available!"));
            }
        }
    }
}
