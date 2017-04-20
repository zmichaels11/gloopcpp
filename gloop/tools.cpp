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

#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_surface.h>

#include "exceptions.hpp"
#include "errors.hpp"
#include "gloop_throw.hpp"
#include "states/texture2D_parameters.hpp"
#include "texture2D.hpp"
#include "wrapper/gl.hpp"

namespace gloop {
    namespace {

        static bool hasSuffix(
                const std::string& str,
                const std::string& suffix) {

            return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
        }
    }

    gloop::texture2D tools::loadTexture(const std::string& file, const states::texture2D_parameters params) {
        gloop::texture2D out;

        out.setParameters(params);

        const auto img = SDL_LoadBMP(file.c_str());

        const auto sdlFormat = img->format->format;
        const auto sdlPixelType = SDL_PIXELTYPE(sdlFormat);
        const auto sdlPixelOrder = SDL_PIXELORDER(sdlFormat);

        if (sdlPixelType == SDL_PIXELTYPE_UNKNOWN) {
            gloop_throw(gloop::exception::invalid_enum_exception("Unknown SDL pixel type!"));
        } else if (sdlPixelType == SDL_PIXELTYPE_ARRAYU8) {
            switch (sdlPixelOrder) {
                case SDL_ARRAYORDER_NONE:
                    gloop_throw(gloop::exception::invalid_enum_exception("SDL pixel type array must have an array order!"));
                    break;
                case SDL_ARRAYORDER_BGR:                    
                    out.allocate(enums::texture_internal_format::R8_G8_B8_UNORM, 1, img->w, img->h);
                    out.update(0, 0, 0, img->w, img->h, reinterpret_cast<gloop::pixel_formats::B8_G8_R8*> (img->pixels));
                    break;
                case SDL_ARRAYORDER_BGRA:
                    out.allocate(enums::texture_internal_format::R8_G8_B8_A8_UNORM, 1, img->w, img->h);
                    out.update(0, 0, 0, img->w, img->h, reinterpret_cast<gloop::pixel_formats::B8_G8_R8_A8*> (img->pixels));
                    break;
                case SDL_ARRAYORDER_RGB:
                    out.allocate(enums::texture_internal_format::R8_G8_B8_UNORM, 1, img->w, img->h);
                    out.update(0, 0, 0, img->w, img->h, reinterpret_cast<gloop::pixel_formats::R8_G8_B8 *> (img->pixels));
                    break;
                case SDL_ARRAYORDER_RGBA:
                    out.allocate(enums::texture_internal_format::R8_G8_B8_A8_UNORM, 1, img->w, img->h);
                    out.update(0, 0, 0, img->w, img->h, reinterpret_cast<gloop::pixel_formats::R8_G8_B8_A8 *> (img->pixels));
                    break;
                default:
                    gloop_throw(gloop::exception::invalid_enum_exception("Unsupported SDL pixel type array order!"));
                    break;
            }
        } else {
            gloop_throw(gloop::exception::invalid_enum_exception("Unsupported SDL pixel type!"));
        }                
        
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


}