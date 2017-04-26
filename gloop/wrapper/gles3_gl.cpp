/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLES3 3
#if GL == GLES3

#include "gl.hpp"
#include "gl_gles3.hpp"

#include "../buffer.hpp"

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

#define __gloop_link(external, internal) decltype(external) external = internal
#define __gloop_decl(external, internal) static std::decay<decltype(external)>::type internal

namespace {
    static gloop::buffer::features _bufferFeatures;

    static void initBufferFeatures() {
        _bufferFeatures.map = true;
        _bufferFeatures.mapRange = true;
        _bufferFeatures.blockBind = true;
        _bufferFeatures.immutable = gloop::wrapper::EXT_buffer_storage;
    }
}

namespace gloop {
    const buffer::features& gloop::buffer::FEATURES = _bufferFeatures;
}

namespace gloop {
    namespace wrapper {
        namespace {
            __gloop_decl(glProgramUniform1i, _glProgramUniform1i);
            __gloop_decl(glProgramUniform2i, _glProgramUniform2i);
            __gloop_decl(glProgramUniform3i, _glProgramUniform3i);
            __gloop_decl(glProgramUniform4i, _glProgramUniform4i);

            __gloop_decl(glProgramUniform1f, _glProgramUniform1f);
            __gloop_decl(glProgramUniform2f, _glProgramUniform2f);
            __gloop_decl(glProgramUniform3f, _glProgramUniform3f);
            __gloop_decl(glProgramUniform4f, _glProgramUniform4f);

            __gloop_decl(glProgramUniform1iv, _glProgramUniform1iv);
            __gloop_decl(glProgramUniform2iv, _glProgramUniform2iv);
            __gloop_decl(glProgramUniform3iv, _glProgramUniform3iv);
            __gloop_decl(glProgramUniform4iv, _glProgramUniform4iv);

            __gloop_decl(glProgramUniform1fv, _glProgramUniform1fv);
            __gloop_decl(glProgramUniform2fv, _glProgramUniform2fv);
            __gloop_decl(glProgramUniform3fv, _glProgramUniform3fv);
            __gloop_decl(glProgramUniform4fv, _glProgramUniform4fv);

            __gloop_decl(glProgramUniformMatrix2fv, _glProgramUniformMatrix2fv);
            __gloop_decl(glProgramUniformMatrix3fv, _glProgramUniformMatrix3fv);
            __gloop_decl(glProgramUniformMatrix4fv, _glProgramUniformMatrix4fv);

            __gloop_decl(glDrawArraysIndirect, _glDrawArraysIndirect);
            __gloop_decl(glDrawElementsIndirect, _glDrawElementsIndirect);

            __gloop_decl(glDispatchCompute, _glDispatchCompute);
            __gloop_decl(glDispatchComputeIndirect, _glDispatchComputeIndirect);

            __gloop_decl(OPENGLES_3_1, _OPENGLES_3_1);

            static void init_OpenGLES_3_1() {
                GLint major = 0;
                GLint minor = 0;

                glGetIntegerv(GL_MAJOR_VERSION, &major);
                glGetIntegerv(GL_MINOR_VERSION, &minor);

                if (major > 3) {
                    _OPENGLES_3_1 = true;
                } else if (major == 3 && minor >= 1) {
                    _OPENGLES_3_1 = true;
                } else {
                    _OPENGLES_3_1 = false;
                }

                if (_OPENGLES_3_1) {
                    _glProgramUniform1i = load<void(GLuint, GLint, GLint)> ("glProgramUniform1i");
                    _glProgramUniform2i = load<void(GLuint, GLint, GLint, GLint)> ("glProgramUniform2i");
                    _glProgramUniform3i = load<void(GLuint, GLint, GLint, GLint, GLint)> ("glProgramUniform3i");
                    _glProgramUniform4i = load<void(GLuint, GLint, GLint, GLint, GLint, GLint)> ("glProgramUniform4i");

                    _glProgramUniform1f = load<void(GLuint, GLint, GLfloat)> ("glProgramUniform1f");
                    _glProgramUniform2f = load<void(GLuint, GLint, GLfloat, GLfloat)> ("glProgramUniform2f");
                    _glProgramUniform3f = load<void(GLuint, GLint, GLfloat, GLfloat, GLfloat)> ("glProgramUniform3f");
                    _glProgramUniform4f = load<void(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat)> ("glProgramUniform4f");

                    _glProgramUniform1iv = load<void(GLuint, GLint, GLsizei, const GLint*) >("glProgramUniform1iv");
                    _glProgramUniform2iv = load<void(GLuint, GLint, GLsizei, const GLint*) >("glProgramUniform2iv");
                    _glProgramUniform3iv = load<void(GLuint, GLint, GLsizei, const GLint*) >("glProgramUniform3iv");
                    _glProgramUniform4iv = load<void(GLuint, GLint, GLsizei, const GLint*) >("glProgramUniform4iv");

                    _glProgramUniform1fv = load<void(GLuint, GLint, GLsizei, const GLfloat*) >("glProgramUniform1fv");
                    _glProgramUniform2fv = load<void(GLuint, GLint, GLsizei, const GLfloat*) >("glProgramUniform2fv");
                    _glProgramUniform3fv = load<void(GLuint, GLint, GLsizei, const GLfloat*) >("glProgramUniform3fv");
                    _glProgramUniform4fv = load<void(GLuint, GLint, GLsizei, const GLfloat*) >("glProgramUniform4fv");

                    _glProgramUniformMatrix2fv = load<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) > ("glProgramUniform2fv");
                    _glProgramUniformMatrix3fv = load<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) > ("glProgramUniform3fv");
                    _glProgramUniformMatrix4fv = load<void(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) > ("glProgramUniform4fv");

