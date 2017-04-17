/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_objects.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 11:21 AM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        constexpr gloop::enum_t TEXTURE_MAG_FILTER = 0x2800;
        constexpr gloop::enum_t TEXTURE_MIN_FILTER = 0x2801;
        constexpr gloop::enum_t TEXTURE_WRAP_S = 0x2802;
        constexpr gloop::enum_t TEXTURE_WRAP_T = 0x2803;
        constexpr gloop::enum_t TEXTURE_MAX_ANISOTROPY = 0x84FE;
        constexpr gloop::enum_t TEXTURE_1D = 0x0DE0;
        constexpr gloop::enum_t TEXTURE_2D = 0x0DE1;
        constexpr gloop::enum_t BGR = 0x80E0;
        constexpr gloop::enum_t BGRA = 0x80E1;
        constexpr gloop::enum_t RGB = 0x1907;
        constexpr gloop::enum_t RGBA = 0x1908;

        void textureParameteri(
                gloop::uint_t texture,
                gloop::enum_t pname,
                gloop::int_t value);

        void textureParameterf(
                gloop::uint_t texture,
                gloop::enum_t pname,
                gloop::float_t value);

        void deleteTextures(
                gloop::sizei_t count,
                gloop::uint_t * textures);

        void createTextures(
                gloop::enum_t target,
                gloop::sizei_t count,
                gloop::uint_t * textures);

        void textureStorage1D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width);

        void textureStorage2D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height);

        void textureStorage3D(
                gloop::enum_t texture,
                gloop::sizei_t levels,
                gloop::enum_t internalFormat,
                gloop::sizei_t width, gloop::sizei_t height, gloop::sizei_t depth);

        void textureSubImage1D(
                gloop::uint_t texture,
                gloop::int_t level,
                gloop::int_t xOffset,
                gloop::sizei_t width,
                gloop::enum_t format,
                gloop::enum_t type,
                const void * pixels);

        void textureSubImage2D(
                gloop::uint_t texture,
                gloop::int_t level,
                gloop::int_t xOffset, gloop::int_t yOffset,
                gloop::sizei_t width, gloop::sizei_t height,
                gloop::enum_t format, gloop::enum_t type, const void * pixels);

        void textureSubImage3D(
                gloop::uint_t texture,
                gloop::int_t level,
                gloop::int_t xOffset, gloop::int_t yOffset, gloop::int_t zOffset,
                gloop::sizei_t width, gloop::sizei_t height, gloop::sizei_t depth,
                gloop::enum_t format, gloop::enum_t type, const void * pixels);

        void bindTextureUnit(
                gloop::uint_t unit,
                gloop::uint_t texture);
    }
}