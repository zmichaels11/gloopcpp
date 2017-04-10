/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_wrap.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 11:03 AM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class texture_wrap : gloop::enum_t {
            CLAMP_TO_EDGE = 0x812F,
            MIRRORED_REPEAT = 0x8370,
            REPEAT = 0x2901
        };
    }
}