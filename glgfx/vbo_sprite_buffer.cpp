/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vbo_sprite_buffer.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <cstddef>
#include <cstring>
#include <string>

#include "../gloop/buffer.hpp"
#include "../gloop/draw_calls.hpp"
#include "../gloop/gl_traits.hpp"
#include "../gloop/glint.hpp"
#include "../gloop/enums.hpp"
#include "../gloop/matrices.hpp"
#include "../gloop/objects.hpp"
#include "../gloop/uniforms.hpp"
#include "../gloop/tools.hpp"

#include "blend_mode.hpp"
#include "sprite.hpp"

const bool & glgfx::vbo_sprite_buffer::USE_BINDLESS = gloop::texture2D::FEATURES.bindless;

namespace glgfx {
    namespace {

        static const gloop::vertex_attributes& getAttributes() {
            static gloop::vertex_attributes _attribs;
            static bool isInit = false;

            if (!isInit) {
                _attribs.setLocation("vPos", 0);
                _attribs.setLocation("vMvp0", 1);
                _attribs.setLocation("vMvp1", 2);
                _attribs.setLocation("vMvp2", 3);
                _attribs.setLocation("vMvp3", 4);
                _attribs.setLocation("vUVs", 5);
                _attribs.setLocation("vCTr0", 6);
                _attribs.setLocation("vCTr1", 7);
                _attribs.setLocation("vCTr2", 8);
                _attribs.setLocation("vCTr3", 9);
                _attribs.setLocation("vCo", 10);
                _attribs.setLocation("vIgnoreCT", 11);

                if (gloop::texture2D::FEATURES.bindless) {                    
                    _attribs.setLocation("vImage", 12);
                }

                isInit = true;
            }

            return _attribs;
        }                

        static void bindTexture(const gloop::texture2D * texture) {
            static gloop::program program;
            static gloop::uniform::uniform_int_binding textureBind;

            if (!program) {
                program.setVertexAttributes(getAttributes());

                std::string file;

                if (gloop::isGLES2) {
                    file = "glgfx/shaders/ES2_vbo_sprite_buffer";                
                } else if (gloop::texture2D::FEATURES.bindless) {
                    file = "glgfx/shaders/vbo_sprite_buffer_bindless";
                } else {
                    file = "glgfx/shaders/vbo_sprite_buffer";
                }

                gloop::shader shaders[]{
                    gloop::shader::makeVertexShader(file + ".vert"),
                    gloop::shader::makeFragmentShader(file + ".frag")
                };

                program.linkShaders(shaders, 2);

                if (!vbo_sprite_buffer::USE_BINDLESS) {                    
                    textureBind = program.getUniformIntBinding("spritesheet", 0);
                }
            }

            program.use();

            if (!vbo_sprite_buffer::USE_BINDLESS) {
                textureBind();
                texture->bind(0);
            }
        }
    }

    vbo_sprite_buffer::vbo_sprite_buffer() {
        if (USE_BINDLESS) {
            _bindlessDrawData = std::make_unique < bindless_draw_data[]> (BATCH_SIZE);
        } else {
            _drawData = std::make_unique < draw_data[]> (BATCH_SIZE);
        }

        _spriteCount = 0;
        _currentBlendMode = blend_mode::NORMAL;
        _currentTexture = nullptr;
    }

