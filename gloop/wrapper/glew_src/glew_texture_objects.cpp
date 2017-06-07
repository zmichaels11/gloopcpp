/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLEW 1
#if GL == GLEW
#include "texture_objects.hpp"

#include <algorithm>
#include <iostream>

#include <GL/glew.h>

#include "../glint.hpp"
#include "../gloop_throw.hpp"
#include "../exception/invalid_enum_exception.hpp"
#include "../exception/invalid_operation_exception.hpp"
#include "../tools.hpp"

namespace gloop {
    namespace wrapper {
        
        gloop::uint64_t getTextureHandle(gloop::uint_t texture) {
            if (GLEW_ARB_bindless_texture) {
                return glGetTextureHandleARB(texture);
            } else if (GLEW_NV_bindless_texture) {
                return glGetTextureHandleNV(texture);
            } else {
                gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
            }
        }
        
        void makeTextureHandleResident(gloop::uint64_t handle) {
            if (GLEW_ARB_bindless_texture) {
                glMakeTextureHandleResidentARB(handle);
            } else if (GLEW_NV_bindless_texture) {
                glMakeTextureHandleResidentNV(handle);
            } else {
                gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
            }
        }
        
        void makeTextureHandleNonResident(gloop::uint64_t handle) {
            if (GLEW_ARB_bindless_texture) {
                glMakeTextureHandleNonResidentARB(handle);
            } else if (GLEW_NV_bindless_texture) {
                glMakeTextureHandleNonResidentNV(handle);
            } else {
                gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
            }
        }

        void textureParameterf(
                gloop::uint_t texture,
                gloop::enum_t pname,
                gloop::float_t value) {

            if (GLEW_ARB_direct_state_access) {
                glTextureParameterf(texture, pname, value);
            } else {
                glBindTexture(GL_TEXTURE_2D, texture);
                glTexParameterf(GL_TEXTURE_2D, pname, value);
            }
        }

        void textureParameteri(
                gloop::uint_t texture,
                gloop::enum_t pname,
                gloop::int_t value) {

            if (GLEW_ARB_direct_state_access) {
                glTextureParameteri(texture, pname, value);
            } else {
                glBindTexture(GL_TEXTURE_2D, texture);
                glTexParameteri(GL_TEXTURE_2D, pname, value);
            }
        }

        void createTextures(
                gloop::enum_t target,
                gloop::sizei_t count,
                gloop::uint_t * textures) {

            if (GLEW_ARB_direct_state_access) {
                glCreateTextures(target, count, textures);
            } else {
                glGenTextures(count, textures);
            }
        }

        void deleteTextures(
                gloop::sizei_t count,
                gloop::uint_t * textures) {
            
            glDeleteTextures(count, textures);
        }

        void textureStorage2D(
                gloop::uint_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height) {

            if (GLEW_ARB_texture_storage) {
                if (GLEW_ARB_direct_state_access) {
                    glTextureStorage2D(texture, levels, internalFormat, width, height);
                } else {
                    glBindTexture(GL_TEXTURE_2D, texture);
                    glTexStorage2D(GL_TEXTURE_2D, levels, internalFormat, width, height);
                }
            } else {
                GLenum glType = 0;
                GLenum glFormat = 0;

                switch (internalFormat) {
                    case GL_RGB8:
                        glType = GL_UNSIGNED_BYTE;
                        glFormat = GL_RGB;
                        break;
                    case GL_RGBA8:
                        glType = GL_UNSIGNED_BYTE;
                        glFormat = GL_RGBA;
                        break;
                    case GL_RGB32F:
                        glType = GL_FLOAT;
                        glFormat = GL_RGB;
                        break;
                    case GL_RGBA32F:
                        glType = GL_FLOAT;
                        glFormat = GL_RGBA;
                        break;
                    default:
                        gloop_throw(gloop::exception::invalid_enum_exception("Unsupported format!"));
                }

                glBindTexture(GL_TEXTURE_2D, texture);

                for (int i = 0; i < levels; i++) {
                    glTexImage2D(GL_TEXTURE_2D, i, glFormat, width, height, 0, glFormat, glType, nullptr);

                    width = std::max(1, (width / 2));
                    height = std::max(1, (height / 2));
                }

                gloop::tools::assertGLError("Error allocating storage!");
            }
        }

        void textureSubImage2D(
                gloop::uint_t texture,
                gloop::int_t level,
                gloop::int_t xOffset, gloop::int_t yOffset,
                gloop::sizei_t width, gloop::sizei_t height,
                gloop::enum_t format, gloop::enum_t type, const void * pixels) {

            if (GLEW_ARB_direct_state_access) {
                glTextureSubImage2D(texture, level, xOffset, yOffset, width, height, format, type, pixels);
            } else {
                glBindTexture(GL_TEXTURE_2D, texture);
                glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, yOffset, width, height, format, type, pixels);
            }
        }

        void bindTextureUnit(
                gloop::uint_t unit,
                gloop::uint_t texture) {

            if (GLEW_ARB_direct_state_access) {
                glBindTextureUnit(unit, texture);                     
            } else {
                glActiveTexture(GL_TEXTURE0 + unit);
                glBindTexture(GL_TEXTURE_2D, texture);                
            }
        }
    }
}
#endif
#undef GLEW
