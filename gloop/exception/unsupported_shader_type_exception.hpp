/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <string>

#include "invalid_enum_exception.hpp"

namespace gloop {
    namespace exception {

        class unsupported_shader_type_exception : public invalid_enum_exception {
        public:

            unsupported_shader_type_exception(std::string msg) : invalid_enum_exception(msg) {
            }
        };
    }
}