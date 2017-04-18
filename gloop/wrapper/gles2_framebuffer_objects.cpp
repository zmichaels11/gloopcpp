/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLES2 2
#if GL == GLES2
#include "framebuffer_objects.hpp"

#include <SDL2/SDL_opengles2.h>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {

        void createRenderbuffers(
                gloop::sizei_t n,
                gloop::uint_t * renderbuffers) {

            glGenRenderbuffers(n, renderbuffers);
        }

        void deleteRenderbuffers(
                gloop::sizei_t n,
                gloop::uint_t * renderbuffers) {

            glDeleteRenderbuffers(n, renderbuffers);
        }

        void namedRenderbufferStorage(
                gloop::uint_t renderbuffer,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height) {

            glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
            glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
            glBindRenderbuffer(GL_RENDERBUFFER, 0);
        }

        void createFramebuffers(
                gloop::sizei_t n,
                gloop::uint_t * framebuffers) {

            glGenFramebuffers(n, framebuffers);
        }

        void deleteFramebuffers(
                gloop::sizei_t n,
                gloop::uint_t * framebuffers) {

            glDeleteFramebuffers(n, framebuffers);
        }

        void namedFramebufferRenderbuffer(
                gloop::uint_t framebuffer,
                gloop::enum_t attachment,
                gloop::enum_t renderbufferTarget,
                gloop::uint_t renderbuffer) {

            glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, renderbufferTarget, renderbuffer);
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        void namedFramebufferTexture(
                gloop::uint_t framebuffer,
                gloop::enum_t attachment,
                gloop::uint_t texture,
                gloop::int_t level) {

            glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
            glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture, level);
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        void bindFramebuffer(
                gloop::enum_t target,
                gloop::uint_t framebuffer) {

            glBindFramebuffer(target, framebuffer);
        }
    }
}
#endif