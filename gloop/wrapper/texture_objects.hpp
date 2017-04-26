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
#include "gl.hpp"

namespace gloop {
    namespace wrapper {        
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
        
        gloop::uint64_t getTextureHandle(gloop::uint_t texture);
        
        void makeTextureHandleResident(gloop::uint64_t handle);
        
        void makeTextureHandleNonResident(gloop::uint64_t handle);
    }
}