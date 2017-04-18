/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLEW 1
#if GL == GLEW
#include "buffer_objects.hpp"

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {

        void bindBuffer(
                gloop::enum_t target,
                gloop::uint_t buffer) {

            glBindBuffer(target, buffer);
        }

        void namedBufferData(
                gloop::enum_t target,
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::enum_t usage) {

            if (GLEW_ARB_direct_state_access) {
                glNamedBufferData(buffer, size, data, usage);
            } else {
                glBindBuffer(target, buffer);
                glBufferData(target, size, data, usage);
            }
        }

        void namedBufferStorage(
                gloop::enum_t target,
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::bitfield_t flags) {

            if (GLEW_ARB_buffer_storage) {
                if (GLEW_ARB_direct_state_access) {
                    glNamedBufferStorage(buffer, size, data, flags);
                } else {
                    glBindBuffer(target, buffer);
                    glBufferStorage(target, size, data, flags);
                }
            } else {
                throw "ARB_buffer_storage is not supported!";
            }
        }

        void createBuffers(                
                gloop::sizei_t n,
                gloop::uint_t * buffers) {

            if (GLEW_ARB_direct_state_access) {
                glCreateBuffers(n, buffers);
            } else {
                glGenBuffers(n, buffers);
            }
        }

        void deleteBuffers(
                gloop::sizei_t n,
                const gloop::uint_t * buffers) {

            glDeleteBuffers(n, buffers);
        }

        void bindBufferBase(
                gloop::enum_t target,
                gloop::uint_t buffer) {

            bindBufferBase(target, buffer);
        }

        void bindBufferRange(
                gloop::enum_t target,
                gloop::uint_t index,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size) {

            bindBufferRange(target, index, buffer, offset, size);
        }

        void namedBufferSubData(
                gloop::enum_t target,   
                gloop::uint_t buffer,
                gloop::intptr_t offset,
                gloop::sizeiptr_t size,
                const void * data) {

            if (GLEW_ARB_direct_state_access) {
                glNamedBufferSubData(buffer, offset, size, data);
            } else {
                glBindBuffer(target, buffer);
                glBufferSubData(target, offset, size, data);
            }
        }

        void * mapNamedBufferRange(
                gloop::enum_t target,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t length,
                gloop::bitfield_t access) {

            if (GLEW_ARB_direct_state_access) {
                return glMapNamedBufferRange(buffer, offset, length, access);
            } else {
                glBindBuffer(target, buffer);
                
                void * out = glMapBufferRange(buffer, offset, length, access);
                
                glBindBuffer(target, 0);
                
                return out;
            }
        }

        void unmapNamedBuffer(
                gloop::enum_t target, 
                gloop::uint_t buffer) {
            
            if (GLEW_ARB_direct_state_access) {
                glUnmapNamedBuffer(buffer);
            } else {
                glBindBuffer(target, buffer);
                glUnmapBuffer(target);
                glBindBuffer(target, 0);
            }
        }

        void getNamedBufferSubData(
                gloop::enum_t target,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size,
                void * data) {

            if (GLEW_ARB_direct_state_access) {
                glGetNamedBufferSubData(buffer, offset, size, data);
            } else {
                glBindBuffer(target, buffer);
                glGetBufferSubData(target, offset, size, data);
                glBindBuffer(target, 0);
            }
        }
    }
}
#endif
#undef GLEW