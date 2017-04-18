/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   framebuffer_objects.hpp
 * Author: zmichaels
 *
 * Created on April 18, 2017, 3:41 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        void createRenderbuffers(
                gloop::sizei_t n,
                gloop::uint_t * renderbuffers);

        void deleteRenderbuffers(
                gloop::sizei_t n,
                gloop::uint_t * renderbuffers);

        void namedRenderbufferStorage(
                gloop::uint_t renderbuffer,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height);

        void createFramebuffers(
                gloop::sizei_t n,
                gloop::uint_t * framebuffers);

        void deleteFramebuffers(
                gloop::sizei_t n,
                gloop::uint_t * framebuffers);

        void namedFramebufferRenderbuffer(
                gloop::uint_t framebuffer,
                gloop::enum_t attachment,
                gloop::enum_t renderbufferTarget,
                gloop::uint_t renderbuffer);

        void namedFramebufferTexture(
                gloop::uint_t framebuffer,
                gloop::enum_t attachment,
                gloop::uint_t texture,
                gloop::int_t level);

        void bindFramebuffer(
                gloop::enum_t target,
                gloop::uint_t framebuffer);
    }
}