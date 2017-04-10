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
        
        void textureParameteri(
                gloop::uint_t texture,
                gloop::enum_t pname,
                gloop::int_t value);

        void textureParameterf(
                gloop::uint_t texture,
                gloop::enum_t pname,
                gloop::float_t value);
    }
}