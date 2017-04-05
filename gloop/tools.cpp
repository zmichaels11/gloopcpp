/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tools.hpp"

#include <istream>
#include <sstream>
#include <string>

#include <GL/glew.h>

#include "exceptions.hpp"
#include "errors.hpp"

namespace gloop {
    std::string tools::readAll(const std::istream& in) {
        if (in) {
            std::ostringstream contents;

            contents << in.rdbuf();
            contents << std::endl;

            return contents.str();
        } else {
            throw "Unable to read contents of stream!";
        }
    }

    std::string tools::readAll(std::ifstream& in) {
        if (in) {
            std::ostringstream contents;

            contents << in.rdbuf();
            contents << std::endl;

            in.close();

            return contents.str();
        } else {
            throw "Unable to read contents of file input stream!";
        }
    }

    void tools::assertGLError() {
        auto err = glGetError();

        switch (err) {
            case GL_INVALID_ENUM:
                throw gloop::exception::invalid_enum_exception();
            case GL_INVALID_VALUE:
                throw gloop::exception::invalid_value_exception();
            case GL_INVALID_OPERATION:
                throw gloop::exception::invalid_operation_exception();
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                throw gloop::exception::invalid_framebuffer_operation_exception();
            case GL_OUT_OF_MEMORY:
                throw gloop::error::out_of_memory_error();
            case GL_NO_ERROR:
                // nothing to report
                break;
            default:
                throw gloop::exception::base_exception("Unknown error: " + err);
        }
    }

    void tools::assertGLError(std::string customMsg) {
        auto err = glGetError();

        switch (err) {
            case GL_NO_ERROR:
                // nothing to report
                break;
            case GL_INVALID_ENUM:
                throw gloop::exception::invalid_enum_exception(customMsg);
            case GL_INVALID_VALUE:
                throw gloop::exception::invalid_value_exception(customMsg);
            case GL_INVALID_OPERATION:
                throw gloop::exception::invalid_operation_exception(customMsg);
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                throw gloop::exception::invalid_framebuffer_operation_exception(customMsg);
            case GL_OUT_OF_MEMORY:
                throw gloop::error::out_of_memory_error(customMsg);
            default:
                throw gloop::exception::base_exception(customMsg);
        }
    }
}