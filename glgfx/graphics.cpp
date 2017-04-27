/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "graphics.hpp"

#include "../gloop/matrices.hpp"

#include "blend_mode.hpp"
#include "sprite.hpp"
#include "renderer.hpp"
#include "renderers/sprite_renderer.hpp"
#include "renderers/line_renderer.hpp"

namespace glgfx {
    graphics::graphics() {
        _currentRenderer = nullptr;
    }

    void graphics::dispose() {
        flush();

        _currentRenderer = nullptr;
    }

    void graphics::flush() {
        if (_currentRenderer) {
            _currentRenderer->flush();
        }

        _currentRenderer = glgfx::renderers::sprite_renderer::getInstance();
    }

    renderer * graphics::switchRenderer(renderer* r) {
        if (_currentRenderer != r) {
            if (_currentRenderer) {
                _currentRenderer->flush();
            }

            if (r) {
                r->reset();
            }

            _currentRenderer = r;
        }

        return r;
    }
    
    void graphics::drawLine(const gloop::mat4& mvp, const gloop::vec4& color, float x1, float y1, float x2, float y2) {
        renderers::line_renderer::line_draw lineDrawCall;
        
        lineDrawCall.mvp = mvp;
        lineDrawCall.color = color;
        lineDrawCall.start = gloop::vec2{x1, y1};
        lineDrawCall.end = gloop::vec2{x2, y2};
        
        renderers::line_renderer * r = reinterpret_cast<renderers::line_renderer*> (switchRenderer(renderers::line_renderer::getInstance()));
        
        r->draw(lineDrawCall);
    }
    
    void graphics::drawSprite(sprite& sprite) {
        renderers::sprite_renderer * r = reinterpret_cast<renderers::sprite_renderer*> (switchRenderer(renderers::sprite_renderer::getInstance()));
        
        r->draw(sprite);
    }
}