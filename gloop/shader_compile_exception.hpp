/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shader_compile_exception.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:32 AM
 */

#ifndef SHADER_COMPILE_EXCEPTION_HPP
#define SHADER_COMPILE_EXCEPTION_HPP

#include <string>

#include "exception.hpp"

namespace gloop {
    class shader_compile_exception : public exception {
    public:
        shader_compile_exception(std::string msg) : exception(msg) {}
    };
}

#endif /* SHADER_COMPILE_EXCEPTION_HPP */

