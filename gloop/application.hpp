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

namespace gloop {

    enum class context_profile {
        DONT_CARE,
        CORE,
        COMPATIBILITY,
        ES
    };

    inline std::ostream& operator<<(std::ostream& os, context_profile cp) {
        switch (cp) {
            case context_profile::DONT_CARE:
                os << "DONT_CARE";
                break;
            case context_profile::CORE:
                os << "CORE";
                break;
            case context_profile::COMPATIBILITY:
                os << "COMPATIBILITY";
                break;
            case context_profile::ES:
                os << "ES";
                break;
            default:
                os << "UNKNOWN";
                break;
        }

        return os;
    }

    struct context_hints {

        struct version {
            unsigned int major;
            unsigned int minor;

            inline friend std::ostream& operator<<(std::ostream& os, version v) {
                return os << "version: "
                        << v.major
                        << "."
                        << v.minor;
            }
        } version;

        context_profile profile;
        int swapInterval;
        bool doubleBuffer;

        inline friend std::ostream& operator<<(std::ostream& os, const context_hints& ch) {
            return os << "context_hints: ["
                    << ch.version
                    << ", profile: " << ch.profile
                    << ", swapInterval: " << ch.swapInterval
                    << ", doubleBuffer: " << (ch.doubleBuffer ? "true" : "false");
        }
    };

    inline context_hints getDefaultContextHints() {
#define GLEW 1
#define GLES2 2
#define GLES3 3

#if GL == GLEW
#ifdef __DEBUG
        std::cout << "DEBUG: Default context is OpenGL 3.3" << std::endl;
#endif
        return {
            {3, 3}, context_profile::CORE, 1, true};
#elif GL == GLES2
#ifdef __DEBUG 
        std::cout << "DEBUG: Default context is OpenGLES 2.0" << std::endl;
#endif
        return {
            {2, 0}, context_profile::ES, 1, true};
#elif GL == GLES3
#ifdef __DEBUG
        std::cout << "DEBUG: Default context is OPENGLES 3.0" << std::endl;
#endif
        return {
            {3, 0}, context_profile::ES, 1, true};
#endif

#undef GLES3
#undef GLES2
#undef GLEW
    }

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
        _width(width), _height(height), _title(title), _window(nullptr), _surface(nullptr),
        _hints({
            {3, 0}, context_profile::DONT_CARE
        }), _context(nullptr), _glContext(nullptr) {
        }

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