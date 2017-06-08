/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "masked_image_renderer.hpp"

#include <iostream>
#include <memory>

#include "../../gloop/gl_traits.hpp"
#include "../../gloop/buffer.hpp"
#include "../../gloop/draw/arrays_instanced.hpp"
#include "../../gloop/enums/buffer_storage_hint.hpp"
#include "../../gloop/enums/buffer_target.hpp"
#include "../../gloop/enums/vertex_attribute_type.hpp"
#include "../../gloop/program.hpp"
#include "../../gloop/shader.hpp"
#include "../../gloop/texture2D.hpp"
#include "../../gloop/uniform/uniform_int_binding.hpp"
#include "../../gloop/vertex_array.hpp"
#include "../../gloop/vertex_attribute_binding.hpp"
#include "../../gloop/vertex_attributes.hpp"

const bool& glgfx::renderers::masked_image_renderer::USE_BINDLESS = gloop::texture2D::FEATURES.bindless;

namespace glgfx {
    namespace renderers {

        static const gloop::vertex_attributes& getAttributes() {
            static gloop::vertex_attributes _attribs;
            static bool isInit = false;

            if (!isInit) {
                _attribs.setLocation("vPos", 0);
                _attribs.setLocation("vImageUVs", 1);
                _attribs.setLocation("vMaskUVs", 2);
                _attribs.setLocation("vMvp0", 3);
                _attribs.setLocation("vMvp1", 4);
                _attribs.setLocation("vMvp2", 5);
                _attribs.setLocation("vMvp3", 6);

                if (masked_image_renderer::USE_BINDLESS) {
                    _attribs.setLocation("vImage", 7);
                    _attribs.setLocation("vMask", 8);
                }
            }

            return _attribs;
        }

        static void bindTexture(gloop::texture2D * image, gloop::texture2D * mask) {
            static gloop::program _program;
            static gloop::uniform::uniform_int_binding _bindImage, _bindMask;

            if (!_program) {
                _program.setVertexAttributes(getAttributes());

                std::string file;

                if (gloop::isGLES2()) {
                    file = "glgfx/shaders/ES2_masked_image_renderer";
				} else if (gloop::isGLES3()) {
					file = "glgfx/shaders/ES3_masked_image_renderer";
                } else if (masked_image_renderer::USE_BINDLESS) {
                    file = "glgfx/shaders/masked_image_renderer_bindless";
                } else {
                    file = "glgfx/shaders/masked_image_renderer";
                }

                gloop::shader shaders[]{
                    gloop::shader::makeVertexShader(file + ".vert"),
                    gloop::shader::makeFragmentShader(file + ".frag")
                };

                _program.linkShaders(shaders, 2);

                if (masked_image_renderer::USE_BINDLESS) {
                    _bindImage = _program.getUniformIntBinding("image", 0);
                    _bindMask = _program.getUniformIntBinding("mask", 1);
                }
            }

            _program.use();

            if (!masked_image_renderer::USE_BINDLESS) {
                image->bind(0);
                mask->bind(1);
                _bindImage();
                _bindMask();
            }
        }

        masked_image_renderer::masked_image_renderer() {
            if (USE_BINDLESS) {
                _bindlessData = std::make_unique < bindless_draw_data[]> (BATCH_SIZE);
            } else {
                _drawData = std::make_unique < draw_data[]> (BATCH_SIZE);
            }

            _imageCount = 0;
            _currentImage = nullptr;
            _currentMask = nullptr;
        }

