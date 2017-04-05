/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   program_link_exception.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:57 AM
 */

#ifndef PROGRAM_LINK_EXCEPTION_HPP
#define PROGRAM_LINK_EXCEPTION_HPP

#include "exception.hpp"

#include <string>

namespace gloop {

    class program_link_exception : public exception {
    public:

        program_link_exception(std::string msg) : exception(msg) {
        }
    };
}


#endif /* PROGRAM_LINK_EXCEPTION_HPP */

