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

        class invalid_value_exception : public base_exception {
        public:

            invalid_value_exception(std::string msg) : base_exception(msg) {
            }

            invalid_value_exception() : base_exception("A numeric argument is out of range!") {
            }
        };
    }
}