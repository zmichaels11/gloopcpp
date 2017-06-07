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
#ifndef _LIB
#include <iostream>
#include <memory>
#include <utility>

#include "gloop/application.hpp"
#include "gloop/objects.hpp"
#include "gloop/context.hpp"
#include "gloop/draw_calls.hpp"
#include "gloop/enums.hpp"
#include "gloop/tools.hpp"
#include "gloop/uniforms.hpp"
#include "gloop/wrapper/gl.hpp"

namespace {

    static struct my_context : gloop::context {
        gloop::program program;
        gloop::vertex_array vao;
        gloop::vertex_attributes attribs;
        gloop::buffer vbo;
        gloop::buffer ibo;

        struct model {
            gloop::program * program;
            gloop::vertex_array * vertexArray;
            std::unique_ptr<gloop::draw::draw_call> drawCall;
            std::unique_ptr<gloop::uniform::uniform_binding> uniforms;

            inline void render() const {
                program->use();
                vertexArray->bind();
                (*uniforms)();
                (*drawCall)();
            }
        } model;
    } glContext;

    static void initProgram(my_context * glCtx) {
        auto vendor = gloop::wrapper::getString(gloop::wrapper::VENDOR);
        auto renderer = gloop::wrapper::getString(gloop::wrapper::RENDERER);
        auto version = gloop::wrapper::getString(gloop::wrapper::VERSION);

        std::cout << "Vendor: "
                << vendor
                << "\n"
                << "Renderer: "
                << renderer
                << "\n"
                << "Version: "
                << version
                << std::endl;

        gloop::shader shaders[]{
            gloop::shader::makeVertexShader("tests/basic.vert"),
            gloop::shader::makeFragmentShader("tests/basic.frag")
        };

        glCtx->attribs.setLocation("LVertexPos2D", 0);
        glCtx->program.setVertexAttributes(glCtx->attribs);
        glCtx->program.linkShaders(shaders, 2);
    }

    static void initVertexArray(my_context * glCtx) {
        glCtx->ibo.allocate(
                gloop::enums::buffer_target::ELEMENT_ARRAY,
                std::array<gloop::uint_t, 6>{0, 1, 2, 0, 2, 3});

        glCtx->vbo.allocate(
                gloop::enums::buffer_target::ARRAY,
                std::array<gloop::float_t, 8>{
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.5f, 0.5f,
            -0.5f, 0.5f
        });


        glCtx->vao.addBinding(
                glCtx->attribs["LVertexPos2D"]
                .bindBuffer(&(glCtx->vbo), gloop::enums::vertex_attribute_type::VEC2));

        glCtx->vao.setIndexBuffer(&(glCtx->ibo));
    }

    static void initModel(my_context * glCtx) {
        glCtx->model.program = &(glCtx->program);
        glCtx->model.vertexArray = &(glCtx->vao);

        gloop::draw::elements drawCall;

        drawCall.drawMode = gloop::draw::mode::TRIANGLES;
        drawCall.count = 6;
        drawCall.indexType = gloop::draw::index_type::UNSIGNED_INT;
        drawCall.indices = nullptr;

        glCtx->model.drawCall = std::make_unique<gloop::draw::elements>(drawCall);

        glCtx->currentClear = glCtx->currentClear.withColor(0.5F, 0.6F, 0.5F, 1.0F);

        gloop::uniform::uniform_vec4_binding setColor;

        setColor = glCtx->program.getUniformVec4Binding("fColor", 0.0F, 0.0F, 1.0F, 1.0F);

        glCtx->model.uniforms = std::make_unique<gloop::uniform::uniform_vec4_binding>(setColor);
    }

    static void render(const gloop::application * app, gloop::context * ctx) {
        if (ctx == nullptr) {
            throw "Context is null!";
        }

        auto glCtx = reinterpret_cast<my_context *> (ctx);

        if (!glCtx->program) {
            initProgram(glCtx);
        }

        if (!glCtx->vao) {
            initVertexArray(glCtx);
        }

        if (!glCtx->model.vertexArray) {
            initModel(glCtx);
        }

        gloop::tools::assertGLError();

        glCtx->currentClear();
        glCtx->model.render();
    }
}

int simple_rect(int argc, char** argv) {
    gloop::application app(640, 480, "basic_rect");

    {
        gloop::context_hints hints;

        hints.profile = gloop::context_profile::ES;
        hints.version.major = 2;
        hints.version.minor = 0;
        hints.swapInterval = 1;
        hints.doubleBuffer = true;

        app.setGLHints(hints);
    }

    app.setGLContext(&glContext);

    app.setMainLoop(render);

    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }

    return EXIT_SUCCESS;
}
#endif