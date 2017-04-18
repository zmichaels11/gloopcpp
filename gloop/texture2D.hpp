/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture2D.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 9:59 AM
 */

#pragma once

#include <SDL2/SDL_surface.h>

#include "enums/texture_internal_format.hpp"
#include "enums/texture_format.hpp"
#include "glint.hpp"
#include "pixel_formats.hpp"
#include "tools.hpp"

namespace gloop {

    class texture2D {
    public:

        struct size {
            gloop::sizei_t width;
            gloop::sizei_t height;
        };
    private:
        gloop::uint_t _id;
        size _size;
        enums::texture_internal_format _format;
        gloop::sizei_t _levels;

    public:

        texture2D() :
        _size({0, 0}),
        _format(static_cast<enums::texture_internal_format> (0)),
        _levels(0) {
        }

        texture2D(texture2D&) = delete;

        ~texture2D();

        gloop::uint_t getId() const;

        bool isValid() const;

        inline operator bool() const {
            return isValid();
        }

        const size& getSize() const;

        gloop::uint_t getMipmapLevelCount() const;

        enums::texture_internal_format getInternalFormat() const;

        void allocate(
                const enums::texture_internal_format internalFormat,
                const gloop::sizei_t levels,
                const gloop::sizei_t width, const gloop::sizei_t height);
        
        void allocate(const SDL_Surface * img);
        
        inline void allocate(const std::unique_ptr<SDL_Surface, tools::sdl_surface_deleter>& pImg) {
            allocate(pImg.get());
        }

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::B32F_G32F_R32F * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::B32F_G32F_R32F_A32F * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::B8_G8_R8 * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::B8_R8_G8_A8 * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::R32F_G32F_B32F * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::R32F_G32F_B32F_A32F * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::R8_G8_B8 * data) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const gloop::pixel_formats::R8_G8_B8_A8 * ddata) const;

        void update(
                const gloop::sizei_t level,
                const gloop::int_t xOffset, const gloop::int_t yOffset,
                const gloop::sizei_t width, const gloop::sizei_t height,
                const SDL_Surface * image) const;

        inline void update(
                const gloop::sizei_t level,
                const SDL_Surface * image) const {

            update(level, 0, 0, image->w, image->h, image);
        }

        void free();

        void bind(const gloop::uint_t unit) const;
    };
}