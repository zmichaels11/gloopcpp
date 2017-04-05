/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   out_of_memory_error.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:27 AM
 */

#ifndef OUT_OF_MEMORY_ERROR_HPP
#define OUT_OF_MEMORY_ERROR_HPP

#include <string>

#include "error.hpp"

namespace gloop {

    class out_of_memory_error : public error {
    public:

        out_of_memory_error(std::string msg) : error(msg) {
        }

        out_of_memory_error() : error("OpenGL ran out of memory!") {
        }
    };
}

#endif /* OUT_OF_MEMORY_ERROR_HPP */

