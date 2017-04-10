/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <string>

#include <SDL2/SDL_rwops.h>

namespace gloop {
    namespace tools {        
        std::string readAll(SDL_RWops * file);
        
        void assertGLError(std::string customMsg);
        
        void assertGLError();
    }
}
