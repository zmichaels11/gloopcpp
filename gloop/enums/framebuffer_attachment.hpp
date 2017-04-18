/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   framebuffer_attachment.hpp
 * Author: zmichaels
 *
 * Created on April 18, 2017, 3:15 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        enum class framebuffer_attachment : gloop::enum_t {
            COLOR0 = 0x8CE0,
            COLOR1 = 0x8CE1,
            COLOR2 = 0x8CE2,
            COLOR3 = 0x8CE3,
            DEPTH_ATTACHMENT = 0x8D00,
            DEPTH_STENCIL = 0x821A
        };
        
        framebuffer_attachment operator+(framebuffer_attachment attach, gloop::int_t offset);
        
        framebuffer_attachment operator-(framebuffer_attachment attach, gloop::int_t offset);
        
        framebuffer_attachment& operator+=(framebuffer_attachment& attach, gloop::int_t offset);
        
        framebuffer_attachment& operator-=(framebuffer_attachment& attach, gloop::int_t offset);
    }
}