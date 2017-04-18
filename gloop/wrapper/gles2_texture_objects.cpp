#define GLES2 2
#if GL == GLES2
#include "texture_objects.hpp"

#include <algorithm>
#include <iostream>

#include <cstring>

#include <SDL2/SDL_opengles2.h>

#include "../enums/texture_format.hpp"
#include "../glint.hpp"
#include "../gloop_throw.hpp"
#include "../pixel_formats.hpp"
#include "../tools.hpp"

#include "gl.hpp"

namespace gloop {
    namespace wrapper {
        namespace {            
            static bool isBGRASupported() {
                static const bool support = hasExtension("GL_EXT_texture_format_BGRA8888");
                
                return support;
            }
            
            static bool isBGR(const gloop::enum_t format) {
                return gloop::wrapper::BGR;
            }
            
            static bool isBGRA(const gloop::enum_t format) {
                return gloop::wrapper::BGRA;
            }
                 
            static bool isFloat(const gloop::enum_t type) {
                return type == gloop::wrapper::FLOAT;
            }
            
            static bool isUint8(const gloop::enum_t type) {
                return type == gloop::wrapper::UNSIGNED_BYTE;
            }
        }
        

        void textureParameterf(
                gloop::uint_t texture,
                gloop::enum_t pname,
                gloop::float_t value) {

            glBindTexture(GL_TEXTURE_2D, texture);
            glTexParameterf(GL_TEXTURE_2D, pname, value);
        }

        void textureParameteri(
                gloop::uint_t texture,
                gloop::enum_t pname,
                gloop::int_t value) {

            glBindTexture(GL_TEXTURE_2D, texture);
            glTexParameteri(GL_TEXTURE_2D, pname, value);

        }

        void createTextures(
                gloop::enum_t target,
                gloop::sizei_t count,
                gloop::uint_t * textures) {

            glGenTextures(count, textures);
        }

        void deleteTextures(
                gloop::sizei_t count,
                gloop::uint_t * textures) {

            glDeleteTextures(count, textures);
        }

        void textureStorage1D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width) {

            glBindTexture(GL_TEXTURE_2D, texture);

            for (int i = 0; i < levels; i++) {
                glTexImage2D(GL_TEXTURE_2D, i, internalFormat, width, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
                width = std::max(1, (width / 2));
            }

            glBindTexture(GL_TEXTURE_2D, 0);
        }

        void textureStorage2D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height) {

            GLenum glType = 0;
            GLenum glFormat = 0;

            switch (internalFormat) {
                case 0x8051:
                    glType = GL_UNSIGNED_BYTE;
                    glFormat = GL_RGB;
                    
                    break;
                case 0x8058:
                    glType = GL_UNSIGNED_BYTE;
                    glFormat = GL_RGBA;
                    break;
                case 0x8815:
                    glType = GL_FLOAT;
                    glFormat = GL_RGB;
                    break;
                case 0x8814:
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
            
            glBindTexture(GL_TEXTURE_2D, 0);
            
            gloop::tools::assertGLError("Error allocating storage!");
        }

        void textureStorage3D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height, gloop::sizei_t depth) {

            gloop_throw(gloop::exception::invalid_operation_exception("3D textures are not supported!"));
        }        

        void textureSubImage1D(
                gloop::uint_t texture,
                gloop::int_t level,
                gloop::int_t xOffset,
                gloop::sizei_t width,
                gloop::enum_t format,
                gloop::enum_t type,
                const void * pixels) {

            glBindTexture(GL_TEXTURE_2D, texture);

            glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, 0, width, 1, format, type, pixels);

            glBindTexture(GL_TEXTURE_2D, 0);
        }

        void textureSubImage2D(
                gloop::uint_t texture,
                gloop::int_t level,
                gloop::int_t xOffset, gloop::int_t yOffset,
                gloop::sizei_t width, gloop::sizei_t height,
                gloop::enum_t format, gloop::enum_t type, const void * pixels) {                        
            
            glBindTexture(GL_TEXTURE_2D, texture);

            if (isBGR(format)) {
                if (!isBGRASupported()) {
                    const auto size = width * height - xOffset * yOffset;
                    
                    if (isFloat(type)) {
                        auto dst = new gloop::pixel_formats::R32F_G32F_B32F[size];
                        const auto src = reinterpret_cast<const pixel_formats::B32F_G32F_R32F *> (pixels);
                        
                        pixel_formats::reorder(dst, src, size);
                        
                        glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, yOffset, width, height, wrapper::RGB, wrapper::FLOAT, dst);
                        
                        delete[] dst;
                    } else if (isUint8(type)) {
                        auto dst = new pixel_formats::R8_G8_B8[size];
                        const auto src = reinterpret_cast<const pixel_formats::B8_G8_R8 *> (pixels);
                        
                        pixel_formats::reorder(dst, src, size);
                        
                        glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, yOffset, width, height, wrapper::RGB, wrapper::UNSIGNED_BYTE, dst);
                        
                        delete[] dst;
                    } else {
                        gloop_throw(gloop::exception::invalid_enum_exception("Unsupported type!"));
                    }                                        
                } else {
                    glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, yOffset, width, height, format, type, pixels);
                }
            } else if (isBGRA(format)) {
                if (!isBGRASupported()) {
                    const auto size = width * height - xOffset * yOffset;
                    
                    if (isFloat(type)) {
                        auto dst = new gloop::pixel_formats::R32F_G32F_B32F_A32F[size];
                        const auto src = reinterpret_cast<const pixel_formats::B32F_G32F_R32F_A32F *> (pixels);
                        
                        pixel_formats::reorder(dst, src, size);
                        
                        glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, yOffset, width, height, wrapper::RGBA, wrapper::FLOAT, dst);
                        
                        delete[] dst;
                    } else if (isUint8(type)) {
                        auto dst = new pixel_formats::R8_G8_B8_A8[size];
                        const auto src = reinterpret_cast<const pixel_formats::B8_G8_R8_A8 *> (pixels);
                        
                        pixel_formats::reorder(dst, src, size);
                        
                        glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, yOffset, width, height, wrapper::RGBA, wrapper::UNSIGNED_BYTE, dst);
                        
                        delete[] dst;
                    } else {
                        gloop_throw(gloop::exception::invalid_enum_exception("Unsupported type!"));
                    }                                        
                } else {
                    glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, yOffset, width, height, format, type, pixels);
                }
            }

            glBindTexture(GL_TEXTURE_2D, 0);              
            
            gloop::tools::assertGLError();
        }

        void textureSubImage3D(
                gloop::uint_t texture,
                gloop::int_t level,
                gloop::int_t xOffset, gloop::int_t yOffset, gloop::int_t zOffset,
                gloop::sizei_t width, gloop::sizei_t height, gloop::sizei_t depth,
                gloop::enum_t format, gloop::enum_t type, const void * pixels) {

            gloop_throw(gloop::exception::invalid_operation_exception("3D textures are not supported!"));
        }

        void bindTextureUnit(
                gloop::uint_t unit,
                gloop::uint_t texture) {
            
            glActiveTexture(GL_TEXTURE0 + unit);
            glBindTexture(GL_TEXTURE_2D, texture);            
        }
    }
}

#endif