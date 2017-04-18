/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "framebuffer_attachment.hpp"

#include "../glint.hpp"

namespace gloop {
    namespace enums {
        framebuffer_attachment operator+(framebuffer_attachment attach, gloop::int_t offset) {
            const auto glEnum = static_cast<gloop::int_t> (attach);
            const auto result = glEnum + offset;
            const auto out = static_cast<framebuffer_attachment> (result);
            
            return out;
        }
        
        framebuffer_attachment operator-(framebuffer_attachment attach, gloop::int_t offset) {
            const auto glEnum = static_cast<gloop::int_t> (attach);
            const auto result = glEnum - offset;
            const auto out = static_cast<framebuffer_attachment> (result);
            
            return out;
        }
        
        framebuffer_attachment& operator+= (framebuffer_attachment& attach, gloop::int_t offset) {
            const auto glEnum = static_cast<gloop::int_t> (attach);
            const auto result = glEnum + offset;
            const auto out = static_cast<framebuffer_attachment> (result);
            
            attach = out;
            
            return attach;
        }
        
        framebuffer_attachment& operator-= (framebuffer_attachment& attach, gloop::int_t offset) {
            const auto glEnum = static_cast<gloop::int_t> (attach);
            const auto result = glEnum - offset;
            const auto out = static_cast<framebuffer_attachment> (result);
            
            attach = out;
            
            return attach;
        }
    }
}