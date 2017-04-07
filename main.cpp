/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zmichaels
 *
 * Created on March 20, 2017, 9:46 AM
 */

#include <iostream>
#include <memory>
#include <utility>

#include <GL/glew.h>

#include "gloop/application.hpp"
#include "gloop/buffer.hpp"
#include "gloop/context.hpp"
#include "gloop/draw_calls.hpp"
#include "gloop/program.hpp"
#include "gloop/shader.hpp"
#include "gloop/tools.hpp"
#include "gloop/uniforms.hpp"
#include "gloop/vertex_array.hpp"
#include "gloop/vertex_attributes.hpp"

struct model {
    gloop::program * program;
    gloop::vertex_array * vertexArray;
    std::shared_ptr<gloop::draw::draw_call> drawCall;
    std::shared_ptr<gloop::uniform::uniform_binding> uniforms;
    
    inline void render() const {
        program->use();
        vertexArray->bind();
        (*uniforms)();
        (*drawCall)();
    }
} model;

struct my_context : gloop::context {
    gloop::program program;     
    gloop::vertex_array vao;
    gloop::vertex_attributes attribs;
    gloop::buffer vbo;
    gloop::buffer ibo;
} glContext;

int main(int argc, char** argv) {
    gloop::application app(640, 480, "SDL Tutorial");

    {
        gloop::context_hints hints;

        hints.version.major = 3;
        hints.version.minor = 1;
        hints.swapInterval = 1;

        app.setGLHints(hints);
    }

    app.setGLContext(&glContext);

    app.setMainLoop([](const gloop::application * app, gloop::context * ctx) {                       
        if (ctx == nullptr) {
            throw "Context is null!";
        }

        auto glCtx = reinterpret_cast<my_context *> (ctx);

        if (!glCtx->program) {            
            gloop::shader shaders[] {
                gloop::shader::makeVertexShader("basic.vert"),
                gloop::shader::makeFragmentShader("basic.frag")
            };

            glCtx->attribs.setLocation("LVertexPos2D", 0);
            glCtx->program.setVertexAttributes(glCtx->attribs);
            glCtx->program.linkShaders(shaders, 2);
            
            gloop::uniform::uniform_vec4_binding setColor;
            
            setColor = glCtx->program.getUniformVec4Binding("fColor", 0.0F, 0.0F, 1.0F, 1.0F);
            
            model.uniforms = std::make_shared<gloop::uniform::uniform_vec4_binding>(setColor);
        }

        if (!glCtx->vao) {            
            glCtx->ibo.allocate(std::array<GLuint, 4> {0, 1, 2, 3});                        
            glCtx->vbo.allocate(std::array<GLfloat, 8> { 
                -0.5f, -0.5f,
                 0.5f, -0.5f,
                 0.5f, 0.5f,
                -0.5f, 0.5f});
                
            gloop::tools::assertGLError("buffer allocate");                        
                
            auto attrib = glCtx->attribs["LVertexPos2D"];
            auto binding = attrib.bindBuffer(&(glCtx->vbo), gloop::vertex_attribute_type::VEC2);
            
            glCtx->vao.addBinding(binding);                        
            glCtx->vao.setIndexBuffer(&(glCtx->ibo));
        }
        
        if (!model.vertexArray) {
            model.program = &(glCtx->program);
            model.vertexArray = &(glCtx->vao);
                        
            gloop::draw::elements drawCall;
            
            drawCall.drawMode = gloop::draw::mode::TRIANGLE_FAN;
            drawCall.count = 4;
            drawCall.indexType = gloop::draw::index_type::UNSIGNED_INT;
            drawCall.indices = nullptr;
            
            model.drawCall = std::make_shared<gloop::draw::elements>(drawCall);
        }

        gloop::tools::assertGLError();

        glCtx->currentClear();        
        model.render();
    });

    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }

    return 0;
}

