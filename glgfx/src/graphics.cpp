/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "graphics.hpp"

#include <algorithm>

#include "gloop.hpp"

#include "blend_mode.hpp"
#include "sprite.hpp"
#include "renderer.hpp"
#include "renderers/sprite_renderer.hpp"
#include "renderers/line_renderer.hpp"
#include "renderers/solid_renderer.hpp"

namespace glgfx {

    graphics::graphics() {
        _currentRenderer = renderers::sprite_renderer::getInstance();
        _surface = gloop::framebuffer::getCurrentFramebuffer();
        _viewport = std::make_unique<gloop::states::viewport> (gloop::states::viewport::getCurrentViewport());
    }
    
    graphics::graphics(gloop::framebuffer * surface, const gloop::states::viewport& viewport) {
        _currentRenderer = renderers::sprite_renderer::getInstance();
        _surface = surface;
        _viewport = std::make_unique<gloop::states::viewport> (viewport);
    }

    graphics::~graphics() {
        dispose();
    }

    void graphics::clear() {
        constexpr gloop::vec4 BLACK{0.0F, 0.0F, 0.0F, 1.0F};

        clear(BLACK);
    }

    void graphics::clear(const gloop::vec4& color) {
        auto size = _viewport->getSize();
        auto offset = _viewport->getOffset();

        clearRect(color, offset.x, offset.y, size.width, size.height);
    }

    void graphics::clearRect(const gloop::vec4& color, int x, int y, unsigned int width, unsigned int height) {
        if (_currentRenderer != nullptr) {
            _currentRenderer->flush();
            _currentRenderer = renderers::sprite_renderer::getInstance();
        }

        using scissor_t = gloop::states::scissor;
        using clear_t = gloop::states::clear;

        auto viewSize = _viewport->getSize();
        auto viewOff = _viewport->getOffset();
        auto sx = gloop::int_t(x);
        auto sy = gloop::int_t(viewSize.height - y - height);
        auto sw = gloop::sizei_t(width);
        auto sh = gloop::sizei_t(height);

        scissor_t scissor(true,{sx, sy}, {sw, sh});
        
        clear_t::color clearColor;
        clearColor.red = color[0];
        clearColor.green = color[1];
        clearColor.blue = color[2];
        clearColor.alpha = color[3];
        
        static auto clearMask = gloop::bitfields::clear_mask::COLOR | gloop::bitfields::clear_mask::DEPTH;            
        
        clear_t clear(clearMask, clearColor, 1.0, 0);
        
        
        scissor_t::push();            
        scissor();                        
        clear();
        scissor_t::pop();        
    }

    void graphics::setBlendMode(blend_mode blend) {
        
        switchRenderer(renderers::sprite_renderer::getInstance());
        _currentBlendMode = blend;
        apply(blend);
    }

    blend_mode graphics::getBlendMode() {
        return _currentBlendMode;
    }

    void graphics::dispose() {
        flush();

        _currentRenderer = nullptr;
    }

    void graphics::flush() {
        const bool fbChanged = _surface != gloop::framebuffer::getCurrentFramebuffer();
        renderer * defaultRenderer = renderers::sprite_renderer::getInstance();

        if (fbChanged) {
            defaultRenderer->flush();
            gloop::framebuffer::push();
            _surface->bind();
        }

        gloop::states::blend::push();
        apply(blend_mode::NORMAL);

        if (_currentRenderer != defaultRenderer) {
            if (_currentRenderer) {
                _currentRenderer->flush();
            }

            _currentRenderer = defaultRenderer;
        }

        gloop::states::blend::pop();

        if (fbChanged) {
            defaultRenderer->flush();
            gloop::framebuffer::pop();
        }
    }

    template<class T>
    T * graphics::switchRenderer(T * t) {
        auto * r = reinterpret_cast<renderer *> (t);

        if (_currentRenderer != r) {
            if (_currentRenderer) {
                _currentRenderer->flush();
            }

            if (r) {
                r->reset();
            }

            _currentRenderer = r;
        }

        return t;
    }

