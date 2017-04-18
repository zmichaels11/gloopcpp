/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   framebuffer_target.hpp
 * Author: zmichaels
 *
 * Created on April 18, 2017, 4:06 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class framebuffer_target : gloop::enum_t {
            FRAMEBUFFER = 0x8D40
        };
    }
}