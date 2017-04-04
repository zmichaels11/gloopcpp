/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "application.hpp"

#include <iostream>
#include <functional>

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "gloop/context.hpp"

void application::setMainLoop(const std::function<void(const application *, gloop::context *)> callback) {
    if (this->isInitialized()) {
        throw "Unable to set main loop after application is initialized!";
    }
    
    this->_mainLoop = callback;
}

bool application::isInitialized() const {
    return this->_surface != nullptr;
}

void application::start() {
    if (this->isInitialized()) {
        std::cerr << "The application is already initialized!" << std::endl;
        return;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw "Unable to initialize SDL!";
    }
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, this->_hints.version.major);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, this->_hints.version.minor);
    
    switch (this->_hints.profile) {
        case gl_context_profile::CORE:
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            break;
        case gl_context_profile::ES:
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
            break;
        case gl_context_profile::COMPATIBILITY:
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
            break;
        default:
            // do nothing
            break;            
    }
    
    this->_window = SDL_CreateWindow(
            this->_title.c_str(),
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            this->_width, this->_height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);        
    
    if (this->_window == nullptr) {
        throw "SDL_Window could not be created!";        
    }
    
    this->_glContext = SDL_GL_CreateContext(this->_window);
    
    if (this->_glContext == nullptr) {
        std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
        throw "OpenGL context could not be created!";                
    }
    
    if (glewInit() != GLEW_OK) {
        throw "glew could not be initialized!";
    }
    
    if (this->_hints.swapInterval) {
        if (SDL_GL_SetSwapInterval(this->_hints.swapInterval) < 0) {
            std::cerr << "WARN: unable to set swap interval! SDL_Error: "
                    << SDL_GetError()
                    << std::endl;
        }
    }        
    
    this->_surface = SDL_GetWindowSurface(_window);
    
    if (this->_context != nullptr) {
        *_context = gloop::context(_width, _height);
    }
    
    bool quit = false;
    while(!quit) {
        try {
            this->_mainLoop(this, this->_context);
        } catch (const char * err) {
            std::cerr << err << std::endl;
            quit = true;
        }
        
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        
        SDL_GL_SwapWindow(this->_window);
        //SDL_UpdateWindowSurface(this->_window);
    }
}

SDL_Window * const application::getWindow() const {
    return this->_window;
}

SDL_Surface * const application::getSurface() const {    
    return this->_surface;
}

int application::getWidth() const {
    return this->_width;
}

int application::getHeight() const {
    return this->_height;
}

std::string application::getTitle() const {
    return this->_title;
}

void application::close() {
    if (this->isInitialized()) {
        SDL_DestroyWindow(this->_window);
        this->_surface = nullptr;
        this->_window = nullptr;        
    }
}

application::~application() {
    this->close();
}

void application::setGLHints(const gl_hints hints) {
    if (this->isInitialized()) {
        throw "Unable to set OpenGL hints after SDL is initialized!";
    }
    
    this->_hints = hints;
}

const gl_hints application::getGLHints() const {
    return this->_hints;
}

void application::setGLContext(gloop::context * ctx) {
    if (this->isInitialized()) {
        throw "Unable to specify GL context after SDL is initialized!";
    }
    
    this->_context = ctx;
}

const gloop::context * application::getGLContext() const {
    return _context;
}