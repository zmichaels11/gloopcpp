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

        class uniform_name_not_found_exception : public base_exception {
        public:

            uniform_name_not_found_exception(std::string msg) : base_exception(msg) {
            }
        };
    }
}