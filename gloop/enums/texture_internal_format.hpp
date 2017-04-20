/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_internal_format.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 10:14 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class texture_internal_format : gloop::enum_t {
            UNKNOWN = 0,
            R8_G8_B8_UNORM = 0x8051,
            R8_G8_B8_A8_UNORM = 0x8058,            
            R32_G32_B32_FLOAT = 0x8815,
            R32_G32_B32_A32_FLOAT = 0x8814
        };
        
        inline std::ostream& operator<<(std::ostream& os, texture_internal_format enumval) {
            switch (enumval) {
                case texture_internal_format::R8_G8_B8_UNORM:
                    os << "R8_G8_B8_UNORM";
                    break;
                case texture_internal_format::R8_G8_B8_A8_UNORM:
                    os << "R8_G8_B8_A8_UNORM";
                    break;
                case texture_internal_format::R32_G32_B32_FLOAT:
                    os << "R32_G32_B32_FLOAT";
                    break;
                case texture_internal_format::R32_G32_B32_A32_FLOAT:
                    os << "R32_G32_B32_A32_FLOAT";
                    break;
                default:
                    os << "UNKNOWN";
                    break;
            }
            
            return os;
        }
    }
}