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

extern PFNGLMAPBUFFERRANGEEXTPROC glMapBufferRangeEXT;
extern PFNGLMAPBUFFEROESPROC glMapBufferOES;
extern PFNGLUNMAPBUFFEROESPROC glUnmapBufferOES;
extern PFNGLBUFFERSTORAGEEXTPROC glBufferStorageEXT;

namespace gloop {
    namespace wrapper {

        void bindBuffer(
                gloop::enum_t target,
                gloop::uint_t buffer) {

            glBindBuffer(target, buffer);
        }

        void namedBufferData(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::enum_t usage) {

            glBindBuffer(targetHint, buffer);
            glBufferData(targetHint, size, data, usage);
            glBindBuffer(targetHint, 0);
        }

        void namedBufferStorage(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::bitfield_t flags) {

            if (glBufferStorageEXT != nullptr) {
                glBindBuffer(targetHint, buffer);
                glBufferStorageEXT(targetHint, size, data, flags);
                glBindBuffer(targetHint, 0);
            }
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
            glBindBuffer(targetHint, 0);
        }

        void * mapNamedBufferRange(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t length,
                gloop::bitfield_t access) {

            if (glMapBufferRangeEXT != nullptr) {
                glBindBuffer(targetHint, buffer);

                void * out = glMapBufferRangeEXT(targetHint, offset, length, access);

                glBindBuffer(targetHint, 0);

                return out;
            } else if (glUnmapBufferOES != nullptr) {
                glBindBuffer(targetHint, buffer);

                gloop::char_t * ptr = (gloop::char_t *) glMapBufferOES(targetHint, access);

                glBindBuffer(targetHint, 0);

                return (ptr + offset);
            } else {
                throw "glMapBufferOES is not supported!";
            }
        }

        void unmapNamedBuffer(
                gloop::enum_t targetHint,
                gloop::uint_t buffer) {

            if (glUnmapBufferOES != nullptr) {
                glBindBuffer(targetHint, buffer);
                glUnmapBufferOES(targetHint);
                glBindBuffer(targetHint, 0);
            } else {
                throw "glUnmapBufferOES is not supported!";
            }
        }

        void getNamedBufferSubData(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::intptr_t offset,
                gloop::sizeiptr_t size,
                void * data) {

            throw "glGetBufferSubData is not supported!";
        }

        void bindBufferRange(                
                gloop::enum_t target,
                gloop::uint_t index,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size) {

            throw "glBindBufferRange is not supported!";
        }

        void bindBufferBase(                
                gloop::enum_t target,
                gloop::uint_t buffer) {

            throw "glBindBufferBase is not supported!";
        }
    }
}
#endif