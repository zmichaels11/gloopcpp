/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pixel_format.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 10:51 AM
 */

#pragma once

#include <cstddef>

#include "enums/texture_format.hpp"
#include "glint.hpp"

namespace gloop {
    namespace pixel_formats {

        struct R8_G8_B8 {
            gloop::uint8_t red;
            gloop::uint8_t green;
            gloop::uint8_t blue;
        };

        struct R8_G8_B8_A8 {
            gloop::uint8_t red;
            gloop::uint8_t green;
            gloop::uint8_t blue;
            gloop::uint8_t alpha;
        };

        struct B8_G8_R8 {
            gloop::uint8_t blue;
            gloop::uint8_t green;
            gloop::uint8_t red;
        };

        struct B8_G8_R8_A8 {
            gloop::uint8_t blue;
            gloop::uint8_t green;
            gloop::uint8_t red;
            gloop::uint8_t alpha;
        };

        struct R32F_G32F_B32F {
            gloop::float_t red;
            gloop::float_t green;
            gloop::float_t blue;
        };

        struct B32F_G32F_R32F {
            gloop::float_t blue;
            gloop::float_t green;
            gloop::float_t red;
        };

        struct R32F_G32F_B32F_A32F {
            gloop::float_t red;
            gloop::float_t green;
            gloop::float_t blue;
            gloop::float_t alpha;
        };

        struct B32F_G32F_R32F_A32F {
            gloop::float_t blue;
            gloop::float_t green;
            gloop::float_t red;
            gloop::float_t alpha;
        };
        
        inline enums::texture_format getFormat(const B32F_G32F_R32F * pixels) {
            return enums::texture_format::BGR;
        }
        
        inline enums::texture_format getFormat(const B32F_G32F_R32F_A32F * pixels) {
            return enums::texture_format::BGRA;
        }
        
        inline enums::texture_format getFormat(const B8_G8_R8 * pixels) {
            return enums::texture_format::BGR;
        }
        
        inline enums::texture_format getFormat(const B8_G8_R8_A8 * pixels) {
            return enums::texture_format::BGRA;
        }
        
        inline enums::texture_format getFormat(const R32F_G32F_B32F * pixels) {
            return enums::texture_format::RGB;
        }
        
        inline enums::texture_format getFormat(const R32F_G32F_B32F_A32F * pixels) {
            return enums::texture_format::RGBA;
        }
        
        inline enums::texture_format getFormat(const R8_G8_B8 * pixels) {
            return enums::texture_format::RGB;
        }
        
        inline enums::texture_format getFormat(const R8_G8_B8_A8 * pixels) {
            return enums::texture_format::RGBA;
        }
        
        B32F_G32F_R32F * reorder(R32F_G32F_B32F * pixels, const std::size_t count);
        
        R32F_G32F_B32F * reorder(B32F_G32F_R32F * pixels, const std::size_t count);
        
        B32F_G32F_R32F_A32F * reorder(R32F_G32F_B32F_A32F * pixels, const std::size_t count);
        
        R32F_G32F_B32F_A32F * reorder(B32F_G32F_R32F_A32F * pixels, const std::size_t count);
        
        B8_G8_R8 * reorder(R8_G8_B8 * pixels, const std::size_t count);
        
        R8_G8_B8 * reorder(B8_G8_R8 * pixels, const std::size_t count);
        
        B8_G8_R8_A8 * reorder(R8_G8_B8_A8 * pixels, const std::size_t count);
        
        R8_G8_B8_A8 * reorder(B8_G8_R8_A8 * pixels, const std::size_t count);
        
        void reorder(R32F_G32F_B32F * dst, const B32F_G32F_R32F * src, const std::size_t count);
        
        void reorder(B32F_G32F_R32F * dst, const R32F_G32F_B32F * src, const std::size_t count);
        
        void reorder(R32F_G32F_B32F_A32F * dst, const B32F_G32F_R32F_A32F * src, const std::size_t count);
        
        void reorder(B32F_G32F_R32F_A32F * dst, const R32F_G32F_B32F_A32F * src, const std::size_t count);
        
        void reorder(R8_G8_B8 * dst, const B8_G8_R8 * src, const std::size_t count);
        
        void reorder(B8_G8_R8 * dst, const R8_G8_B8 * src, const std::size_t count);
        
        void reorder(R8_G8_B8_A8 * dst, const B8_G8_R8_A8 * src, const std::size_t count);
        
        void reorder(B8_G8_R8_A8 * dst, const R8_G8_B8_A8 * src, const std::size_t count);
    }
}