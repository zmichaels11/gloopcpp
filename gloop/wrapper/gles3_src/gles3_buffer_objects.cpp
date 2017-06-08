/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLES3 3
#if GL == GLES3
#include "gl.hpp"

#include "buffer_objects.hpp"

#include <iostream>

#include <GLES3/gl3.h>

#include "../glint.hpp"

#include "gl.hpp"
#include "gl_gles3.hpp"
#include "glext.hpp"
#include "pfnglproc.hpp"

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
        }

        void namedBufferStorage(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::bitfield_t flags) {


            if (EXT_buffer_storage) {
                glBindBuffer(targetHint, buffer);
                (*EXT_buffer_storage.bufferStorageEXT) (targetHint, size, data, flags);
            } else {
                glBindBuffer(targetHint, buffer);
                if (data == nullptr) {
                    glBufferData(targetHint, size, nullptr, GL_DYNAMIC_DRAW);
                } else {
                    glBufferData(targetHint, size, data, GL_STATIC_DRAW);
                }
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

		void getNamedBufferSubData(
				gloop::enum_t,
				gloop::uint_t,
				gloop::intptr_t,
				gloop::sizeiptr_t,
				void *) {}

        void namedBufferSubData(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size,
                const void * data) {

            glBindBuffer(targetHint, buffer);
            glBufferSubData(targetHint, offset, size, data);
        }

        void * mapNamedBufferRange(
                gloop::enum_t targetHint,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t length,
                gloop::bitfield_t access) {


            glBindBuffer(targetHint, buffer);

            void * out = glMapBufferRange(targetHint, offset, length, access);

            return out;
        }

        void unmapNamedBuffer(
                gloop::enum_t targetHint,
                gloop::uint_t buffer) {

            glBindBuffer(targetHint, buffer);
            glUnmapBuffer(targetHint);
        }

        void bindBufferRange(
                gloop::enum_t target,
                gloop::uint_t index,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size) {

            glBindBufferRange(target, index, buffer, offset, size);
        }

        void bindBufferBase(
                gloop::enum_t target,
                gloop::uint_t index,
                gloop::uint_t buffer) {

            glBindBufferBase(target, index, buffer);
        }
    }
}
#endif
#undef GLES3
