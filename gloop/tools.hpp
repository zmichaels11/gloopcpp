/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <memory>
#include <string>

#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_surface.h>

#include "image.hpp"

namespace gloop {
    namespace tools {        
        std::string readAll(SDL_RWops * file);
        
        void assertGLError(std::string customMsg);
        
        void assertGLError();     
        
        struct sdl_surface_deleter {
            void operator() (SDL_Surface * p) const { SDL_FreeSurface(p); }
        };
        
        std::unique_ptr<SDL_Surface, sdl_surface_deleter> loadImage(const std::string& img);
        
        
    }
}
