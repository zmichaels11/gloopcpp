/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sprite_renderer.hpp"

#include "../../gloop/exception/invalid_operation_exception.hpp"
#include "../../gloop/gloop_throw.hpp"

#include "../sprite_buffer.hpp"
#include "../sprite_buffers/vbo_sprite_buffer.hpp"

namespace glgfx {
    namespace renderers {
        sprite_buffer * sprite_renderer::getSpriteBuffer() {
            static sprite_buffer * _buffer;
            
            if (!_buffer) {
                auto vboSpriteBuffer = glgfx::sprite_buffers::vbo_sprite_buffer::getInstance();
                
                if (vboSpriteBuffer->isSupported()) {
                    _buffer = vboSpriteBuffer;
                } else {
                    gloop_throw(gloop::exception::invalid_operation_exception("No sprite buffers are supported!"));
                }
            }
            
            return _buffer;
        }
        
        sprite_renderer * sprite_renderer::getInstance() {
            static std::unique_ptr<sprite_renderer> _instance;
            
            if (!_instance) {
                _instance.reset(new sprite_renderer);
            }
            
            return _instance.get();
        }
        
        void sprite_renderer::flush() {
            getSpriteBuffer()->flush();
        }
        
        void sprite_renderer::draw(glgfx::sprite& sprite) {
            getSpriteBuffer()->draw(sprite);
        }
        
        void sprite_renderer::reset() {
            getSpriteBuffer()->reset();
        }
    }
}