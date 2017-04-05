/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   invalid_uniform_name_exception.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:58 AM
 */

#ifndef INVALID_UNIFORM_NAME_EXCEPTION_HPP
#define INVALID_UNIFORM_NAME_EXCEPTION_HPP

#include "exception.hpp"

#include <string>

namespace gloop {

    class invalid_uniform_name_exception : public exception {
    public:

        invalid_uniform_name_exception(std::string msg) : exception(msg) {
        }
    };
}


#endif /* INVALID_UNIFORM_NAME_EXCEPTION_HPP */

