/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <string>

#include "base_error.hpp"

namespace gloop {
    namespace error {

        class out_of_memory_error : public base_error {
        public:

            out_of_memory_error(std::string msg) : base_error(msg) {
            }

            out_of_memory_error() : base_error("OpenGL ran out of memory!") {
            }
        };
    }
}