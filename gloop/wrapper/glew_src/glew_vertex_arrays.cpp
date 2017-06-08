#ifndef __EMSCRIPTEN__
#include "vertex_arrays.hpp"

#include <iostream>

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {

        void createVertexArrays(gloop::sizei_t n, gloop::uint_t * arrays) {
            glGenVertexArrays(n, arrays);
        }

        void bindVertexArray(gloop::uint_t vertexArray) {
            glBindVertexArray(vertexArray);
        }

        void enableVertexAttribArray(gloop::uint_t attrib) {
            glEnableVertexAttribArray(attrib);
        }

        void disableVertexAttribArray(gloop::uint_t attrib) {
            glDisableVertexAttribArray(attrib);
        }

        void deleteVertexArrays(gloop::sizei_t n, gloop::uint_t * arrays) {
            glDeleteVertexArrays(n, arrays);
        }
        
        void vertexAttribDivisor(gloop::uint_t index, gloop::uint_t divisor) {
            glVertexAttribDivisor(index, divisor);
        }
        
        void vertexAttribPointer(gloop::uint_t index, gloop::int_t size, gloop::enum_t type, gloop::boolean_t normalized, gloop::sizei_t stride, const void * pointer) {
            glVertexAttribPointer(index, size, type, normalized, stride, pointer);            
        }
        
        void vertexAttribIPointer(gloop::uint_t index, gloop::int_t size, gloop::enum_t type, gloop::sizei_t stride, const void * pointer) {
            glVertexAttribIPointer(index, size, type, stride, pointer);
        }
    }
}
#endif
