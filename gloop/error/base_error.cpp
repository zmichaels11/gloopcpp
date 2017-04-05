/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "base_error.hpp"

namespace gloop {
    namespace error {
        const char * base_error::what() const throw() {
            return _msg.c_str();
        }
    }
}