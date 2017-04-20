/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pixel_type.hpp
 * Author: zmichaels
 *
 * Created on April 20, 2017, 9:00 AM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class pixel_type : gloop::enum_t {
            UINT8 = 0x1401,            
            FLOAT32 = 0x1406
        };
    }
}