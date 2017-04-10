#define GLES2 2
#if GL == GLES2
#include "texture_objects.hpp"

#include <SDL2/SDL_opengles2.h>

#include "../glint.hpp"

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
    }
}

#endif