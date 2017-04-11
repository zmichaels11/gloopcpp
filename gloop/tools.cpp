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

#include "exceptions.hpp"
#include "errors.hpp"
#include "gloop_throw.hpp"
#include "wrapper/gl.hpp"

namespace gloop {

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