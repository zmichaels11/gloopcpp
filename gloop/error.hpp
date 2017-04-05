/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   error.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:23 AM
 */

#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>
#include <string>

namespace gloop {
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
}

#endif /* ERROR_HPP */

