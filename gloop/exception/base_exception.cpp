/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "base_exception.hpp"

namespace gloop {
    namespace exception {
        const char * base_exception::what() const throw() {
            return _msg.c_str();
        }
    }        
}