/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sprite.hpp
 * Author: zmichaels
 *
 * Created on April 21, 2017, 3:58 PM
 */

#pragma once

#include "../gloop/texture2D.hpp"

#include "blend_mode.hpp"

namespace glgfx {
    struct sprite_frame {
        struct size {
            float width;
            float height;
        };
        
        virtual const size& getSize() const = 0;
        
        struct offset {
            float x;
            float y;
        };
        
        virtual const offset& getOffset() const = 0;
        
        struct uvs {
            float u0;
            float v0;
            float u1;
            float v1;
        };
        
        virtual const uvs& getUVs() = 0;
        
        virtual gloop::texture2D * getTexture() const = 0;
    };
    
    struct sprite_instance {
        virtual const sprite_frame * getSpriteFrame() const = 0;
        
        virtual const float * getTransformation() const = 0;
        
        virtual const float * getColorTransform() const = 0;
        
        virtual bool hasColorTransform() const = 0;
        
        virtual blend_mode getBlendMode() const = 0;
    };
}