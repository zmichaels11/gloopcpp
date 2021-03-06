/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "application.hpp"

#include <exception>
#include <functional>
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <SDL2/SDL.h>

#include "context.hpp"
#include "gloop_throw.hpp"
#include "wrapper/gl.hpp"

namespace gloop {

    application * application::MAIN_APPLICATION = nullptr;

    void application::setMainLoop(const std::function<void(const application *, context *) > callback) {
        if (this->isInitialized()) {
            gloop_throw("Unable to set main loop after application is initialized!");
        }

        this->_mainLoop = callback;
    }

    bool application::isInitialized() const {
        return this->_surface != nullptr;
    }

    void application::start() {
        if (this->isInitialized()) {            
            std::cout << "WARN: The application is already initialized!" << std::endl;
            return;
        }

        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            gloop_throw("Unable to initialize SDL!");
        }
        
#ifdef __EMSCRIPTEN__
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#else
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, this->_hints.version.major);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, this->_hints.version.minor);
#endif

        switch (this->_hints.profile) {
            case context_profile::CORE:
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
                break;
            case context_profile::ES:
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
                break;
            case context_profile::COMPATIBILITY:
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
            gloop_throw("SDL_Window could not be created!");
        }

        this->_glContext = SDL_GL_CreateContext(this->_window);

        if (this->_glContext == nullptr) {
            gloop_throw("OpenGL[ES] context could not be created!");
        }

        gloop::wrapper::init();

        if (this->_hints.swapInterval) {
            std::cout << "INFO: Setting swap interval to: " << _hints.swapInterval << std::endl;
            if (SDL_GL_SetSwapInterval(this->_hints.swapInterval) != 0) {
                std::cerr << "WARN: unable to set swap interval! SDL_Error: "
                        << SDL_GetError()
                        << std::endl;
            }
        }

        if (this->_hints.doubleBuffer) {
            if (SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) != 0) {
                std::cerr << "WARN: unable to enable doublebuffer! SDL_Error: "
                        << SDL_GetError()
                        << std::endl;
            }
        }

        this->_surface = SDL_GetWindowSurface(_window);

        if (this->_context != nullptr) {
            _context->currentScissor = _context->currentScissor.withSize({_width, _height});
            _context->currentViewport = _context->currentViewport.withSize({_width, _height});
        }

        MAIN_APPLICATION = this;

#ifdef __EMSCRIPTEN__
        emscripten_set_main_loop(runLoop, 60, true);
#else
        while (true) {
            runLoop();
        }
#endif
    }

    //NOTE: emscripten doesn't support exceptions, so omit the try-catch
    void application::runLoop() {
#ifdef __EMSCRIPTEN__
        MAIN_APPLICATION->_mainLoop(MAIN_APPLICATION, MAIN_APPLICATION->_context);
#else
        try {
            MAIN_APPLICATION->_mainLoop(MAIN_APPLICATION, MAIN_APPLICATION->_context);
        } catch (const char * err) {
            std::cerr << err << std::endl;
            std::terminate();
        }
#endif

        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                std::terminate();
            }
        }
        
        SDL_GL_SwapWindow(MAIN_APPLICATION->_window);
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

    void application::setGLHints(const context_hints hints) {
        if (this->isInitialized()) {
            gloop_throw("Unable to set OpenGL hints after SDL is initialized!");
        }

        this->_hints = hints;
    }

    const context_hints application::getGLHints() const {
        return this->_hints;
    }

    void application::setGLContext(context * ctx) {
        if (this->isInitialized()) {
            gloop_throw("Unable to specify GL context after SDL is initialized!");
        }

        this->_context = ctx;
    }

    const context * application::getGLContext() const {
        return _context;
    }
}
