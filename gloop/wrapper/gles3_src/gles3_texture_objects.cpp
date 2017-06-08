#include "texture_objects.hpp"

#include <algorithm>

#include <cstring>

#include <GLES3/gl3.h>

#include "../enums/texture_format.hpp"
#include "../exception/invalid_operation_exception.hpp"
#include "../glint.hpp"
#include "../gloop_throw.hpp"
#include "../pixel_formats.hpp"
#include "../tools.hpp"

#include "gl.hpp"
#include "gl_gles3.hpp"

namespace gloop {
    namespace wrapper {

        gloop::uint64_t getTextureHandle(gloop::uint_t texture) {
            gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
        }

        void makeTextureHandleResident(gloop::uint64_t handle) {
            gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
        }

        void makeTextureHandleNonResident(gloop::uint64_t handle) {
            gloop_throw(gloop::exception::invalid_operation_exception("Bindless textures are not supported!"));
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

            glTexStorage2D(GL_TEXTURE_2D, levels, internalFormat, width, 1);
        }

        void textureStorage2D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height) {

            glBindTexture(GL_TEXTURE_2D, texture);

            glTexStorage2D(GL_TEXTURE_2D, levels, internalFormat, width, height);
        }

        void textureStorage3D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height, gloop::sizei_t depth) {

            glBindTexture(GL_TEXTURE_3D, texture);
            glTexStorage3D(GL_TEXTURE_3D, levels, internalFormat, width, height, depth);
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

            glBindTexture(GL_TEXTURE_3D, texture);
            glTexSubImage3D(GL_TEXTURE_3D, level, xOffset, yOffset, zOffset, width, height, depth, format, type, pixels);
        }

        void bindTextureUnit(
                gloop::uint_t unit,
                gloop::uint_t texture) {

            glActiveTexture(GL_TEXTURE0 + unit);
            glBindTexture(GL_TEXTURE_2D, texture);
        }
    }
}
