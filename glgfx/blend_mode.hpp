/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   blend_mode.hpp
 * Author: zmichaels
 *
 * Created on April 21, 2017, 2:56 PM
 */

#pragma once

namespace glgfx {
    enum class blend_mode {
        NORMAL,
        PREMULTIPLIED,
        NONE,
        LAYER,
        DARKEN,
        MULTIPLY,
        MULTIPLY_ADD,
        LIGHTEN,
        SCREEN,
        OVERLAY,
        HARDLIGHT,
        LINEAR_DODGE,
        ADD,
        SUBTRACT,
        DIFFERENCE,
        INVERT,
        ALPHA,
        EASE,
        MIN,
        MAX
    };
}