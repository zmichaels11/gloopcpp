/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLEW 1
#if GL == GLEW
#include "texture_objects.hpp"

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {

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
    }
}
#endif
#undef GLEW