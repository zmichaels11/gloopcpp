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

bool EXT_buffer_storage;
bool ANGLE_instanced_arrays;
bool OES_mapbuffer;
bool EXT_map_buffer_range;
bool OES_vertex_array_object;

namespace gloop {
    namespace wrapper {

        gloop::enum_t getError() {
            return glGetError();
        }

        const gloop::ubyte_t * getString(gloop::enum_t param) {
            return glGetString(param);
        }

        void init() {
            EXT_buffer_storage = hasExtension("GL_EXT_buffer_storage");
            if (EXT_buffer_storage) {
                glBufferStorageEXT = (PFNGLBUFFERSTORAGEEXTPROC) SDL_GL_GetProcAddress("glBufferStorageEXT");
                
                if (glBufferStorageEXT == nullptr) {
                    EXT_buffer_storage = false;
                }
            }

            ANGLE_instanced_arrays = hasExtension("ANGLE_instanced_arrays");
            if (ANGLE_instanced_arrays) {
                glDrawArraysInstancedANGLE = (PFNGLDRAWARRAYSINSTANCEDANGLEPROC) SDL_GL_GetProcAddress("glDrawArraysInstancedANGLE");
                glDrawElementsInstancedANGLE = (PFNGLDRAWELEMENTSINSTANCEDANGLEPROC) SDL_GL_GetProcAddress("glDrawElementsInstancedANGLE");
                glVertexAttribDivisorANGLE = (PFNGLVERTEXATTRIBDIVISORANGLEPROC) SDL_GL_GetProcAddress("glVertexAttribDivisorANGLE");
                
                if (glDrawArraysInstancedANGLE == nullptr
                        || glDrawElementsInstancedANGLE == nullptr
                        || glVertexAttribDivisorANGLE == nullptr) {
                    
                    ANGLE_instanced_arrays = false;
                }
            }

            OES_mapbuffer = hasExtension("GL_OES_mapbuffer");
            if (OES_mapbuffer) {
                glMapBufferOES = (PFNGLMAPBUFFEROESPROC) SDL_GL_GetProcAddress("glMapBufferOES");
                glUnmapBufferOES = (PFNGLUNMAPBUFFEROESPROC) SDL_GL_GetProcAddress("glUnmapBufferOES");
                
                if (glMapBufferOES == nullptr || glUnmapBufferOES == nullptr) {
                    OES_mapbuffer = false;
                }
            }

            EXT_map_buffer_range = hasExtension("GL_EXT_map_buffer_range");
            if (EXT_map_buffer_range) {
                glMapBufferRangeEXT = (PFNGLMAPBUFFERRANGEEXTPROC) SDL_GL_GetProcAddress("glMapBufferRangeEXT");
                
                if (glMapBufferRangeEXT == nullptr) {
                    EXT_map_buffer_range = false;
                }
            }

            OES_vertex_array_object = hasExtension("GL_OES_vertex_array_object");
            if (OES_vertex_array_object) {
                glGenVertexArraysOES = (PFNGLGENVERTEXARRAYSOESPROC) SDL_GL_GetProcAddress("glGenVertexArraysOES");
                glDeleteVertexArraysOES = (PFNGLDELETEVERTEXARRAYSOESPROC) SDL_GL_GetProcAddress("glDeleteVertexArraysOES");
                glBindVertexArrayOES = (PFNGLBINDVERTEXARRAYOESPROC) SDL_GL_GetProcAddress("glBindVertexArrayOES");
                
                if(glGenVertexArraysOES == nullptr
                        || glDeleteVertexArraysOES == nullptr
                        || glBindVertexArrayOES == nullptr) {
                    
                    OES_vertex_array_object = false;
                }
            }
        }
    }
}
#endif
#undef GLES2