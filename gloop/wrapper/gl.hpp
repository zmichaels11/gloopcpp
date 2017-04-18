/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gl.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 3:54 PM
 */

#pragma once

#include <cstring>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        constexpr gloop::enum_t TRUE = 1;
        constexpr gloop::enum_t FALSE = 0;
        constexpr gloop::enum_t NO_ERROR = 0;
        constexpr gloop::enum_t INVALID_ENUM = 0x0500;
        constexpr gloop::enum_t INVALID_VALUE = 0x501;
        constexpr gloop::enum_t INVALID_OPERATION = 0x0502;
        constexpr gloop::enum_t OUT_OF_MEMORY = 0x0505;
        constexpr gloop::enum_t INVALID_FRAMEBUFFER_OPERATION = 0x0506;
        constexpr gloop::enum_t FLOAT = 0x1406;
        constexpr gloop::enum_t INT = 0x1404;
        constexpr gloop::enum_t UNSIGNED_INT = 0x1405;
        constexpr gloop::enum_t UNSIGNED_BYTE = 0x1401;
        constexpr gloop::enum_t INFO_LOG_LENGTH = 0x8B84;
        constexpr gloop::enum_t COMPILE_STATUS = 0x8B81;
        constexpr gloop::enum_t LINK_STATUS = 0x8B82;
        constexpr gloop::enum_t INVALID_INDEX = 0xFFFFFFFF;
        constexpr gloop::enum_t BLEND = 0x0BE2;
        constexpr gloop::enum_t SCISSOR = 0x0C11;
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
        constexpr gloop::enum_t VENDOR = 0x1F00;
        constexpr gloop::enum_t RENDERER = 0x1F01;
        constexpr gloop::enum_t VERSION = 0x1F02;
        constexpr gloop::enum_t EXTENSIONS = 0x1F03;

        gloop::enum_t getError();

        const gloop::ubyte_t * getString(gloop::enum_t param);

        void init();
                
        inline bool hasExtension(const char * ext) {
            const auto extensions = reinterpret_cast<const char *> (getString(EXTENSIONS));
            
            return std::strstr(extensions, ext);
        }
    }
}