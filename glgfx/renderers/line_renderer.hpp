/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   line_renderer.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 9:46 AM
 */

#pragma once

#include <memory>

#include "../../gloop/matrices.hpp"

namespace glgfx {
    namespace renderers {
        class line_renderer {
        public:
            struct draw_data_t {
                gloop::vec2 start;
                gloop::vec2 end;
                gloop::vec4 color;
                gloop::mat4 mvp;
            };
            
            std::unique_ptr<draw_data_t[]> _drawData;
            
        };
    }
}