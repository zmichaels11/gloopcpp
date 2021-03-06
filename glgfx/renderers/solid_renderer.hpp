/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   solid_renderer.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 3:22 PM
 */

#pragma once

#include <memory>

#include "gloop.hpp"

#include "../renderer.hpp"

namespace glgfx {
    namespace renderers {
        class solid_renderer : public glgfx::renderer {
        public:
            static constexpr unsigned int BATCH_SIZE = 96;
            static solid_renderer * getInstance();
            
        private:
            struct buffer_data_t {
                std::unique_ptr<gloop::vertex_array> _vao;
                std::unique_ptr<gloop::buffer> _verts;
                
                buffer_data_t();
            } _bufferData;
            
        public:
            struct point {
                gloop::vec2 pos;
                gloop::vec4 color;
                gloop::mat4 mvp;                
            };
            
        private:
            std::unique_ptr<point[]> _drawData;
            unsigned int _pointCount;
            void streamDraw();
            
        public:
            solid_renderer();
            
            virtual void flush() override;
            
            virtual void draw(const point& drawCall);
            
            virtual void reset() override;
        };
    }
}
