#ifndef __EMSCRIPTEN__
#include "drawing_commands.hpp"

#include <GL/glew.h>

#include "../glint.hpp"

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
                const void * indirect) {

            glDrawArraysIndirect(mode, indirect);
        }

        void drawElementsIndirect(
                gloop::enum_t mode,
                gloop::enum_t type,
                const void * indirect) {

            glDrawElementsIndirect(mode, type, indirect);
        }

        void dispatchCompute(
                gloop::uint_t numGroupsX,
                gloop::uint_t numGroupsY,
                gloop::uint_t numGroupsZ) {

            glDispatchCompute(numGroupsX, numGroupsY, numGroupsZ);
        }
        
        void dispatchComputeIndirect(gloop::intptr_t indirect) {
            glDispatchComputeIndirect(indirect);
        }
    }
}
#endif
