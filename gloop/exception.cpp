/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "exception.hpp"

namespace gloop {
    const char * exception::what() const throw() {
        return _msg.c_str();
    }        
}