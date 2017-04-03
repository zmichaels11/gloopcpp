/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "exception.hpp"

#include <string>
#include <GL/glew.h>

const char * gloop::exception::what() const throw() {
    return _msg.c_str();
}

const char * gloop::error::what() const throw() {
    return _msg.c_str();
}