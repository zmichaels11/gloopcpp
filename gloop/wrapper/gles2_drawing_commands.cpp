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

extern PFNGLDRAWARRAYSINSTANCEDANGLEPROC glDrawArraysInstancedANGLE;
extern PFNGLDRAWELEMENTSINSTANCEDANGLEPROC glDrawElementsInstancedANGLE;
extern PFNGLVERTEXATTRIBDIVISORANGLEPROC glVertexAttribDivisorANGLE;

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

            glDrawArraysInstancedANGLE(mode, first, count, instanceCount);
        }

        void drawElementsInstanced(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices,
                gloop::sizei_t instanceCount) {

            glDrawElementsInstancedANGLE(mode, count, type, indices, instanceCount);
        }
    }
}
#endif
#undef GLES2