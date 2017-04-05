/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "base_exception.hpp"

#include <string>

namespace gloop {
    namespace exception {

        class program_link_exception : public base_exception {
        public:

            program_link_exception(std::string msg) : base_exception(msg) {
            }
        };
    }
}