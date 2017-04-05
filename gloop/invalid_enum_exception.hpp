/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   invalid_enum_exception.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:24 AM
 */

#ifndef INVALID_ENUM_EXCEPTION_HPP
#define INVALID_ENUM_EXCEPTION_HPP

#include <string>

#include "exception.hpp"

namespace gloop {
    class invalid_enum_exception : public exception {
    public:

        invalid_enum_exception(std::string msg) : exception(msg) {
        }

        invalid_enum_exception() : exception("An value for an enumerated argument was detected!") {
        }
    };
}

#endif /* INVALID_ENUM_EXCEPTION_HPP */

