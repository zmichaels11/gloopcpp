/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   invalid_operation_exception.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:25 AM
 */

#ifndef INVALID_OPERATION_EXCEPTION_HPP
#define INVALID_OPERATION_EXCEPTION_HPP

#include <string>

#include "exception.hpp"

namespace gloop {
    class invalid_operation_exception : public exception {
    public:

        invalid_operation_exception(std::string msg) : exception(msg) {
        }

        invalid_operation_exception() : exception("An illegal operation from the current state was executed!") {
        }
    };
}

#endif /* INVALID_OPERATION_EXCEPTION_HPP */

