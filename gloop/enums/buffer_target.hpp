/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer_target.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:00 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class buffer_target : gloop::enum_t {
            UNKNOWN = 0,
            ARRAY = 0x8892,
            ELEMENT_ARRAY = 0x8893,
            ATOMIC_COUNTER = 0x92C0,
            COPY_READ = 0x8F36,
            COPY_WRITE = 0x8F37,
            DISPATCH_INDIRECT = 0x90EE,
            DRAW_INDIRECT = 0x8F3F,
            PIXEL_PACK = 0x88EB,
            PIXEL_UNPACK = 0x88EC,
            QUERY = 0x9192,
            SHADER_STORAGE = 0x90D2,
            TEXTURE = 0x8C2A,
            TRANSFORM_FEEDBACK = 0x8C8E,
            UNIFORM = 0x8A11
        };
        
        std::ostream& operator<<(std::ostream& os, buffer_target enumval);
    }
}
