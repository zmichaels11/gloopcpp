/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sprite_buffer.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 4:42 PM
 */

#pragma once

namespace glgfx {
    class sprite;
    
    struct sprite_buffer {
        virtual void draw(sprite& s) = 0;
        
        virtual void flush() = 0;
        
        virtual void reset() = 0;
        
        virtual bool isSupported() const = 0;
    };
}