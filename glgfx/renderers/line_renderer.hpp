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

#include "../renderer.hpp"

namespace gloop {
    class buffer;
    class vertex_array;
}

namespace glgfx {
    namespace renderers {
        class line_renderer : public glgfx::renderer {
        public:
            static constexpr unsigned int BATCH_SIZE = 256;
            static line_renderer* getInstance();
                    
        private:
            struct buffer_data_t {
                std::unique_ptr<gloop::vertex_array> _vao;
                std::unique_ptr<gloop::buffer> _verts;
                std::unique_ptr<gloop::buffer> _vInstance;
                
                buffer_data_t();
            } _bufferData;
        public:
            struct line_draw {
                gloop::vec2 start;
                gloop::vec2 end;
                gloop::vec4 color;
                gloop::mat4 mvp;
            };
            
        private:
            std::unique_ptr<line_draw[]> _drawData;
            unsigned int _lineCount;
            
            void streamDraw();
            
        public:
            line_renderer();
            
            virtual void flush();
            
            void draw(const line_draw& drawCall);
            
            virtual void reset();
        };
    }
}