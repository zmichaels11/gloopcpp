/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   masked_image_renderer.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 3:56 PM
 */

#pragma once

#include <memory>

#include "gloop.hpp"

#include "../renderer.hpp"

namespace glgfx {
    namespace renderers {
        class masked_image_renderer : public glgfx::renderer {
        public:
            static constexpr unsigned int BATCH_SIZE = 64;
            const static bool& USE_BINDLESS;
            static masked_image_renderer * getInstance();
            
        private:
            struct buffer_data_t {
                std::unique_ptr<gloop::buffer> _verts;
                std::unique_ptr<gloop::buffer> _vInstance;
                std::unique_ptr<gloop::vertex_array> _vao;
                
                buffer_data_t();
            } _bufferData;
            
            struct bindless_draw_data {
                gloop::vec4 imgUVs;
                gloop::vec4 maskUVs;
                gloop::mat4 mvp;
                gloop::uint64_t image;
                gloop::uint64_t mask;
            };
            
            std::unique_ptr<bindless_draw_data[]> _bindlessData;
            
            struct draw_data {
                gloop::vec4 imgUVs;
                gloop::vec4 maskUVs;
                gloop::mat4 mvp;                
            };
            gloop::texture2D * _currentImage;
            gloop::texture2D * _currentMask;
            
            std::unique_ptr<draw_data[]> _drawData;
            
            unsigned int _imageCount;
            
            void streamDraw();
            
            void bindlessStreamDraw();
            
        public:
            struct masked_image {
                gloop::vec4 imgUVs;
                gloop::vec4 maskUVs;
                gloop::mat4 mvp;
                gloop::texture2D * image;
                gloop::texture2D * mask;
            };
            
            masked_image_renderer();
            
            virtual void flush() override;
            
            virtual void draw(const masked_image& drawCall);
            
            virtual void reset() override;
        };
    }
}
