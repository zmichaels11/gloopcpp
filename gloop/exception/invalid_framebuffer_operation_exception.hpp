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

        class invalid_framebuffer_operation_exception : public base_exception {
        public:

            invalid_framebuffer_operation_exception(std::string msg) : base_exception(msg) {
            }

            invalid_framebuffer_operation_exception() : base_exception("Attempted to read or render from an incomplete framebuffer!") {
            }
        };
    }
}
