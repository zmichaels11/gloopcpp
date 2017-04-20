/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLES2 2
#if GL == GLES2
#include "drawing_commands.hpp"

#include <SDL2/SDL_opengles2.h>

#include "../glint.hpp"
#include "../tools.hpp"
#include "gl_gles2.hpp"

namespace gloop {
    namespace wrapper {
        void drawArrays(
                gloop::enum_t mode,
                gloop::int_t first,
                gloop::sizei_t count) {

            glDrawArrays(mode, first, count);
            tools::__debugAssertGLError("Unable to draw arrays!");
        }

        void drawElements(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices) {

            glDrawElements(mode, count, type, indices);
            tools::__debugAssertGLError("Unable to draw elements!");
        }

        void drawArraysInstanced(
                gloop::enum_t mode,
                gloop::int_t first,
                gloop::sizei_t count,
                gloop::sizei_t instanceCount) {

            glDrawArraysInstancedANGLE(mode, first, count, instanceCount);
            tools::__debugAssertGLError("Unable to draw arrays instanced!");
        }

        void drawElementsInstanced(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices,
                gloop::sizei_t instanceCount) {

            glDrawElementsInstancedANGLE(mode, count, type, indices, instanceCount);
            tools::__debugAssertGLError("Unable to draw elements instanced!");
        }
    }
}
#endif
#undef GLES2