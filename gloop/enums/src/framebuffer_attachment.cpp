/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "framebuffer_attachment.hpp"

#include <iostream>

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

		std::ostream& operator<< (std::ostream& os, framebuffer_attachment enumval) {
			switch (enumval) {
				case framebuffer_attachment::DEPTH_ATTACHMENT:
					return os << "DEPTH_ATTACHMENT";
				case framebuffer_attachment::DEPTH_STENCIL:
					return os << "DEPTH_STENCIL";
				default:
					constexpr auto VAL_COLOR0 = static_cast<gloop::enum_t> (framebuffer_attachment::COLOR0);
					const auto value = static_cast<gloop::enum_t> (enumval);

					if (value < VAL_COLOR0) {
						return os << "UNKNOWN";
					} else {
						return os << "COLOR" << (value - VAL_COLOR0);
					}
			}
		}
    }
}
