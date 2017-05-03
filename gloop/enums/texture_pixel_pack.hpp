/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_pixel_pack.hpp
 * Author: zmichaels
 *
 * Created on May 3, 2017, 9:16 AM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class texture_pixel_pack : gloop::enum_t { 
            UINT8 = 0x1401,
            UINT16 = 0x1403,
            UINT32 = 0x1405,
            FLOAT32 = 0x1406
        };
    }
}