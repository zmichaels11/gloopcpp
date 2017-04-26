/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "solid_renderer.hpp"

#include <iostream>
#include <memory>

#include "../../gloop/gl_traits.hpp"
#include "../../gloop/buffer.hpp"
#include "../../gloop/draw/arrays.hpp"
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
            static gloop::vertex_attributes& getAttributes() {
                static gloop::vertex_attributes _attribs;
                static bool isInit = false;
                
                if (!isInit) {
                    _attribs.setLocation("vPos", 0);
                    _attribs.setLocation("vColor", 1);
                    _attribs.setLocation("vMvp0", 2);
                    _attribs.setLocation("vMvp1", 3);
                    _attribs.setLocation("vMvp2", 4);
                    _attribs.setLocation("vMvp3", 5);
                    
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
                        file = "glgfx/shaders/ES2_solid_renderer";
                    } else {
                        file = "glgfx/shaders/solid_renderer";
                    }
                    
                    gloop::shader shaders[] {
                        gloop::shader::makeVertexShader(file + ".vert"),
                        gloop::shader::makeFragmentShader(file + ".frag")
                    };
                    
                    _program.linkShaders(shaders, 2);                                        
                }
                
                _program.use();
            }
        }
        
        
        solid_renderer * solid_renderer::getInstance() {
            static std::unique_ptr<solid_renderer> _instance;
            
            if (!_instance) {
                _instance.reset(new solid_renderer);
            }
            
            return _instance.get();
        }
        
        solid_renderer::buffer_data_t::buffer_data_t() {
            gloop::buffer * verts = new gloop::buffer;
            gloop::vertex_array * vao = new gloop::vertex_array;
            
            constexpr auto stride = sizeof(point);
            constexpr auto buffer_size = stride * BATCH_SIZE;
            constexpr auto vec4_size = 4 * sizeof(gloop::float_t);
            
            verts->allocate(gloop::enums::buffer_target::ARRAY, buffer_size, gloop::enums::buffer_storage_hint::STREAM_DRAW);
            
            auto attribs = getAttributes();
            
            int off = 0;
            vao->addBinding(attribs["vPos"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC2, off, stride));
            off += vec4_size;
            vao->addBinding(attribs["vColor"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC4, off, stride));
            off += vec4_size;
            vao->addBinding(attribs["vMvp0"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC4, off, stride));
            off += vec4_size;
            vao->addBinding(attribs["vMvp1"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC4, off, stride));
            off += vec4_size;
            vao->addBinding(attribs["vMvp2"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC4, off, stride));
            off += vec4_size;
            vao->addBinding(attribs["vMvp3"].bindBuffer(verts, gloop::enums::vertex_attribute_type::VEC4, off, stride));
        }
        
        void solid_renderer::streamDraw() {
            auto instanceSize = sizeof(point) * _pointCount;
            
            _bufferData._verts->reallocate();
            _bufferData._verts->setData(0, instanceSize, _drawData.get());
            
            gloop::draw::arrays drawCall;
            
            drawCall.count = _pointCount;
            drawCall.drawMode = gloop::draw::mode::TRIANGLES;
            drawCall.first = 0;
            
            _bufferData._vao->bind();
            drawCall();
            _pointCount = 0;
        }
        
        void solid_renderer::flush() {
            if (_pointCount == 0) {
                return;
            }
            
            useProgram();
            streamDraw();
        }
        
        void solid_renderer::reset() {
            _pointCount = 0;
        }
        
        void solid_renderer::draw(const point& drawCall) {
            if (_pointCount == BATCH_SIZE - 1) {
                flush();
            }
            
            _drawData[_pointCount] = drawCall;
            _pointCount++;
        }
    }
}