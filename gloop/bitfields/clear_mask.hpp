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

#include <GL/glew.h>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        enum class clear_mask : gloop::bitfield_t {
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
    }
}