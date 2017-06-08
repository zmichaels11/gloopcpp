/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "vertex_arrays.hpp"

#include <SDL2/SDL_opengles2.h>

#include "../glint.hpp"
#include "gl_gles2.hpp"

namespace gloop {
    namespace wrapper {

        void createVertexArrays(gloop::sizei_t n, gloop::uint_t * arrays) {
            (*OES_vertex_array_object.genVertexArraysOES) (n, arrays);
        }

        void bindVertexArray(gloop::uint_t vertexArray) {
            (*OES_vertex_array_object.bindVertexArrayOES) (vertexArray);
        }

        void enableVertexAttribArray(gloop::uint_t attrib) {
            glEnableVertexAttribArray(attrib);
        }

        void disableVertexAttribArray(gloop::uint_t attrib) {
            glDisableVertexAttribArray(attrib);
        }

        void deleteVertexArrays(gloop::sizei_t n, gloop::uint_t * arrays) {
            (*OES_vertex_array_object.deleteVertexArraysOES) (n, arrays);
        }
        
        void vertexAttribDivisor(gloop::uint_t index, gloop::uint_t divisor) {
            (*ANGLE_instanced_arrays.vertexAttribDivisorANGLE) (index, divisor);
        }
        
        void vertexAttribPointer(gloop::uint_t index, gloop::int_t size, gloop::enum_t type, gloop::boolean_t normalized, gloop::sizei_t stride, const void * pointer) {
            glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        }
        
        void vertexAttribIPointer(gloop::uint_t index, gloop::int_t size, gloop::enum_t type, gloop::sizei_t stride, const void * pointer) {
            // no idea if this would be alright...
            glVertexAttribPointer(index, size, type, GL_FALSE, stride, pointer);
        }
    }
}
