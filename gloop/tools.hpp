/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <iostream>
#include <memory>
#include <string>

#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_surface.h>

#include "states/texture2D_parameters.hpp"
#include "texture2D.hpp"

namespace gloop {

    class texture2D;    

    namespace tools {
        std::string readAll(SDL_RWops * file);

        void assertGLError(std::string customMsg);

        void assertGLError();

        inline void __debugAssertGLError(std::string customMsg) {
#ifdef _DEBUG
            assertGLError(customMsg);
#endif
        }

        inline void __debugAssertGLError() {
#ifdef _DEBUG
            assertGLError();
#endif
        }

        inline void __debug(std::string msg) {
#ifdef _DEBUG
            std::cout << "DEBUG: " << msg << std::endl;
#endif
        }

        struct loaded_texture2D {
            gloop::texture2D texture;
            struct view_t {
                float u0;
                float v0;
                float u1;
                float v1;
            } view;
        };
        
        loaded_texture2D loadTexture(const std::string& file, const states::texture2D_parameters params = states::texture2D_parameters());
        
        unsigned int getNearestPowerOf2(unsigned int n);
    }
}
