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

#include "../gloop/glint.hpp"
#include "../gloop/matrices.hpp"

namespace gloop {
    class buffer;
    class texture2D;
    class vertex_array;
}

namespace glgfx {
    enum class blend_mode : unsigned int;
    class sprite;

    class vbo_sprite_buffer {
    public:        
        constexpr static unsigned int BATCH_SIZE = 256;
    private:

        struct buffer_data_t {
            std::unique_ptr<gloop::buffer> _verts;
            std::unique_ptr<gloop::buffer> _vInstance;
            std::unique_ptr<gloop::vertex_array> _vao;

            buffer_data_t();
        } _bufferData;

        struct draw_data_t {
            gloop::mat4 vMvp;
            gloop::vec4 vUVs;
            gloop::mat4 vCTr;
            gloop::vec4 vCo;
            gloop::vec2 vIgnoreCT;            
        };
        
        struct bindless_draw_data_t {
            gloop::mat4 vMvp;
            gloop::vec4 vUVs;
            gloop::mat4 vCTr;
            gloop::vec4 vCo;
            gloop::vec2 vIgnoreCT;             
            gloop::uint64_t texture;
        };
        
        std::unique_ptr<draw_data_t[]> _drawData;
        std::unique_ptr<bindless_draw_data_t[]> _bindlessDrawData;

        unsigned int _spriteCount;
        blend_mode _currentBlendMode;
        const gloop::texture2D * _currentTexture;

        void streamDraw();
        void bindlessStreamDraw();

    public:
        vbo_sprite_buffer();
        
        void draw(sprite& s);

        void flush();

        void reset();

        bool isSupported() const;
    };
}