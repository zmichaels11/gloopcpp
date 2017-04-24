/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "context.hpp"

#include <iostream>

namespace gloop {
    context::context(const gloop::sizei_t width, const gloop::sizei_t height, const gloop::double_t near, const gloop::double_t far) {
        
    }

    std::ostream& operator<<(std::ostream& os, const context& ctx) {
        return os << "context: ["
                << "blend: " << ctx.currentBlend
                << ", scissor: " << ctx.currentScissor
                << ", viewport: " << ctx.currentViewport
                << ", clear: " << ctx.currentClear
                << "]";
    }
}