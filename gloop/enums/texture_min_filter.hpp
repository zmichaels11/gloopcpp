/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_min_filter.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 10:59 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class texture_min_filter : gloop::enum_t {
            UNKNOWN = 0,
            NEAREST = 0x2600,
            LINEAR = 0x2601,
            NEAREST_MIPMAP_NEAREST = 0x2700,
            LINEAR_MIPMAP_NEAREST = 0x2701,
            NEAREST_MIPMAP_LINEAR = 0x2702,
            LINEAR_MIPMAP_LINEAR = 0x2703
        };
        
        inline std::ostream& operator<<(std::ostream& os, texture_min_filter enumval) {
            switch (enumval) {
                case texture_min_filter::NEAREST:
                    os << "NEAREST";
                    break;
                case texture_min_filter::LINEAR:
                    os << "LINEAR";
                    break;
                case texture_min_filter::NEAREST_MIPMAP_NEAREST:
                    os << "NEAREST_MIPMAP_NEAREST";
                    break;
                case texture_min_filter::LINEAR_MIPMAP_NEAREST:
                    os << "LINEAR_MIPMAP_NEAREST";
                    break;
                case texture_min_filter::NEAREST_MIPMAP_LINEAR:
                    os << "NEAREST_MIPMAP_LINEAR";
                    break;                
                case texture_min_filter::LINEAR_MIPMAP_LINEAR:
                    os << "LINEAR_MIPMAP_LINEAR";
                    break;
                default:
                    os << "UNKNOWN";
            }
            
            return os;
        }
    }
}