/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   renderbuffer_format.hpp
 * Author: zmichaels
 *
 * Created on April 18, 2017, 3:04 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {

    namespace enums {

        enum class renderbuffer_internal_format : gloop::enum_t {
            DEPTH16 = 0x81A5,
            R4_G4_B4_A4 = 0x8056,
            R5_G5_B5_A1 = 0x8057,
            R5_G6_B5 = 0x8D62,
            STENCIL_INDEX8 = 0x8D48
        };
    }
}