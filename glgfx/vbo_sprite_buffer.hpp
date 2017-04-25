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
        constexpr static unsigned int BUFFER_COUNT = 3;
        constexpr static unsigned int BATCH_SIZE = 256;
    private:

        struct buffer_data_t {
            std::unique_ptr<gloop::buffer> _verts;
            std::unique_ptr<gloop::buffer> _vInstance;
            std::unique_ptr<gloop::vertex_array> _vao;

            buffer_data_t();
        } _bufferData[BUFFER_COUNT];

        struct draw_data_t {
            std::array<float, 16> vMvp;
            std::array<float, 4> vUVs;
            std::array<float, 16> vCTr;
            std::array<float, 4> vCo;
            float vIgnoreCT;
        } _drawData[BATCH_SIZE];
        unsigned int _currentBuffer;

        unsigned int _spriteCount;
        blend_mode _currentBlendMode;
        const gloop::texture2D * _currentTexture;

        void streamDraw();

    public:
        void draw(const sprite& s);

        void flush();

        void reset();

        bool isSupported() const;
    };
}