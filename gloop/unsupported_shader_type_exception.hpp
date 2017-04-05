/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   unsupported_shader_type_exception.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 10:31 AM
 */

#ifndef UNSUPPORTED_SHADER_TYPE_EXCEPTION_HPP
#define UNSUPPORTED_SHADER_TYPE_EXCEPTION_HPP

#include <string>

#include "invalid_enum_exception.hpp"

namespace gloop {
    class unsupported_shader_type_exception : public invalid_enum_exception {
    public:
        unsupported_shader_type_exception(std::string msg) : invalid_enum_exception(msg) {}
    };
}


#endif /* UNSUPPORTED_SHADER_TYPE_EXCEPTION_HPP */

