/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sprite_renderer.hpp
 * Author: zmichaels
 *
 * Created on April 21, 2017, 3:07 PM
 */

#pragma once

#include "sprite.hpp"

namespace glgfx {
    struct sprite_renderer {        
        
        virtual void draw(const sprite_instance * sprite) = 0;
        
        virtual void flush() = 0;
        
        virtual void reset() = 0;
        
        virtual bool isSupported() const = 0;
    };
}