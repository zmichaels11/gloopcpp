/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <functional>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "context.hpp"
#include "context_hints.hpp"

namespace gloop {        
    class application {
    private:
        const int _width;
        const int _height;
        const std::string _title;
        std::function<void(const application *, context *) > _mainLoop;
        SDL_Window * _window;
        SDL_Surface * _surface;
        SDL_GLContext _glContext;

        context_hints _hints;
        gloop::context * _context;

        static application * MAIN_APPLICATION;
        static void runLoop();

    public:

        application(const int width, const int height, std::string title = "SDL Test") :
        	_width(width), 
			_height(height), 
			_title(title), 
			_window(nullptr), 
			_surface(nullptr),
			_glContext(nullptr), 
        	_hints({{3, 3}, context_profile::CORE}),
			_context(nullptr) {}

        ~application();

        application(const application&) = delete;

        application(application&&) = default;

        application& operator=(const application&) = delete;

        application& operator=(application&&) = default;

        inline friend std::ostream& operator<<(std::ostream& os, const application& a) {
            return os << "application: ["
                    << "title: " << a._title
                    << ", " << a._hints;
        }

        void setGLContext(context * ctx);

        const context * getGLContext() const;

        int getWidth() const;

        int getHeight() const;

        std::string getTitle() const;

        bool isInitialized() const;

        void setMainLoop(const std::function<void(const application *, context *) > callback);

        void setGLHints(const context_hints hints);

        void start();

        void close();

        const context_hints getGLHints() const;
    };
}
