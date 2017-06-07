/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define GLES3 3
#if GL == GLES3
#include "framebuffer_objects.hpp"

#include <GLES3/gl3.h>

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
        }

        void namedFramebufferTexture(
                gloop::uint_t framebuffer,
                gloop::enum_t attachment,
                gloop::uint_t texture,
                gloop::int_t level) {

            glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
            glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture, level);
        }

        void bindFramebuffer(
                gloop::enum_t target,
                gloop::uint_t framebuffer) {

            glBindFramebuffer(target, framebuffer);
        }
    }
}
#endif
#undef GLES3