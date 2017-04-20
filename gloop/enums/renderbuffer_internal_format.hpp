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

#include <iostream>

#include "../glint.hpp"

namespace gloop {

    namespace enums {

        enum class renderbuffer_internal_format : gloop::enum_t {
            UNKNOWN = 0,
            DEPTH16 = 0x81A5,
            R4_G4_B4_A4 = 0x8056,
            R5_G5_B5_A1 = 0x8057,
            R5_G6_B5 = 0x8D62,
            STENCIL_INDEX8 = 0x8D48
        };
        
        inline std::ostream& operator<<(std::ostream& os, renderbuffer_internal_format enumval) {
            switch (enumval) {
                case renderbuffer_internal_format::DEPTH16:
                    os << "DEPTH16";
                    break;
                case renderbuffer_internal_format::R4_G4_B4_A4:
                    os << "R4_G4_B4_A4";
                    break;
                case renderbuffer_internal_format::R5_G6_B5:
                    os << "R5_G6_R5";
                    break;
                case renderbuffer_internal_format::R5_G5_B5_A1:
                    os << "R5_G5_B5_A1";
                    break;
                case renderbuffer_internal_format::STENCIL_INDEX8:
                    os << "STENCIL_INDEX8";
                    break;
                default:
                    os << "UNKNOWN";
                    break;
            }
            
            return os;
        }
    }
}