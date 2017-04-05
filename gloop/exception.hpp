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
}

#endif /* EXCEPTION_HPP */

