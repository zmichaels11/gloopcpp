/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphics.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 4:57 PM
 */

#pragma once

#include <functional>
#include <memory>
#include <queue>

#include "../gloop/matrices.hpp"

namespace gloop {
    class framebuffer;
    namespace states {
        class viewport;
    }
}

namespace glgfx {
    enum class blend_mode : unsigned int;
    class renderer;
    class sprite;

    class graphics {
    private:
        std::queue<std::function<void()>> _drawCommands;
        
        renderer * _currentRenderer;
        blend_mode _currentBlendMode;

        gloop::framebuffer * _surface;
        std::unique_ptr<gloop::states::viewport> _viewport;

        template<class T>
        T * switchRenderer(T * r);

    public:
        graphics(gloop::framebuffer * surface, const gloop::states::viewport& viewport);

        ~graphics();

        blend_mode getBlendMode();                
        
        void clear();
        
        void clear(const gloop::vec4& color);
        
        void clearRect(const gloop::vec4& color, int x, int y, unsigned int width, unsigned int height);

        void setBlendMode(blend_mode blend);

        void drawSprite(sprite& sprite);

        void drawLine(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& p0, const gloop::vec2& p1);

        void drawRect(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& pos, const gloop::vec2& size);

        void drawTriangle(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& p0, const gloop::vec2& p1, const gloop::vec2& p2);

        void fillRect(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& pos, const gloop::vec2& size);

        void fillTriangle(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& p0, const gloop::vec2& p1, const gloop::vec2& p2);

        void flush();

        void dispose();
    };
}