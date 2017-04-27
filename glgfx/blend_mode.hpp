/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   blend_mode.hpp
 * Author: zmichaels
 *
 * Created on April 24, 2017, 4:17 PM
 */

#pragma once

namespace glgfx {
    enum class blend_mode : unsigned int {
        NORMAL = 0,
        MIN,
        MAX,
        ADD,
        SUBTRACT,
        MULTIPLY,
        MULTIPLY_ADD,
        SCREEN,
        LINEAR_DODGE,
        NONE,
        PRE_MULTIPLIED
    };
    
    void apply(blend_mode);
}