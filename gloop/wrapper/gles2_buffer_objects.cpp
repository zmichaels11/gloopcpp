/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLES2 2
#if GL == GLES2
#include "buffer_objects.hpp"

#include <iostream>

#include <SDL2/SDL_opengles2.h>

#include "../gloop_throw.hpp"
#include "../tools.hpp"
#include "gl.hpp"
#include "gl_gles2.hpp"

namespace gloop {
    namespace wrapper {        
        void bindBuffer(
                gloop::enum_t target,
                gloop::uint_t buffer) {

            glBindBuffer(target, buffer);
            tools::__debugAssertGLError("Unable to bind buffer!");
        }

        void namedBufferData(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::enum_t usage) {

            glBindBuffer(targetHint, buffer);
            glBufferData(targetHint, size, data, usage);
            tools::__debugAssertGLError("Unable to allocate buffer!");
        }

        void namedBufferStorage(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::bitfield_t flags) {

            if (EXT_buffer_storage) {
                glBindBuffer(targetHint, buffer);
                glBufferStorageEXT(targetHint, size, data, flags);
            } else {
                glBindBuffer(targetHint, buffer);
                if (data == nullptr) {
                    glBufferData(targetHint, size, nullptr, GL_DYNAMIC_DRAW);
                } else {
                    glBufferData(targetHint, size, data, GL_STATIC_DRAW);
                }
            }
            
            tools::__debugAssertGLError("Unable to allocate immutable buffer!");
        }

        void createBuffers(
                gloop::sizei_t n,
                gloop::uint_t * buffers) {

            glGenBuffers(n, buffers);
        }

        void deleteBuffers(
                gloop::sizei_t n,
                const gloop::uint_t * buffers) {

            glDeleteBuffers(n, buffers);
        }

        void namedBufferSubData(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size,
                const void * data) {

            glBindBuffer(targetHint, buffer);
            glBufferSubData(targetHint, offset, size, data);
            tools::__debugAssertGLError("Unable to update buffer!");
        }

        void * mapNamedBufferRange(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t length,
                gloop::bitfield_t access) {

            if (EXT_map_buffer_range) {
                glBindBuffer(targetHint, buffer);

                void * out = glMapBufferRangeEXT(targetHint, offset, length, access);
                
                tools::__debugAssertGLError("Unable to map buffer range!");

                return out;
            } else if (OES_mapbuffer) {
                glBindBuffer(targetHint, buffer);

                gloop::char_t * ptr = (gloop::char_t *) glMapBufferOES(targetHint, access);
                
                tools::__debugAssertGLError("Unable to map buffer!");

                return (ptr + offset);
            } else {
                gloop_throw("EXT_map_buffer_range and OES_mapbuffer is not supported!");
            }
        }

        void unmapNamedBuffer(
                gloop::enum_t targetHint,
                gloop::uint_t buffer) {

            if (OES_mapbuffer) {
                glBindBuffer(targetHint, buffer);
                glUnmapBufferOES(targetHint);
                tools::__debugAssertGLError("Unable to unmap buffer!");
            } else {
                gloop_throw("OES_mapbuffer is not supported!");
            }
        }
    }
}
#endif
#undef GLES2