    template renderers::line_renderer * graphics::switchRenderer<renderers::line_renderer>(renderers::line_renderer *);
    template renderers::solid_renderer * graphics::switchRenderer<renderers::solid_renderer>(renderers::solid_renderer *);
    template renderers::sprite_renderer * graphics::switchRenderer<renderers::sprite_renderer>(renderers::sprite_renderer *);

    void graphics::drawLine(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& p0, const gloop::vec2& p1) {
        using line_renderer_t = renderers::line_renderer;
        using line_t = line_renderer_t::line_draw;

        line_t line;

        line.mvp = mvp;
        line.color = color;
        line.start = p0;
        line.end = p1;

        switchRenderer(line_renderer_t::getInstance())->draw(line);
    }

    void graphics::drawSprite(sprite& sprite) {
        switchRenderer(renderers::sprite_renderer::getInstance())->draw(sprite);
    }

    void graphics::drawRect(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& pos, const gloop::vec2& size) {
        gloop::vec2 p0 = pos;
        gloop::vec2 p1 = gloop::vec2{pos[0] + size[0], pos[1]};
        gloop::vec2 p2 = gloop::vec2{pos[0] + size[0], pos[1] + size[1]};
        gloop::vec2 p3 = gloop::vec2{pos[0], pos[1] + size[1]};

        using line_renderer_t = renderers::line_renderer;
        using line_t = line_renderer_t::line_draw;

        std::array<line_t, 4> lines;

        lines[0].start = p0;
        lines[0].end = p1;

        lines[1].start = p1;
        lines[1].end = p2;

        lines[2].start = p2;
        lines[2].end = p3;

        lines[3].start = p3;
        lines[3].end = p0;

        auto * r = switchRenderer(line_renderer_t::getInstance());

        std::for_each(lines.begin(), lines.end(), [&](line_t & line) {
            line.mvp = mvp;
            line.color = color;
            r->draw(line);
        });
    }

    void graphics::drawTriangle(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& p0, const gloop::vec2& p1, const gloop::vec2& p2) {
        using line_renderer_t = renderers::line_renderer;
        using line_t = line_renderer_t::line_draw;

        std::array<line_t, 3> lines;

        lines[0].start = p0;
        lines[0].end = p1;

        lines[1].start = p1;
        lines[1].end = p2;

        lines[2].start = p2;
        lines[2].end = p0;

        auto * r = switchRenderer(line_renderer_t::getInstance());

        std::for_each(lines.begin(), lines.end(), [&] (line_t & line) {
            line.mvp = mvp;
            line.color = color;
            r->draw(line);
        });
    }

    void graphics::fillRect(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& pos, const gloop::vec2& size) {
        using solid_renderer_t = renderers::solid_renderer;
        using point_t = solid_renderer_t::point;

        auto p0 = pos;
        auto p1 = gloop::vec2{pos[0] + size[0], pos[1]};
        auto p2 = gloop::vec2{pos[0], pos[1] + size[1]};
        auto p3 = gloop::vec2{pos[0] + size[0], pos[1] + size[1]};

        std::array<point_t, 6> points;

        points[0].pos = p0;
        points[1].pos = p1;
        points[2].pos = p2;

        points[3].pos = p1;
        points[4].pos = p2;
        points[5].pos = p3;

        auto * r = switchRenderer(solid_renderer_t::getInstance());

        std::for_each(points.begin(), points.end(), [&] (point_t & point) {
            point.mvp = mvp;
            point.color = color;
            r->draw(point);
        });
    }

    void graphics::fillTriangle(const gloop::mat4& mvp, const gloop::vec4& color, const gloop::vec2& p0, const gloop::vec2& p1, const gloop::vec2& p2) {
        using solid_renderer_t = renderers::solid_renderer;
        using point_t = solid_renderer_t::point;

        std::array<point_t, 3> points;

        points[0].pos = p0;
        points[1].pos = p1;
        points[2].pos = p2;

        auto * r = switchRenderer(solid_renderer_t::getInstance());

        std::for_each(points.begin(), points.end(), [&] (point_t & point) {
            point.mvp = mvp;
            point.color = color;
            r->draw(point);
        });
    }
}
