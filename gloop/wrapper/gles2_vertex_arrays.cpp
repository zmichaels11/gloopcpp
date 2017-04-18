/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLES2 2
#if GL == GLES2

#include "vertex_arrays.hpp"

#include <SDL2/SDL_opengles2.h>

#include "../glint.hpp"

extern PFNGLGENVERTEXARRAYSOESPROC glGenVertexArraysOES;
extern PFNGLDELETEVERTEXARRAYSOESPROC glDeleteVertexArraysOES;
extern PFNGLBINDVERTEXARRAYOESPROC glBindVertexArrayOES;
extern PFNGLVERTEXATTRIBDIVISORANGLEPROC glVertexAttribDivisorANGLE;

namespace gloop {
    namespace wrapper {

        void createVertexArrays(gloop::sizei_t n, gloop::uint_t * arrays) {
            glGenVertexArraysOES(n, arrays);
        }

        void bindVertexArray(gloop::uint_t vertexArray) {
            glBindVertexArrayOES(vertexArray);
        }

        void enableVertexAttribArray(gloop::uint_t attrib) {
            glEnableVertexAttribArray(attrib);
        }

        void disableVertexAttribArray(gloop::uint_t attrib) {
            glDisableVertexAttribArray(attrib);
        }

        void deleteVertexArrays(gloop::sizei_t n, const gloop::uint_t * arrays) {
            glDeleteVertexArraysOES(n, arrays);
        }
        
        void vertexAttribDivisor(gloop::uint_t index, gloop::uint_t divisor) {
            glVertexAttribDivisorANGLE(index, divisor);
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
#endif
#undef GLES2