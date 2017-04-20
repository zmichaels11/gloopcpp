/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   image.hpp
 * Author: zmichaels
 *
 * Created on April 20, 2017, 8:44 AM
 */

#pragma once

#include <memory>

#include "enums/pixel_type.hpp"
#include "enums/texture_format.hpp"
#include "enums/texture_internal_format.hpp"
#include "glint.hpp"

namespace gloop {        
    enum class pixel_type : gloop::enum_t {
        UINT8 = 0x1401,
        FLOAT = 0x1406
    };
    
    struct image2D {
        gloop::sizei_t width;
        gloop::sizei_t height;
        enums::texture_format format;
        enums::texture_internal_format internalFormat;
        enums::pixel_type pixelType;
        
        const void * data;                
    };
}