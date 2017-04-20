/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_format.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 10:11 AM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class texture_format : gloop::enum_t {
            UNKNOWN = 0,
            RGB = 0x1907,
            RGBA = 0x1908,
            BGR = 0x80E0,
            BGRA = 0x80E1
        };                
    }
}