                    _glDrawArraysIndirect = load<void(GLenum, const void *) > ("glDrawArraysIndirect");
                    _glDrawElementsIndirect = load<void(GLenum, GLenum, const void*) > ("glDrawElementsIndirect");

                    _glDispatchCompute = load<void(GLuint, GLuint, GLuint)> ("glDispatchCompute");
                    _glDispatchComputeIndirect = load<void(GLintptr)> ("glDispatchComputeIndirect");
                }
            }
        }

        __gloop_link(glProgramUniform1i, _glProgramUniform1i);
        __gloop_link(glProgramUniform2i, _glProgramUniform2i);
        __gloop_link(glProgramUniform3i, _glProgramUniform3i);
        __gloop_link(glProgramUniform4i, _glProgramUniform4i);

        __gloop_link(glProgramUniform1f, _glProgramUniform1f);
        __gloop_link(glProgramUniform2f, _glProgramUniform2f);
        __gloop_link(glProgramUniform3f, _glProgramUniform3f);
        __gloop_link(glProgramUniform4f, _glProgramUniform4f);

        __gloop_link(glProgramUniform1iv, _glProgramUniform1iv);
        __gloop_link(glProgramUniform2iv, _glProgramUniform2iv);
        __gloop_link(glProgramUniform3iv, _glProgramUniform3iv);
        __gloop_link(glProgramUniform4iv, _glProgramUniform4iv);

        __gloop_link(glProgramUniform1fv, _glProgramUniform1fv);
        __gloop_link(glProgramUniform2fv, _glProgramUniform2fv);
        __gloop_link(glProgramUniform3fv, _glProgramUniform3fv);
        __gloop_link(glProgramUniform4fv, _glProgramUniform4fv);

        __gloop_link(glProgramUniformMatrix2fv, _glProgramUniformMatrix2fv);
        __gloop_link(glProgramUniformMatrix3fv, _glProgramUniformMatrix3fv);
        __gloop_link(glProgramUniformMatrix4fv, _glProgramUniformMatrix4fv);

        __gloop_link(glDrawArraysIndirect, _glDrawArraysIndirect);
        __gloop_link(glDrawElementsIndirect, _glDrawElementsIndirect);

        __gloop_link(glDispatchCompute, _glDispatchCompute);
        __gloop_link(glDispatchComputeIndirect, _glDispatchComputeIndirect);

        __gloop_link(OPENGLES_3_1, _OPENGLES_3_1);

        namespace {
            __gloop_decl(OPENGLES_3_2, _OPENGLES_3_2);

            static void init_OpenGLES_3_2() {
                GLint major = 0;
                GLint minor = 0;

                glGetIntegerv(GL_MAJOR_VERSION, &major);
                glGetIntegerv(GL_MINOR_VERSION, &minor);

                if (major > 3) {
                    _OPENGLES_3_2 = true;
                } else if (major == 3 && minor >= 2) {
                    _OPENGLES_3_2 = true;
                } else {
                    _OPENGLES_3_2 = false;
                }
            }
        }

        __gloop_link(OPENGLES_3_2, _OPENGLES_3_2);

        namespace {
            __gloop_decl(glBufferStorageEXT, _glBufferStorageEXT);
            __gloop_decl(EXT_buffer_storage, _EXT_buffer_storage);

            static void init_EXT_buffer_storage() {
                _EXT_buffer_storage = hasExtension("EXT_buffer_storage");

                if (_EXT_buffer_storage) {
                    _glBufferStorageEXT = load<void(GLenum, GLsizeiptr, const void *, GLbitfield)>("glBufferStorageEXT");
                }
            }
        }

        __gloop_link(glBufferStorageEXT, _glBufferStorageEXT);
        __gloop_link(EXT_buffer_storage, _EXT_buffer_storage);

        namespace {
            __gloop_decl(OPENGLES_3_0, _OPENGLES_3_0);

            static void init_OpenGLES_3_0() {
                GLint major = 0;

                glGetIntegerv(GL_MAJOR_VERSION, &major);

                if (major >= 3) {
                    _OPENGLES_3_0 = true;
                }
            }
        }

        __gloop_link(OPENGLES_3_0, _OPENGLES_3_0);

        gloop::enum_t getError() {
            return glGetError();
        }

        const gloop::ubyte_t * getString(gloop::enum_t param) {
            return glGetString(param);
        }

        void init() {
            init_OpenGLES_3_0();

            init_OpenGLES_3_1();

            init_OpenGLES_3_2();

            init_EXT_buffer_storage();
            
            initBufferFeatures();
        }
    }
}

#undef __gloop_decl
#undef __gloop_link

#endif
#undef GLES3