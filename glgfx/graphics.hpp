/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphics.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 4:57 PM
 */

#pragma once

#include "../gloop/matrices.hpp"

namespace glgfx {
    enum class blend_mode : unsigned int;
    class renderer;
    class sprite;   
    
    class graphics {
    private:
        renderer * _currentRenderer;
        blend_mode _currentBlendMode;
        
        renderer * switchRenderer(renderer * r);
        
    public:
        graphics();
        
        void drawSprite(sprite& sprite);
        
        void drawLine(const gloop::mat4& mvp, const gloop::vec4& color, float x1, float y1, float x2, float y2);
        
        void flush();
        
        void dispose();
    };
}