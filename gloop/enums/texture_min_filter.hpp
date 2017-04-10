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

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class texture_min_filter : gloop::enum_t {
            NEAREST = 0x2600,
            LINEAR = 0x2601,
            NEAREST_MIPMAP_NEAREST = 0x2700,
            LINEAR_MIPMAP_NEAREST = 0x2701,
            NEAREST_MIPMAP_LINEAR = 0x2702,
            LINEAR_MIPMAP_LINEAR = 0x2703
        };
    }
}