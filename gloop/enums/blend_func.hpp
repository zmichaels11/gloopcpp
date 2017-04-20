/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   blend_func.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:43 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class blend_func : gloop::enum_t {
            UNKNOWN = 0XFFFF,
            ZERO = 0,
            ONE = 1,
            SRC_COLOR = 0x0300,
            ONE_MINUS_SRC_COLOR = 0x0301,
            DST_COLOR = 0x0306,
            ONE_MINUS_DST_COLOR = 0x0307,
            SRC_ALPHA = 0x0302,
            ONE_MINUS_SRC_ALPHA = 0x0303,
            DST_ALPHA = 0x0304,
            ONE_MINUS_DST_ALPHA = 0x0305,
            CONSTANT_COLOR = 0x8001,
            ONE_MINUS_CONSTANT_COLOR = 0x8002,
            CONSTANT_ALPHA = 0x8003,
            ONE_MINUS_CONSTANT_ALPHA = 0x8004
        };
        
        inline std::ostream& operator<<(std::ostream& os, blend_func enumval) {
            switch (enumval) {
                case blend_func::ZERO:
                    os << "ZERO";
                    break;
                case blend_func::ONE:
                    os << "ONE";
                    break;
                case blend_func::SRC_COLOR:
                    os << "SRC_COLOR";
                    break;
                case blend_func::ONE_MINUS_SRC_COLOR:
                    os << "ONE_MINUS_SRC_COLOR";
                    break;
                case blend_func::DST_COLOR:
                    os << "DST_COLOR";
                    break;
                case blend_func::ONE_MINUS_DST_COLOR:
                    os << "ONE_MINUS_DST_COLOR";
                    break;
                case blend_func::SRC_ALPHA:
                    os << "SRC_ALPHA";
                    break;
                case blend_func::ONE_MINUS_SRC_ALPHA:
                    os << "ONE_MINUS_SRC_ALPHA";
                    break;
                case blend_func::DST_ALPHA:
                    os << "DST_ALPHA";
                    break;
                case blend_func::ONE_MINUS_DST_ALPHA:
                    os << "ONE_MINUS_DST_ALPHA";
                    break;
                case blend_func::CONSTANT_COLOR:
                    os << "CONSTANT_COLOR";
                    break;
                case blend_func::CONSTANT_ALPHA:
                    os << "CONSTANT_ALPHA";
                    break;
                case blend_func::ONE_MINUS_CONSTANT_ALPHA:
                    os << "ONE_MINUS_CONSTANT_ALPHA";
                    break;
                default:
                    os << "UNKNOWN";
                    break;
            }
            
            return os;
        }
    }
}