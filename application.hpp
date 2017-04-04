/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Application.hpp
 * Author: zmichaels
 *
 * Created on March 20, 2017, 10:21 AM
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <functional>
#include <string>

#include <SDL2/SDL.h>

#include "gloop/context.hpp"

enum class gl_context_profile {
    DONT_CARE,
    CORE,
    COMPATIBILITY,
    ES
};

struct gl_hints {

    struct version {
        unsigned int major;
        unsigned int minor;
    } version;

    gl_context_profile profile;
    int swapInterval;
};

class application {
private:
    const int _width;
    const int _height;
    const std::string _title;
    std::function<void(const application *, gloop::context *) > _mainLoop;
    SDL_Window * _window;
    SDL_Surface * _surface;
    SDL_GLContext _glContext;
    
    gl_hints _hints;
    gloop::context * _context;

public:

    application(const int width, const int height, std::string title = "SDL Test") :
    _width(width), _height(height), _title(title), _window(nullptr), _surface(nullptr),
    _hints({{3, 0}, gl_context_profile::DONT_CARE}), _context(nullptr), _glContext(nullptr) {
    }

    ~application();
    
    void setGLContext(gloop::context * ctx);        
    
    const gloop::context * getGLContext() const;

    int getWidth() const;

    int getHeight() const;

    std::string getTitle() const;

    SDL_Window * const getWindow() const;

    SDL_Surface * const getSurface() const;

    bool isInitialized() const;

    void setMainLoop(const std::function<void(const application *, gloop::context *) > callback);

    void setGLHints(const gl_hints hints);

    void start();

    void close();

    const gl_hints getGLHints() const;
};

#endif /* APPLICATION_HPP */

