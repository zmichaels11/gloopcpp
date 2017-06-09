/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vbo_sprite_buffer.hpp
 * Author: zmichaels
 *
 * Created on April 24, 2017, 4:20 PM
 */

#pragma once

#include <array>
#include <memory>

#include "gloop.hpp"

#include "../sprite_buffer.hpp"

namespace glgfx {
    enum class blend_mode : unsigned int;
    class sprite;

    namespace sprite_buffers {

        class vbo_sprite_buffer : public glgfx::sprite_buffer {
        public:
            constexpr static unsigned int BATCH_SIZE = 256;
            const static bool& USE_BINDLESS;

            static vbo_sprite_buffer * getInstance();
        private:

            struct buffer_data_t {
                std::unique_ptr<gloop::buffer> _verts;
                std::unique_ptr<gloop::buffer> _vInstance;
                std::unique_ptr<gloop::vertex_array> _vao;

                buffer_data_t();
            } _bufferData;

            struct draw_data {
                gloop::mat4 vMvp;
                gloop::vec4 vUVs;
                gloop::mat4 vCTr;
                gloop::vec4 vCo;
                gloop::vec2 vIgnoreCT;
            };

            struct bindless_draw_data {
                gloop::mat4 vMvp;
                gloop::vec4 vUVs;
                gloop::mat4 vCTr;
                gloop::vec4 vCo;
                gloop::vec2 vIgnoreCT;
                gloop::uint64_t texture;
            };

            //NOTE: this can't be union :/
            std::unique_ptr<draw_data[] > _drawData;
            std::unique_ptr<bindless_draw_data[] > _bindlessDrawData;

            unsigned int _spriteCount;
            blend_mode _currentBlendMode;
            const gloop::texture2D * _currentTexture;

            void streamDraw();
            void bindlessStreamDraw();

        public:
            vbo_sprite_buffer();

            virtual void draw(sprite& s) override;

            virtual void flush() override;

            virtual void reset() override;

            virtual bool isSupported() const override;
        };
    }
}
