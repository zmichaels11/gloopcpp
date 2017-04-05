/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <string>

#include "base_exception.hpp"

namespace gloop {
    namespace exception {

        class shader_compile_exception : public base_exception {
        public:

            shader_compile_exception(std::string msg) : base_exception(msg) {
            }
        };
    }
}