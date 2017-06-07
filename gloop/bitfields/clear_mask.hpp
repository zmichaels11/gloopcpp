/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clear_mask.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 11:03 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        enum class clear_mask : gloop::bitfield_t {
            NONE = 0,
            COLOR = 0x00004000,
            DEPTH = 0x00000100,
            STENCIL = 0x00000400
        };
        
        clear_mask operator~(clear_mask);
        clear_mask operator|(clear_mask, clear_mask);
        clear_mask operator^(clear_mask, clear_mask);
        clear_mask operator&(clear_mask, clear_mask);
        clear_mask& operator|=(clear_mask&, clear_mask);
        clear_mask& operator^=(clear_mask&, clear_mask);
        clear_mask& operator&=(clear_mask&, clear_mask);
        
        constexpr bool hasFlag(clear_mask lhs, clear_mask rhs) {
            return (static_cast<gloop::bitfield_t> (lhs) & static_cast<gloop::bitfield_t> (rhs));
        }       

        std::ostream& operator<< (std::ostream& os, clear_mask m);
    }
}
