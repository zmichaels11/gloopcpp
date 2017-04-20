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

#include "states/texture2D_parameters.hpp"
#include "texture2D.hpp"

namespace gloop {        
    
    namespace tools {
        std::string readAll(SDL_RWops * file);

        void assertGLError(std::string customMsg);

        void assertGLError();        
        
        gloop::texture2D loadTexture(const std::string& file, const states::texture2D_parameters params = states::texture2D_parameters());
    }
}
