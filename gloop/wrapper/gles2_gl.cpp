/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define GLES2 2
#if GL == GLES2
#include "gl.hpp"
#include "gl_gles2.hpp"

#include <functional>
#include <type_traits>

#include <SDL2/SDL_opengles2.h>
#include <SDL2/SDL_video.h>

#include "../glint.hpp"

namespace {

    template<typename T>
    static std::function<T> load(const char * fName) {
        auto addr = SDL_GL_GetProcAddress(fName);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        return std::function<T>(reinterpret_cast<__stdcall T*> (addr));
#else        
        return std::function<T>(reinterpret_cast<T*> (addr));
#endif
    }
}

namespace gloop {
    namespace wrapper {

        namespace {
            static std::decay<decltype(glGenVertexArraysOES)>::type _glGenVertexArraysOES;
            static std::decay<decltype(glBindVertexArrayOES)>::type _glBindVertexArrayOES;
            static std::decay<decltype(glDeleteVertexArraysOES)>::type _glDeleteVertexArraysOES;
            static bool _OES_vertex_array_object;

            static void init_OES_vertex_array_object() {
                _OES_vertex_array_object = hasExtension("GL_OES_vertex_array_object");

                if (_OES_vertex_array_object) {
                    _glGenVertexArraysOES = load<void(gloop::sizei_t, gloop::uint_t *)>("glGenVertexArraysOES");
                    _glDeleteVertexArraysOES = load<void(gloop::sizei_t, gloop::uint_t *)>("glDeleteVertexArraysOES");
                    _glBindVertexArrayOES = load<void(gloop::uint_t)>("glBindVertexArrayOES");
                }
            }
        }

        decltype(glGenVertexArraysOES) glGenVertexArraysOES = _glGenVertexArraysOES;
        decltype(glDeleteVertexArraysOES) glDeleteVertexArraysOES = _glDeleteVertexArraysOES;
        decltype(glBindVertexArrayOES) glBindVertexArrayOES = _glBindVertexArrayOES;
        decltype(OES_vertex_array_object) OES_vertex_array_object = _OES_vertex_array_object;

        namespace {
            static std::decay<decltype(glDrawArraysInstancedANGLE)>::type _glDrawArraysInstancedANGLE;
            static std::decay<decltype(glDrawElementsInstancedANGLE)>::type _glDrawElementsInstancedANGLE;
            static std::decay<decltype(glVertexAttribDivisorANGLE)>::type _glVertexAttribDivisorANGLE;
            static bool _ANGLE_instanced_arrays;

            static void init_ANGLE_instanced_arrays() {
                _ANGLE_instanced_arrays = hasExtension("GL_ANGLE_instanced_arrays");

                if (_ANGLE_instanced_arrays) {
                    _glDrawArraysInstancedANGLE = load<void(GLenum, GLint, GLsizei, GLsizei)>("glDrawArraysInstancedANGLE");
                    _glDrawElementsInstancedANGLE = load<void(GLenum, GLsizei, GLenum, const void *, GLsizei)>("glDrawElementsInstancedANGLE");
                    _glVertexAttribDivisorANGLE = load<void(GLuint, GLuint)>("glVertexAttribDivisorANGLE");
                }
            }
        }

        decltype(glDrawArraysInstancedANGLE) glDrawArraysInstancedANGLE = _glDrawArraysInstancedANGLE;
        decltype(glDrawElementsInstancedANGLE) glDrawElementsInstancedANGLE = _glDrawElementsInstancedANGLE;
        decltype(glVertexAttribDivisorANGLE) glVertexAttribDivisorANGLE = _glVertexAttribDivisorANGLE;
        decltype(ANGLE_instanced_arrays) ANGLE_instanced_arrays = _ANGLE_instanced_arrays;

        namespace {
            static std::decay<decltype(glMapBufferRangeEXT)>::type _glMapBufferRangeEXT;
            static bool _EXT_map_buffer_range;

            static void init_EXT_map_buffer_range() {
                _EXT_map_buffer_range = hasExtension("GL_EXT_map_buffer_range");

                if (_EXT_map_buffer_range) {
                    _glMapBufferRangeEXT = load<void*(GLenum, GLintptr, GLsizeiptr, GLbitfield)> ("glMapBufferRangeEXT");
                }
            }
        }

        decltype(glMapBufferRangeEXT) glMapBufferRangeEXT = _glMapBufferRangeEXT;
        decltype(EXT_map_buffer_range) EXT_map_buffer_range = _EXT_map_buffer_range;

        namespace {
            static std::decay<decltype(glMapBufferOES)>::type _glMapBufferOES;
            static std::decay<decltype(glUnmapBufferOES)>::type _glUnmapBufferOES;
            static bool _OES_mapbuffer;

            static void init_OES_mapbuffer() {
                _OES_mapbuffer = hasExtension("GL_OES_mapbuffer");

                if (_OES_mapbuffer) {
                    _glMapBufferOES = load<void*(GLenum, GLenum)>("glMapBufferOES");
                    _glUnmapBufferOES = load < GLboolean(GLenum)>("glUnmapBufferOES");
                }
            }
        }

        decltype(glMapBufferOES) glMapBufferOES = _glMapBufferOES;
        decltype(glUnmapBufferOES) glUnmapBufferOES = _glUnmapBufferOES;
        decltype(OES_mapbuffer) OES_mapbuffer = _OES_mapbuffer;

        namespace {
            static std::decay<decltype(glTexStorage2DEXT)>::type _glTexStorage2DEXT;
            static bool _EXT_texture_storage;

            static void init_EXT_texture_storage() {
                _EXT_texture_storage = hasExtension("GL_EXT_texture_storage");

                if (_EXT_texture_storage) {
                    _glTexStorage2DEXT = load<void(GLenum, GLsizei, GLenum, GLsizei, GLsizei)>("glTexStorage2DEXT");
                }
            }
        }

        decltype(glTexStorage2DEXT) glTexStorage2DEXT = _glTexStorage2DEXT;
        decltype(EXT_texture_storage) EXT_texture_storage = _EXT_texture_storage;
        
        namespace {
            static std::decay<decltype(glBufferStorageEXT)>::type _glBufferStorageEXT;
            static bool _EXT_buffer_storage;
            
            static void init_EXT_buffer_storage() {
                _EXT_buffer_storage = hasExtension("EXT_buffer_storage");
                
                if (_EXT_buffer_storage) {
                    _glBufferStorageEXT = load<void(GLenum, GLsizeiptr, const void *, GLbitfield)>("glBufferStorageEXT");
                }
            }
        }
        
        decltype(glBufferStorageEXT) glBufferStorageEXT = _glBufferStorageEXT;
        decltype(EXT_buffer_storage) EXT_buffer_storage = _EXT_buffer_storage;                

        gloop::enum_t getError() {
            return glGetError();
        }

        const gloop::ubyte_t * getString(gloop::enum_t param) {
            return glGetString(param);
        }

        void init() {
            
            init_EXT_buffer_storage();

            init_ANGLE_instanced_arrays();

            init_OES_mapbuffer();

            init_EXT_map_buffer_range();

            init_OES_vertex_array_object();

            init_EXT_texture_storage();
            
            
        }
    }
}
#endif
#undef GLES2