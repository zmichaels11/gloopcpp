/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   invalid_value_exception.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:25 AM
 */

#ifndef INVALID_VALUE_EXCEPTION_HPP
#define INVALID_VALUE_EXCEPTION_HPP

#include <string>

#include "exception.hpp"

namespace gloop {
    class invalid_value_exception : public exception {
    public:

        invalid_value_exception(std::string msg) : exception(msg) {
        }

        invalid_value_exception() : exception("A numeric argument is out of range!") {
        }
    };
}

#endif /* INVALID_VALUE_EXCEPTION_HPP */

