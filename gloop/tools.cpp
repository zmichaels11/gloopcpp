/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tools.hpp"

#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#ifdef USE_SDL_IMAGE
#include <SDL2/SDL_image.h>
#else
#warning "SDL_Image is not included; PNG will not be available!"
#endif

#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_surface.h>

#include "enums/texture_internal_format.hpp"
#include "errors.hpp"
#include "exceptions.hpp"
#include "gloop_throw.hpp"
#include "states/texture2D_parameters.hpp"
#include "texture2D.hpp"
#include "wrapper/gl.hpp"
#include "pixel_formats.hpp"

namespace gloop {
    namespace {

        static bool hasSuffix(
                const std::string& str,
                const std::string& suffix) {

            return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
        }
    }   

    tools::loaded_texture2D tools::loadTexture(const std::string& file, const states::texture2D_parameters params) {
        loaded_texture2D out;

        out.texture.setParameters(params);

#ifdef USE_SDL_IMAGE
        static bool isInit = false;
        
        if (!isInit) {
            auto result = IMG_Init(IMG_INIT_PNG);
            
            if ((result & IMG_INIT_PNG) != IMG_INIT_PNG) {
                gloop_throw("Unable to initialize PNG library!");
            } else {
                std::cout << "INFO: initialized PNG library!" << std::endl;
            }
            
            isInit = true;
        }
        
        const auto img = IMG_Load(file.c_str());
#else       
        const auto img = SDL_LoadBMP(file.c_str());
#endif
        
        if (img == nullptr) {
            gloop_throw("Unable to load image!");
        }
        
        constexpr Uint32 rmask = 0x000000FF;
        constexpr Uint32 gmask = 0x0000FF00;
        constexpr Uint32 bmask = 0x00FF0000;
        constexpr Uint32 amask = 0xFF000000;
                        
        const auto optimized = SDL_CreateRGBSurface(0, img->w, img->h, 32, rmask, gmask, bmask, amask);
        
        if (optimized == nullptr) {
            gloop_throw("Unable to create RGB surface!");
        }
                
        
        SDL_BlitSurface(img, nullptr, optimized, nullptr);
        
        auto width = tools::getNearestPowerOf2(img->w);
        auto height = tools::getNearestPowerOf2(img->h);
        
        out.texture.allocate(gloop::enums::texture_internal_format::R8_G8_B8_A8_UNORM, 1, width, height);
        out.texture.update(0, 0, 0, img->w, img->h, reinterpret_cast<const gloop::pixel_formats::R8_G8_B8_A8 *> (optimized->pixels));
        
        out.view.u0 = 0.0F;
        out.view.v0 = 0.0F;
        out.view.u1 = float(img->w) / float(width);
        out.view.v1 = float(img->h) / float(height);
        
        SDL_FreeSurface(optimized);
        SDL_FreeSurface(img);
        
        return out;
    }

    std::string tools::readAll(SDL_RWops * file) {
        if (file == nullptr) {
            gloop_throw("Unable to read from file!");
        }

        auto fileSize = SDL_RWsize(file);
        auto res = std::make_unique<char[]>(fileSize);

        Sint64 totalBytesRead = 0;
        Sint64 bytesRead = 1;
        auto buffer = res.get();

        while (totalBytesRead < fileSize && bytesRead != 0) {
            bytesRead = SDL_RWread(file, buffer, 1, (fileSize - totalBytesRead));
            totalBytesRead += bytesRead;
            buffer += bytesRead;
        }

        SDL_RWclose(file);

        if (totalBytesRead != fileSize) {
            gloop_throw("Unable to read entire file!");
        } else {
            return std::string(res.get(), fileSize);
        }
    }
    
    void tools::assertGLError() {
        auto err = gloop::wrapper::getError();

        switch (err) {
            case gloop::wrapper::INVALID_ENUM:
                gloop_throw(gloop::exception::invalid_enum_exception());
            case gloop::wrapper::INVALID_VALUE:
                gloop_throw(gloop::exception::invalid_value_exception());
            case gloop::wrapper::INVALID_OPERATION:
                gloop_throw(gloop::exception::invalid_operation_exception());
            case gloop::wrapper::INVALID_FRAMEBUFFER_OPERATION:
                gloop_throw(gloop::exception::invalid_framebuffer_operation_exception());
            case gloop::wrapper::OUT_OF_MEMORY:
                gloop_throw(gloop::error::out_of_memory_error());
            case gloop::wrapper::NO_ERROR:
                // nothing to report
                break;
            default:
                gloop_throw(gloop::exception::base_exception("Unknown error"));
        }
    }

    void tools::assertGLError(std::string customMsg) {
        auto err = gloop::wrapper::getError();

        switch (err) {
            case gloop::wrapper::NO_ERROR:
                // nothing to report
                break;
            case gloop::wrapper::INVALID_ENUM:
                gloop_throw(gloop::exception::invalid_enum_exception(customMsg));
            case gloop::wrapper::INVALID_VALUE:
                gloop_throw(gloop::exception::invalid_value_exception(customMsg));
            case gloop::wrapper::INVALID_OPERATION:
                gloop_throw(gloop::exception::invalid_operation_exception(customMsg));
            case gloop::wrapper::INVALID_FRAMEBUFFER_OPERATION:
                gloop_throw(gloop::exception::invalid_framebuffer_operation_exception(customMsg));
            case gloop::wrapper::OUT_OF_MEMORY:
                gloop_throw(gloop::error::out_of_memory_error(customMsg));
            default:
                gloop_throw(gloop::exception::base_exception(customMsg));
        }
    }

    unsigned int tools::getNearestPowerOf2(unsigned int n) {
        unsigned int val = 1;
        
        while (val < n) {
            val <<= 1;
        }
        
        return val;
    }
}
