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

#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

#include "application.hpp"
#include "gltools.hpp"
#include "gloop/shader.hpp"
#include "gloop/tools.hpp"
#include "gloop/program.hpp"
#include "gloop/vertex_attributes.hpp"
#include "gloop/buffer.hpp"
#include "gloop/vertex_array.hpp"

struct Context {
    gloop::program program;
    gloop::vertex_array vao;
    gloop::vertex_attributes attribs;
} glContext;

int main(int argc, char** argv) {
    application app(640, 480, "SDL Tutorial");

    {
        gl_hints hints;

        hints.version.major = 3;
        hints.version.minor = 1;
        hints.swapInterval = 1;

        app.setGLHints(hints);
    }

    app.setGLContext(&glContext);


    app.setMainLoop([](const application * app, void * ctx) {
        if (ctx == nullptr) {
            throw "Context is null!";
        }

        Context * glCtx = reinterpret_cast<Context *> (ctx);

        if (!glCtx->program) {
            gloop::shader shaders[] {
                gloop::shader::makeVertexShader("basic.vert"),
                gloop::shader::makeFragmentShader("basic.frag")
            };

            glCtx->attribs.setLocation("LVertexPos2D", 0);
                    glCtx->program.setVertexAttributes(glCtx->attribs);
                    glCtx->program.linkShaders(shaders, 2);
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
                
            auto attrib = glCtx->attribs["LVertexPos2D"];
            auto binding = attrib.bindBuffer(vbo, gloop::vertex_attribute_type::VEC2);
            
            glCtx->vao.addBinding(binding);                        
            glCtx->vao.setIndexBuffer(ibo);
        }

        gloop::tools::assertGLError();

        glClear(GL_COLOR_BUFFER_BIT);

        glCtx->program.use();        
        glCtx->vao.bind();
        glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, nullptr);
    });

    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }

    return 0;
}

