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
#include "wrapper/gl.hpp"

namespace gloop {

    std::string tools::readAll(SDL_RWops * file) {
        if (file == nullptr) {
#ifdef __EMSCRIPTEN__
            std::cerr << "Unable to read from file!" << std::endl;
            std::terminate();
#else
            throw "Unable to read from file!";
#endif
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
#ifdef __EMSCRIPTEN__
            std::cerr << "Unable to read entire file!" << std::endl;
            std::terminate();
#else
            throw "Unable to read entire file!";
#endif
        } else {
            return std::string(res.get(), fileSize);
        }
    }

    void tools::assertGLError() {
        auto err = gloop::wrapper::getError();                

#ifdef __EMSCRIPTEN__
        switch (err) {
            case gloop::wrapper::INVALID_ENUM:
                std::cout << "Invalid Enum!" << std::endl;
                std::terminate();
            case gloop::wrapper::INVALID_VALUE:
                std::cout << "Invalid Value!" << std::endl;
                std::terminate();
            case gloop::wrapper::INVALID_OPERATION:
                std::cout << "Invalid Operation!" << std::endl;
                std::terminate();
            case gloop::wrapper::INVALID_FRAMEBUFFER_OPERATION:
                std::cout << "Invalid Framebuffer Operation!" << std::endl;
                std::terminate();
            case gloop::wrapper::OUT_OF_MEMORY:
                std::cout << "Out of Memory!" << std::endl;
                std::terminate();
            case gloop::wrapper::NO_ERROR:
                // nothing to report
                break;
            default:
                std::cout << "Unknown Error!" << std::endl;
                std::terminate();
        }
#else
        switch (err) {
            case gloop::wrapper::INVALID_ENUM:
                throw gloop::exception::invalid_enum_exception();
            case gloop::wrapper::INVALID_VALUE:
                throw gloop::exception::invalid_value_exception();
            case gloop::wrapper::INVALID_OPERATION:
                throw gloop::exception::invalid_operation_exception();
            case gloop::wrapper::INVALID_FRAMEBUFFER_OPERATION:
                throw gloop::exception::invalid_framebuffer_operation_exception();
            case gloop::wrapper::OUT_OF_MEMORY:
                throw gloop::error::out_of_memory_error();
            case gloop::wrapper::NO_ERROR:
                // nothing to report
                break;
            default:
                throw gloop::exception::base_exception("Unknown error: " + err);
        }
#endif
    }

    void tools::assertGLError(std::string customMsg) {
        auto err = gloop::wrapper::getError();

#ifdef __EMSCRIPTEN__
        switch (err) {
            case gloop::wrapper::NO_ERROR:
                // nothing to report
                break;
            case gloop::wrapper::INVALID_ENUM:
                std::cout << "Invalid Enum: " << customMsg << std::endl;
                std::terminate();
            case gloop::wrapper::INVALID_VALUE:
                std::cout << "Invalid Value: " << customMsg << std::endl;
                std::terminate();
            case gloop::wrapper::INVALID_OPERATION:
                std::cout << "Invalid Operation: " << customMsg << std::endl;
                std::terminate();
            case gloop::wrapper::INVALID_FRAMEBUFFER_OPERATION:
                std::cout << "Invalid Framebuffer Operation: " << customMsg << std::endl;
                std::terminate();
            case gloop::wrapper::OUT_OF_MEMORY:
                std::cout << "Out of Memory: " << customMsg << std::endl;
                std::terminate();
            default:
                std::cout << "Unknown error: " << customMsg << std::endl;
                std::terminate();
        }
#else
        switch (err) {
            case gloop::wrapper::NO_ERROR:
                // nothing to report
                break;
            case gloop::wrapper::INVALID_ENUM:
                throw gloop::exception::invalid_enum_exception(customMsg);
            case gloop::wrapper::INVALID_VALUE:
                throw gloop::exception::invalid_value_exception(customMsg);
            case gloop::wrapper::INVALID_OPERATION:
                throw gloop::exception::invalid_operation_exception(customMsg);
            case gloop::wrapper::INVALID_FRAMEBUFFER_OPERATION:
                throw gloop::exception::invalid_framebuffer_operation_exception(customMsg);
            case gloop::wrapper::OUT_OF_MEMORY:
                throw gloop::error::out_of_memory_error(customMsg);
            default:
                throw gloop::exception::base_exception(customMsg);
        }
#endif
    }
}