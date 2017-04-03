/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exception.hpp
 * Author: zmichaels
 *
 * Created on April 3, 2017, 8:24 AM
 */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>
#include <GL/glew.h>

namespace gloop {

    class exception : public std::exception {
    private:
        const std::string _msg;

    public:

        exception(std::string msg) : _msg(msg) {
        }

        exception() : _msg("An OpenGL exception occurred! The offending operation was ignored.") {
        }

        virtual const char * what() const throw ();
    };

    class error : public std::exception {
    private:
        const std::string _msg;

    public:

        error(std::string msg) : _msg(msg) {
        }

        error() : _msg("An OpenGL error occurred! The GLContext is now invalid.") {
        }
        
        virtual const char * what() const throw ();
    };

    class invalid_enum_exception : public exception {
    public:

        invalid_enum_exception(std::string msg) : exception(msg) {
        }

        invalid_enum_exception() : exception("An value for an enumerated argument was detected!") {
        }
    };

    class invalid_value_exception : public exception {
    public:

        invalid_value_exception(std::string msg) : exception(msg) {
        }

        invalid_value_exception() : exception("A numeric argument is out of range!") {
        }
    };

    class invalid_operation_exception : public exception {
    public:

        invalid_operation_exception(std::string msg) : exception(msg) {
        }

        invalid_operation_exception() : exception("An illegal operation from the current state was executed!") {
        }
    };

    class invalid_framebuffer_operation_exception : public exception {
    public:

        invalid_framebuffer_operation_exception(std::string msg) : exception(msg) {
        }

        invalid_framebuffer_operation_exception() : exception("Attempted to read or render from an incomplete framebuffer!") {
        }
    };

    class out_of_memory_exception : public error {
    public:

        out_of_memory_exception(std::string msg) : error(msg) {
        }

        out_of_memory_exception() : error("OpenGL ran out of memory!") {
        }
    };        
}

#endif /* EXCEPTION_HPP */

