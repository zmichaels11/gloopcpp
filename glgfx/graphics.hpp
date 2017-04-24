/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphics.hpp
 * Author: zmichaels
 *
 * Created on April 21, 2017, 2:50 PM
 */

#pragma once

#include <memory>
#include <queue>

#include "../gloop/framebuffer.hpp"

#include "blend_mode.hpp"
#include "draw_command.hpp"
#include "renderer.hpp"

namespace glgfx {

    class graphics {
    public:

        struct surface_size {
            unsigned int width;
            unsigned int height;
        };                

    private:
        surface_size _size;
        const gloop::framebuffer * _surface;
        blend_mode _currentBlendMode;
        std::queue<std::unique_ptr<draw_command>> drawCommands;

        renderer * switchRenderer(renderer * r);

    public:

        graphics(const gloop::framebuffer * framebuffer, const unsigned int width, const unsigned int height) :
        _surface(framebuffer),
        _size({width, height}),
        _currentBlendMode(blend_mode::NORMAL) {
        }

        ~graphics();

        graphics(const graphics&) = delete;

        graphics(graphics&&) = default;

        graphics& operator=(const graphics&) = delete;

        graphics& operator=(graphics&&) = default;

        const surface_size& getSurfaceSize() const;

        void createPixelSpaceProjection(float * mat) const;

        void createTextureSpaceProjection(float * mat) const;

        void createSurfaceSpaceProjection(float * mat) const;

        void setBlendMode(const blend_mode blend);

        blend_mode getBlendMode() const;
        
        void flush();
        
        void dispose();
        
        void clear();
        
        void clear(const color& color);
        
        void clear(const color& color, int x, int y, unsigned int width, unsigned int height);
        
        void draw(const std::unique_ptr<draw_command>& cmd);
    };
}