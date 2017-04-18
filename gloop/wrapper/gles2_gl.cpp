/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLES2 2
#if GL == GLES2
#include "gl.hpp"

#include <iostream>

#include <SDL2/SDL_opengles2.h>
#include <SDL2/SDL_video.h>

#include "../glint.hpp"

PFNGLDRAWARRAYSINSTANCEDANGLEPROC glDrawArraysInstancedANGLE;
PFNGLDRAWELEMENTSINSTANCEDANGLEPROC glDrawElementsInstancedANGLE;
PFNGLVERTEXATTRIBDIVISORANGLEPROC glVertexAttribDivisorANGLE;
PFNGLMAPBUFFERRANGEEXTPROC glMapBufferRangeEXT;
PFNGLMAPBUFFEROESPROC glMapBufferOES;
PFNGLUNMAPBUFFEROESPROC glUnmapBufferOES;
PFNGLBUFFERSTORAGEEXTPROC glBufferStorageEXT;
PFNGLGENVERTEXARRAYSOESPROC glGenVertexArraysOES;
PFNGLDELETEVERTEXARRAYSOESPROC glDeleteVertexArraysOES;
PFNGLBINDVERTEXARRAYOESPROC glBindVertexArrayOES;

namespace gloop {
    namespace wrapper {

        gloop::enum_t getError() {
            return glGetError();
        }
        
        const gloop::ubyte_t * getString(gloop::enum_t param) {
            return glGetString(param);
        }

        void init() {                        
            glDrawArraysInstancedANGLE = (PFNGLDRAWARRAYSINSTANCEDANGLEPROC) SDL_GL_GetProcAddress("glDrawArraysInstancedANGLE");            
            glDrawElementsInstancedANGLE = (PFNGLDRAWELEMENTSINSTANCEDANGLEPROC) SDL_GL_GetProcAddress("glDrawElementsInstancedANGLE");
            glVertexAttribDivisorANGLE = (PFNGLVERTEXATTRIBDIVISORANGLEPROC) SDL_GL_GetProcAddress("glVertexAttribDivisorANGLE");
            glMapBufferRangeEXT = (PFNGLMAPBUFFERRANGEEXTPROC) SDL_GL_GetProcAddress("glMapBufferRangeEXT");
            glMapBufferOES = (PFNGLMAPBUFFEROESPROC) SDL_GL_GetProcAddress("glMapBufferOES");
            glUnmapBufferOES = (PFNGLUNMAPBUFFEROESPROC) SDL_GL_GetProcAddress("glUnmapBufferOES");
            glBufferStorageEXT = (PFNGLBUFFERSTORAGEEXTPROC) SDL_GL_GetProcAddress("glBufferStorageEXT");
            glGenVertexArraysOES = (PFNGLGENVERTEXARRAYSOESPROC) SDL_GL_GetProcAddress("glGenVertexArraysOES");
            glDeleteVertexArraysOES = (PFNGLDELETEVERTEXARRAYSOESPROC) SDL_GL_GetProcAddress("glDeleteVertexArraysOES");
            glBindVertexArrayOES = (PFNGLBINDVERTEXARRAYOESPROC) SDL_GL_GetProcAddress("glBindVertexArrayOES");                  
        }
    }
}
#endif
#undef GLES2