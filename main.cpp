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

struct Context {
    gloop::program program;
    GLuint vbo;
    GLuint ibo;
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
        
        Context * glCtx = (Context *) ctx;
        
        if (!glCtx->program) {
            gloop::shader shaders[] = {
                gloop::shader::makeVertexShader("basic.vert"),
                gloop::shader::makeFragmentShader("basic.frag")
            };
            
            glCtx->attribs.setLocation("LVertexPos2D", 0);
            glCtx->program.setVertexAttributes(glCtx->attribs);
            glCtx->program.linkShaders(shaders, 2);            
        }
        
        if (!glCtx->ibo) {
            GLuint data[] = {0, 1, 2, 3};
            GLuint buffer = 0;
            
            glGenBuffers(1, &buffer);
            glBindBuffer(GL_ARRAY_BUFFER, buffer);
            glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(GLuint), data, GL_STATIC_DRAW);            
            
            glCtx->ibo = buffer;
        }
        
        if (!glCtx->vbo) {
            GLfloat data[] = {
                -0.5f, -0.5f,
                 0.5f, -0.5f,
                 0.5f,  0.5f,
                -0.5f,  0.5f
            };
            
            GLuint buffer = 0;
            
            glGenBuffers(1, &buffer);
            glBindBuffer(GL_ARRAY_BUFFER, buffer);
            glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(GLfloat), data, GL_STATIC_DRAW);
            
            glCtx->vbo = buffer;
        }
        
        auto err = glGetError();
        
        if (err != GL_NO_ERROR) {
            std::cerr << "OpenGL Error: " << err << std::endl;
        }
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        glCtx->program.use();

        const auto attrib = glCtx->attribs["LVertexPos2D"];
        
        attrib.enable();
        attrib.bindBuffer(glCtx->vbo, 2, GL_FLOAT);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glCtx->ibo);
                
        glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, nullptr);        
        
        glCtx->attribs.disableAttributes();
    });

    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }

    return 0;
}

