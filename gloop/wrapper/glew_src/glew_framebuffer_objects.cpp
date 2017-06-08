#ifndef __EMSCRIPTEN__
#include "framebuffer_objects.hpp"

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {

        void createRenderbuffers(
                gloop::sizei_t n,
                gloop::uint_t * renderbuffers) {

            if (GLEW_ARB_direct_state_access) {
                glCreateRenderbuffers(n, renderbuffers);
            } else {
                glGenRenderbuffers(n, renderbuffers);
            }
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

            if (GLEW_ARB_direct_state_access) {
                glNamedRenderbufferStorage(renderbuffer, internalFormat, width, height);
            } else {
                glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
                glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
                glBindRenderbuffer(GL_RENDERBUFFER, 0);
            }
        }

        void createFramebuffers(
                gloop::sizei_t n,
                gloop::uint_t * framebuffers) {

            if (GLEW_ARB_direct_state_access) {
                glCreateFramebuffers(n, framebuffers);
            } else {
                glGenFramebuffers(n, framebuffers);
            }
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

            if (GLEW_ARB_direct_state_access) {
                glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbufferTarget, renderbuffer);
            } else {
                glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
                glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, renderbufferTarget, renderbuffer);
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
            }
        }

        void namedFramebufferTexture(
                gloop::uint_t framebuffer,
                gloop::enum_t attachment,
                gloop::uint_t texture,
                gloop::int_t level) {

            if (GLEW_ARB_direct_state_access) {
                glNamedFramebufferTexture(framebuffer, attachment, texture, level);
            } else {
                glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
                glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture, level);
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
            }
        }

        void bindFramebuffer(
                gloop::enum_t target,
                gloop::uint_t framebuffer) {

            glBindFramebuffer(target, framebuffer);
        }
    }
}
#endif
