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
#include <fstream>

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "gloop/application.hpp"
#include "gloop/context.hpp"
#include "gloop/shader.hpp"
#include "gloop/tools.hpp"
#include "gloop/program.hpp"
#include "gloop/vertex_attributes.hpp"
#include "gloop/buffer.hpp"
#include "gloop/vertex_array.hpp"

struct context : gloop::context {
    gloop::program program; 
    gloop::uniform_binding color;
    gloop::vertex_array vao;
    gloop::vertex_attributes attribs;
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

        context * glCtx = reinterpret_cast<context *> (ctx);

        if (!glCtx->program) {
            gloop::shader shaders[] {
                gloop::shader::makeVertexShader("basic.vert"),
                gloop::shader::makeFragmentShader("basic.frag")
            };

            glCtx->attribs.setLocation("LVertexPos2D", 0);
            glCtx->program.setVertexAttributes(glCtx->attribs);
            glCtx->program.linkShaders(shaders, 2);
            glCtx->color = glCtx->program.bindUniform("fColor");
        }

        if (!glCtx->vao) {
            gloop::buffer ibo;
            ibo.allocate(std::array<GLuint, 4> {0, 1, 2, 3});
            
            gloop::buffer vbo;
            vbo.allocate(std::array<GLfloat, 8> { 
                -0.5f, -0.5f,
                 0.5f, -0.5f,
                 0.5f, 0.5f,
                -0.5f, 0.5f});
                
            gloop::tools::assertGLError("buffer allocate");
                
            auto attrib = glCtx->attribs["LVertexPos2D"];
            auto binding = attrib.bindBuffer(vbo, gloop::vertex_attribute_type::VEC2);
            
            glCtx->vao.addBinding(binding);                        
            glCtx->vao.setIndexBuffer(ibo);
        }

        gloop::tools::assertGLError();

        glCtx->currentClear();        

        glCtx->program.use();        
        glCtx->vao.bind();
        
        glCtx->color.pushVec4(1.0f, 0.0f, 0.0f, 1.0f);
        glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, nullptr);
    });

    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }

    return 0;
}