    vbo_sprite_buffer::buffer_data_t::buffer_data_t() {
        gloop::buffer * verts = new gloop::buffer;
        gloop::buffer * vInstance = new gloop::buffer;

        constexpr auto bind_stride = sizeof (vbo_sprite_buffer::draw_data);
        constexpr auto bindless_stride = sizeof (vbo_sprite_buffer::bindless_draw_data);
        constexpr auto vec4_size = 4 * sizeof (gloop::float_t);
        constexpr auto vec2_size = 2 * sizeof (gloop::float_t);
        constexpr auto bind_buffer_size = bind_stride * BATCH_SIZE;
        constexpr auto bindless_buffer_size = bindless_stride * BATCH_SIZE;        
        
        const auto stride = USE_BINDLESS ? bindless_stride : bind_stride;
        const auto buffer_size = USE_BINDLESS ? bindless_buffer_size : bind_buffer_size;                

        verts->allocate(gloop::enums::buffer_target::ARRAY, std::array<float, 8>{0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 1.0F, 1.0F});
        vInstance->allocate(gloop::enums::buffer_target::ARRAY, buffer_size, gloop::enums::buffer_storage_hint::STREAM_DRAW);

        auto attribs = getAttributes();

        gloop::vertex_array * vao = new gloop::vertex_array;

        int off = 0;

        vao->addBinding(attribs["vPos"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC2));

        vao->addBinding(attribs["vMvp0"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;
        vao->addBinding(attribs["vMvp1"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;
        vao->addBinding(attribs["vMvp2"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;
        vao->addBinding(attribs["vMvp3"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;

        vao->addBinding(attribs["vUVs"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;

        vao->addBinding(attribs["vCTr0"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;
        vao->addBinding(attribs["vCTr1"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;
        vao->addBinding(attribs["vCTr2"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;
        vao->addBinding(attribs["vCTr3"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;

        vao->addBinding(attribs["vCo"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
        off += vec4_size;

        vao->addBinding(attribs["vIgnoreCT"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::FLOAT, stride, off, 1));
        off += vec2_size;

        if (USE_BINDLESS) {
            vao->addBinding(attribs["vImage"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::UVEC2, stride, off, 1));
        }

        _verts.reset(verts);
        _vInstance.reset(vInstance);
        _vao.reset(vao);
    }

    void vbo_sprite_buffer::bindlessStreamDraw() {
        auto instanceSize = sizeof (bindless_draw_data) * this->_spriteCount;

        this->_bufferData._vInstance->reallocate();
        this->_bufferData._vInstance->setData(0, instanceSize, _bindlessDrawData.get());

        gloop::draw::arrays_instanced drawCall;
        drawCall.count = 4;
        drawCall.drawMode = gloop::draw::mode::TRIANGLE_STRIP;
        drawCall.first = 0;
        drawCall.primitiveCount = this->_spriteCount;

        this->_bufferData._vao->bind();

        drawCall();

        this->_spriteCount = 0;
    }

    void vbo_sprite_buffer::streamDraw() {
        auto instanceSize = sizeof (draw_data) * this->_spriteCount;

        this->_bufferData._vInstance->reallocate();
        this->_bufferData._vInstance->setData(0, instanceSize, _drawData.get());

        gloop::draw::arrays_instanced drawCall;
        drawCall.count = 4;
        drawCall.drawMode = gloop::draw::mode::TRIANGLE_STRIP;
        drawCall.first = 0;
        drawCall.primitiveCount = this->_spriteCount;

        this->_bufferData._vao->bind();

        drawCall();

        this->_spriteCount = 0;
    }

    void vbo_sprite_buffer::flush() {
        if (this->_spriteCount == 0) {
            return;
        } else if (this->_currentTexture == nullptr) {
            std::cout << "WARN: Attempted to flush vbo_sprite_buffer without specifying any textures!" << std::endl;
            return;
        }

        bindTexture(this->_currentTexture);
        apply(this->_currentBlendMode);
        
        if (gloop::texture2D::FEATURES.bindless) {            
            this->bindlessStreamDraw();
        } else {
            this->streamDraw();
        }
    }

    bool vbo_sprite_buffer::isSupported() const {
        return true;
    }

    void vbo_sprite_buffer::reset() {
        this->_currentBlendMode = blend_mode::NORMAL;
        this->_currentTexture = nullptr;
        this->_spriteCount = 0;
    }

    void vbo_sprite_buffer::draw(sprite& s) {
        if (!USE_BINDLESS && this->_currentTexture != nullptr && this->_currentTexture != s.textureData->texture) {
            this->flush();
        }

        if (this->_currentBlendMode != s.blendMode) {
            this->flush();
        }

        if (this->_spriteCount == BATCH_SIZE - 1) {
            this->flush();
        }

        this->_currentTexture = s.textureData->texture;
        this->_currentBlendMode = s.blendMode;

        if (USE_BINDLESS) {
            bindless_draw_data * data = this->_bindlessDrawData.get() + this->_spriteCount;

            data->vMvp = s.transformation;

            data->vUVs[0] = s.textureData->u0;
            data->vUVs[1] = s.textureData->v0;
            data->vUVs[2] = s.textureData->u1;
            data->vUVs[3] = s.textureData->v1;

            {
                static gloop::vec4 identityCO{0.0F, 0.0F, 0.0F, 0.0F};

                //TODO: implement
                
                data->vCTr = gloop::matrices::identity4F();
                data->vCo = identityCO;
            }

            if (s.hasColorTransform) {                                    
                data->vIgnoreCT = gloop::vec2 {0.0F, 0.0F};
            } else {
                data->vIgnoreCT = gloop::vec2 {1.0F, 1.0F};
            }

            data->texture = s.textureData->texture->getHandle();            
        } else {
            draw_data * data = this->_drawData.get() + this->_spriteCount;

            data->vMvp = s.transformation;

            data->vUVs[0] = s.textureData->u0;
            data->vUVs[1] = s.textureData->v0;
            data->vUVs[2] = s.textureData->u1;
            data->vUVs[3] = s.textureData->v1;

            {
                static gloop::vec4 identityCO{0.0F, 0.0F, 0.0F, 0.0F};

                data->vCTr = gloop::matrices::identity4F();
                data->vCo = identityCO;
            }

            if (s.hasColorTransform) {
                //TODO: implement                    
                data->vIgnoreCT = gloop::vec2 {0.0F, 0.0F};
            } else {
                data->vIgnoreCT = gloop::vec2 {1.0F, 1.0F};
            }
        }

        this->_spriteCount++;
    }
    
    vbo_sprite_buffer * vbo_sprite_buffer::getInstance() {
        static std::unique_ptr<vbo_sprite_buffer> _instance;
        
        if (!_instance) {
            _instance.reset(new vbo_sprite_buffer);
        }
        
        return _instance.get();
    }
}