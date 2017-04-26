/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "line_renderer.hpp"

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
#include "../../gloop/vertex_array.hpp"
#include "../../gloop/vertex_attribute_binding.hpp"
#include "../../gloop/vertex_attributes.hpp"

namespace glgfx {
    namespace renderers {
        namespace {

            static const gloop::vertex_attributes& getAttributes() {
                static gloop::vertex_attributes _attribs;
                static bool isInit = false;

                if (!isInit) {
                    _attribs.setLocation("vSelect", 0);
                    _attribs.setLocation("vPos", 1);
                    _attribs.setLocation("vColor", 2);
                    _attribs.setLocation("vMvp0", 3);
                    _attribs.setLocation("vMvp1", 4);
                    _attribs.setLocation("vMvp2", 5);
                    _attribs.setLocation("vMvp3", 6);

                    isInit = true;
                }

                return _attribs;
            }

            static void useProgram() {
                static gloop::program _program;

                if (!_program) {
                    _program.setVertexAttributes(getAttributes());

                    std::string file;

                    if (gloop::isGLES2) {
                        file = "glgfx/shaders/ES2_line_renderer";
                    } else {
                        file = "glgfx/shaders/line_renderer";
                    }

                    gloop::shader shaders[]{
                        gloop::shader::makeVertexShader(file + ".vert"),
                        gloop::shader::makeFragmentShader(file + ".frag")
                    };

                    _program.linkShaders(shaders, 2);
                }

                _program.use();
            }
        }

        line_renderer::line_renderer() {            
            _drawData = std::make_unique <line_draw[]> (BATCH_SIZE);            
            _lineCount = 0;
        }

        line_renderer::buffer_data_t::buffer_data_t() {
            gloop::buffer * verts = new gloop::buffer;
            gloop::buffer * vInstance = new gloop::buffer;

            constexpr auto stride = sizeof (line_draw);
            constexpr auto vec4_size = 4 * sizeof (gloop::float_t);
            constexpr auto buffer_size = stride * BATCH_SIZE;

            verts->allocate(gloop::enums::buffer_target::ARRAY, std::array<float, 4>{0.0F, 0.0F, 1.0F, 1.0F});
            vInstance->allocate(gloop::enums::buffer_target::ARRAY, buffer_size, gloop::enums::buffer_storage_hint::STREAM_DRAW);

            auto attribs = getAttributes();

            gloop::vertex_array * vao = new gloop::vertex_array;

            int off = 0;

            vao->addBinding(attribs["vSelect"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC2));

            vao->addBinding(attribs["vPos"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vColor"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMvp0"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMvp1"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMvp2"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));
            off += vec4_size;
            vao->addBinding(attribs["vMvp3"].bindBuffer(vInstance, gloop::enums::vertex_attribute_type::VEC4, stride, off, 1));

            _verts.reset(verts);
            _vInstance.reset(vInstance);
            _vao.reset(vao);
        }

        void line_renderer::streamDraw() {
            auto instanceSize = sizeof (line_draw) * _lineCount;

            _bufferData._vInstance->reallocate();
            _bufferData._vInstance->setData(0, instanceSize, _drawData.get());

            gloop::draw::arrays_instanced drawCall;

            drawCall.count = 2;
            drawCall.drawMode = gloop::draw::mode::LINES;
            drawCall.first = 0;
            drawCall.primitiveCount = _lineCount;

            _bufferData._vao->bind();
            drawCall();

            _lineCount = 0;
        }

        void line_renderer::flush() {
            if (_lineCount == 0) {
                return;
            }

            useProgram();
            streamDraw();
        }

        void line_renderer::reset() {
            _lineCount = 0;
        }

        void line_renderer::draw(const line_draw& drawCall) {
            if (_lineCount == BATCH_SIZE - 1) {
                flush();
            }
            
            _drawData[_lineCount] = drawCall;
            
            _lineCount++;
        }

        line_renderer* line_renderer::getInstance() {
            static std::unique_ptr<line_renderer> _instance;
            
            if (!_instance) {
                _instance.reset(new line_renderer);
            }
            
            return _instance.get();
        }
    }
}