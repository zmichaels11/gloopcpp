/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLES3 3
#if GL == GLES3

#include "gl.hpp"
#include "gl_gles3.hpp"

#include <functional>
#include <type_traits>

#include <GLES3/gl3.h>

#include <SDL2/SDL_video.h>

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
            init_EXT_texture_storage();
            
            init_EXT_buffer_storage();
        }
    }
}

#endif
#undef GLES3