        masked_image_renderer::buffer_data_t::buffer_data_t() {
            gloop::buffer * verts = new gloop::buffer;

            verts->allocate(gloop::enums::buffer_target::ARRAY, std::array<float, 8>{0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 1.0F, 1.0F});

            gloop::buffer * vInstance = new gloop::buffer;
            gloop::vertex_array * vao = new gloop::vertex_array;

            auto attribs = getAttributes();

            vao->addBinding(attribs["vPos"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC2));

            int off = 0;

            constexpr auto bindless_stride = sizeof (bindless_draw_data);
            constexpr auto bindless_buffer_size = bindless_stride * BATCH_SIZE;
            constexpr auto bind_stride = sizeof (draw_data);
            constexpr auto bind_buffer_size = bind_stride * BATCH_SIZE;
            constexpr auto vec4_size = 4 * sizeof (gloop::float_t);
            constexpr auto tex_handle_size = sizeof (gloop::uint64_t);
            const auto stride = USE_BINDLESS ? bindless_stride : bind_stride;
            const auto buffer_size = USE_BINDLESS ? bindless_buffer_size : bind_buffer_size;

            vInstance->allocate(gloop::enums::buffer_target::ARRAY, buffer_size, gloop::enums::buffer_storage_hint::STREAM_DRAW);

            vao->addBinding(attribs["vImageUVs"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMaskUVs"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMvp0"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMvp1"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMvp2"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMvp3"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;

            if (USE_BINDLESS) {
                vao->addBinding(attribs["vImage"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::UVEC2, stride, off, 1));
                vao->addBinding(attribs["vMask"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::UVEC2, stride, off, 1));
            }

            _verts.reset(verts);
            _vInstance.reset(vInstance);
            _vao.reset(vao);
        }

        void masked_image_renderer::streamDraw() {
            auto instanceSize = sizeof (draw_data) * _imageCount;

            _bufferData._vInstance->reallocate();
            _bufferData._vInstance->setData(0, instanceSize, _drawData.get());

            gloop::draw::arrays_instanced drawCall;

            drawCall.count = 4;
            drawCall.drawMode = gloop::draw::mode::TRIANGLE_STRIP;
            drawCall.first = 0;
            drawCall.primitiveCount = _imageCount;

            _bufferData._vao->bind();
            drawCall();
            _currentImage = nullptr;
            _currentMask = nullptr;
            _imageCount = 0;
        }

        void masked_image_renderer::bindlessStreamDraw() {
            auto instanceSize = sizeof (bindless_draw_data) * _imageCount;

            _bufferData._vInstance->reallocate();
            _bufferData._vInstance->setData(0, instanceSize, _bindlessData.get());

            gloop::draw::arrays_instanced drawCall;

            drawCall.count = 4;
            drawCall.drawMode = gloop::draw::mode::TRIANGLE_STRIP;
            drawCall.first = 0;
            drawCall.primitiveCount = _imageCount;

            _bufferData._vao->bind();
            drawCall();
            _imageCount = 0;
        }

        void masked_image_renderer::flush() {
            if (_imageCount == 0) {
                return;
            }

            if (USE_BINDLESS) {
                bindTexture(nullptr, nullptr);
                bindlessStreamDraw();
            } else {
                if (!_currentImage) {
                    std::cout << "WARN: current image is null!" << std::endl;
                    return;
                } else if (!_currentMask) {
                    std::cout << "WARN: current mask is null!" << std::endl;
                } else {
                    bindTexture(_currentImage, _currentMask);
                    streamDraw();
                }
            }
        }

        void masked_image_renderer::reset() {
            _imageCount = 0;
            _currentImage = nullptr;
            _currentMask = nullptr;
        }

        void masked_image_renderer::draw(const masked_image& drawCall) {
            if (!drawCall.image) {
                std::cout << "WARN: attempted to draw masked image with image = null!" << std::endl;
                return;
            } else if (!drawCall.mask) {
                std::cout << "WARN: attempted to draw masked image with mask = null!" << std::endl;
                return;
            }

            if (_imageCount == BATCH_SIZE - 1) {
                flush();
            }

            if (USE_BINDLESS) {
                if (_currentImage != drawCall.image || _currentMask != drawCall.mask) {
                    flush();
                }
                
                draw_data * data = _drawData.get() + _imageCount;
                
                data->imgUVs = drawCall.imgUVs;
                data->maskUVs = drawCall.maskUVs;
                data->mvp = drawCall.mvp;                                
            } else {
                bindless_draw_data * data = _bindlessData.get() + _imageCount;
                
                data->image = drawCall.image->getHandle();
                data->imgUVs = drawCall.imgUVs;
                data->mask = drawCall.mask->getHandle();
                data->maskUVs = drawCall.maskUVs;
                data->mvp = drawCall.mvp;
            }
            
            _imageCount++;
        }
    }
}
