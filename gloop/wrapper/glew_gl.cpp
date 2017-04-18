/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLEW 1
#if GL == GLEW
#include "gl.hpp"

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        gloop::enum_t getError() {
            return glGetError();
        }
        
        void init() {
            if (glewInit() != GLEW_OK) {                
                throw "GLEW could not be initialized!";
            }
        }
        
        const gloop::ubyte_t * getString(gloop::enum_t param) {
            return glGetString(param);
        }
    }
}
#endif
#undef GLEW