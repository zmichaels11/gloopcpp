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

struct Context {
    GLuint program;
    GLuint vbo;
    GLuint ibo;
    GLint gVertexPos2DLocation;
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
            gloop::shader shVertex = gloop::shader::makeVertexShader("basic.vert");
            gloop::shader shFragment = gloop::shader::makeFragmentShader("basic.frag");
            
            GLuint shaders[] = {
                shVertex.getId(),
                shFragment.getId()};
                        
            glCtx->program = gltools::createProgram(shaders, 2);
            
            auto err = glGetError();
        
            if (err != GL_NO_ERROR) {
                std::cerr << "Error creating program: " << err << std::endl;
            }
            
            glCtx->gVertexPos2DLocation = glGetAttribLocation(glCtx->program, "LVertexPos2D");
                            
            //shFragment.free();
            //shVertex.free();
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
        
        glUseProgram(glCtx->program);                
        
        glEnableVertexAttribArray(glCtx->gVertexPos2DLocation);
        glBindBuffer(GL_ARRAY_BUFFER, glCtx->vbo);
        glVertexAttribPointer(glCtx->gVertexPos2DLocation, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glCtx->ibo);
        
        glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, nullptr);        
    });

    try {
        app.start();
    } catch (const char * err) {
        std::cerr << err << std::endl;
    }

    return 0;
}

