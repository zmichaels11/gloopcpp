/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture_mag_filter.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 11:02 AM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class texture_mag_filter : gloop::enum_t {
            NEAREST = 0x2600,
            LINEAR = 0x2601
        };
    }
}