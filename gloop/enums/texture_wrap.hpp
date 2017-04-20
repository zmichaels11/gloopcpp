/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_wrap.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 11:03 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class texture_wrap : gloop::enum_t {
            UNKNOWN = 0,
            CLAMP_TO_EDGE = 0x812F,
            MIRRORED_REPEAT = 0x8370,
            REPEAT = 0x2901
        };
        
        inline std::ostream& operator<<(std::ostream& os, texture_wrap enumval) {
            switch (enumval) {
                case texture_wrap::CLAMP_TO_EDGE:
                    os << "CLAMP_TO_EDGE";
                    break;
                case texture_wrap::MIRRORED_REPEAT:
                    os << "MIRRORED_REPEAT";
                    break;
                case texture_wrap::REPEAT:
                    os << "REPEAT";
                    break;
                default:
                    os << "UNKNOWN";
                    break;
            }
            
            return os;
        }
    }
}