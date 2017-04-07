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
        
        gloop::enum_t getError();
    }
}