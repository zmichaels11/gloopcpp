/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   invalid_framebuffer_operation_exception.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:26 AM
 */

#ifndef INVALID_FRAMEBUFFER_OPERATION_EXCEPTION_HPP
#define INVALID_FRAMEBUFFER_OPERATION_EXCEPTION_HPP

#include <string>

#include "exception.hpp"

namespace gloop {

    class invalid_framebuffer_operation_exception : public exception {
    public:

        invalid_framebuffer_operation_exception(std::string msg) : exception(msg) {
        }

        invalid_framebuffer_operation_exception() : exception("Attempted to read or render from an incomplete framebuffer!") {
        }
    };
}

#endif /* INVALID_FRAMEBUFFER_OPERATION_EXCEPTION_HPP */

