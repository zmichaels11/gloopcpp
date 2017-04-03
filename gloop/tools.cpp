/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tools.hpp"

#include <string>
#include <istream>
#include <sstream>

#include "exception.hpp"

std::string gloop::tools::readAll(const std::istream& in) {
    if (in) {
        std::ostringstream contents;
        
        contents << in.rdbuf();
        contents << std::endl;
        
        return contents.str();
    } else {
        throw "Unable to read contents of stream!";
    }
}

std::string gloop::tools::readAll(std::ifstream& in) {
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

void gloop::tools::assertGLError() {
    const GLenum err = glGetError();
    
    switch (err) {
        case GL_INVALID_ENUM:
            throw gloop::invalid_enum_exception();
        case GL_INVALID_VALUE:
            throw gloop::invalid_value_exception();
        case GL_INVALID_OPERATION:
            throw gloop::invalid_operation_exception();
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            throw gloop::invalid_framebuffer_operation_exception();
        case GL_OUT_OF_MEMORY:
            throw gloop::out_of_memory_exception();
        case GL_NO_ERROR:
            // nothing to report
            break;
        default:
            throw gloop::exception("Unknown error: " + err);
    }
}

void gloop::tools::assertGLError(std::string customMsg) {
    const GLenum err = glGetError();
    
    switch (err) {
        case GL_NO_ERROR:
            // nothing to report
            break;
        case GL_INVALID_ENUM:
            throw gloop::invalid_enum_exception(customMsg);
        case GL_INVALID_VALUE:
            throw gloop::invalid_value_exception(customMsg);
        case GL_INVALID_OPERATION:
            throw gloop::invalid_operation_exception(customMsg);
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            throw gloop::invalid_framebuffer_operation_exception(customMsg);
        case GL_OUT_OF_MEMORY:
            throw gloop::out_of_memory_exception(customMsg);
        default:
            throw gloop::exception(customMsg);
    }
}