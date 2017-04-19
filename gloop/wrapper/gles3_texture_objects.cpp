#define GLES3 3
#if GL == GLES3
#include "texture_objects.hpp"

#include <algorithm>

#include <cstring>

#include <GLES3/gl3.h>
#include <GLES3/gl31.h>

#include "../enums/texture_format.hpp"
#include "../glint.hpp"
#include "../gloop_throw.hpp"
#include "../pixel_formats.hpp"
#include "../tools.hpp"

#include "gl.hpp"
#include "gl_gles3.hpp"

namespace gloop {
    namespace wrapper {

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

            if (EXT_texture_storage) {
                glTexStorage2DEXT(GL_TEXTURE_2D, levels, internalFormat, width, 1);
            } else {
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

                for (int i = 0; i < levels; i++) {
                    glTexImage2D(GL_TEXTURE_2D, i, glFormat, width, 1, 0, glFormat, glType, nullptr);
                    width = std::max(1, (width / 2));
                }
            }
        }

        void textureStorage2D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height) {

            glBindTexture(GL_TEXTURE_2D, texture);

            if (EXT_texture_storage) {
                glTexStorage2DEXT(GL_TEXTURE_2D, levels, internalFormat, width, height);
            } else {
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

                for (int i = 0; i < levels; i++) {
                    glTexImage2D(GL_TEXTURE_2D, i, glFormat, width, height, 0, glFormat, glType, nullptr);

                    width = std::max(1, (width / 2));
                    height = std::max(1, (height / 2));
                }
            }
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
        }

        void textureSubImage2D(
                gloop::uint_t texture,
                gloop::int_t level,
                gloop::int_t xOffset, gloop::int_t yOffset,
                gloop::sizei_t width, gloop::sizei_t height,
                gloop::enum_t format, gloop::enum_t type, const void * pixels) {

            glBindTexture(GL_TEXTURE_2D, texture);

            glTexSubImage2D(GL_TEXTURE_2D, level, xOffset, yOffset, width, height, format, type, pixels);
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
#undef GLES3