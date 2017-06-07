/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   blend_eq.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:44 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class blend_eq : gloop::enum_t {
            UNKNOWN = 0,
            ADD = 0x8006,
            SUBTRACT = 0x800A,
            REVERSE_SUBTRACT = 0x800B,
            MIN = 0x8007,
            MAX = 0x8008
        };
        
        std::ostream& operator<<(std::ostream& os, const blend_eq enumval);
    }
}
