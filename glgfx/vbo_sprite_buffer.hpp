/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vbo_sprite_buffer.hpp
 * Author: zmichaels
 *
 * Created on April 21, 2017, 3:17 PM
 */

#pragma once

#include <array>
#include <vector>

#include "blend_mode.hpp"
#include "sprite.hpp"
#include "sprite_renderer.hpp"

#include "../gloop/buffer.hpp"

#include "../gloop/program.hpp"
#include "../gloop/texture2D.hpp"
#include "../gloop/uniforms.hpp"
#include "../gloop/vertex_array.hpp"

namespace glgfx {

    class vbo_sprite_buffer : public sprite_renderer {
    public:
        constexpr unsigned int BATCH_SIZE = 256;        

    private:

        struct buffer_data_t {
            gloop::buffer _verts;
            gloop::buffer _vInstance;
            gloop::vertex_array _vao;

            buffer_data_t();
        } _data;
        
        struct sprite_data {            
            float transform[16];
            float uvs[4];
            float colorTransform[16];
            float colorOffset[4];
            float ignoreColorTransform;
        };

        gloop::program * _program;
        gloop::uniform::uniform_int_binding _spritesheetBinding;

        std::vector<sprite_data> _spriteCache;
        gloop::texture2D * _currentTexture;
        blend_mode _currentBlendMode;
        void streamDraw();
        void draw(const sprite_data& sprite);

    public:
        vbo_sprite_buffer();

        vbo_sprite_buffer(const vbo_sprite_buffer&) = delete;

        vbo_sprite_buffer(vbo_sprite_buffer&&) = default;

        ~vbo_sprite_buffer() = default;

        vbo_sprite_buffer& operator=(const vbo_sprite_buffer&) = delete;

        vbo_sprite_buffer& operator=(vbo_sprite_buffer&&) = default;

        virtual void draw(const sprite_instance * sprite);

        virtual void flush();

        virtual void reset();

        virtual bool isSupported() const;
    };
}