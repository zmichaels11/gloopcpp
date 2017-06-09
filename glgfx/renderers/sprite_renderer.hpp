/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sprite_renderer.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 4:40 PM
 */

#pragma once

#include "gloop.hpp"

#include "../renderer.hpp"

namespace glgfx {
    
	class sprite_buffer;
	class sprite;

    namespace renderers {
        class sprite_renderer : public glgfx::renderer {
        public:
            static sprite_renderer * getInstance();
            
        private:
            sprite_buffer * getSpriteBuffer();
            
        public:            
            virtual void flush();
            
            virtual void reset();
            
            void draw(glgfx::sprite& sprite);
        };
    }
}
