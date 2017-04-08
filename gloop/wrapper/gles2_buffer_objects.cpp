/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLES2 1
#if GL == GLES2
#include "buffer_objects.hpp"

#include <SDL2/SDL_opengles2.h>
#include <SDL2/SDL_opengles2_gl2ext.h>

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
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::enum_t usage) {

            glBindBuffer(GL_ARRAY_BUFFER, buffer);
            glBufferData(GL_ARRAY_BUFFER, size, data, usage);
        }

        void namedBufferStorage(
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::bitfield_t flags) {

            if (glBufferStorageEXT != nullptr) {
                glBindBuffer(GL_ARRAY_BUFFER, buffer);
                glBufferStorageEXT(GL_ARRAY_BUFFER, size, data, flags);
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
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size,
                const void * data) {

            glBindBuffer(GL_ARRAY_BUFFER, buffer);
            glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
        }

        void * mapNamedBufferRange(
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t length,
                gloop::bitfield_t access) {
            
            if (glMapBufferRangeEXT != nullptr) {
                glBindBuffer(GL_ARRAY_BUFFER, buffer);
                
                return glMapBufferRangeEXT(GL_ARRAY_BUFFER, offset, length, access);
            } else if (glUnmapBufferOES != nullptr) {
                glBindBuffer(GL_ARRAY_BUFFER, buffer);
                
                gloop::char_t * ptr = (gloop::char_t *) glMapBufferOES(buffer, access);
                
                return (ptr + offset);
            } else {
                throw "glMapBufferOES is not supported!";
            }
        }

        void unmapNamedBuffer(gloop::uint_t buffer) {
            if (glUnmapBufferOES != nullptr) {
                glBindBuffer(GL_ARRAY_BUFFER, buffer);
                glUnmapBufferOES(GL_ARRAY_BUFFER);
            } else {
                throw "glUnmapBufferOES is not supported!";
            }
        }
        
        void getNamedBufferSubData(
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