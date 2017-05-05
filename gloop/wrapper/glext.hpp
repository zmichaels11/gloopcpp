/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   glext.hpp
 * Author: zmichaels
 *
 * Created on May 5, 2017, 9:12 AM
 */

#pragma once

#include "gl.hpp"

#include <string>

namespace gloop {
    namespace wrapper {

        class glext {
            std::string _extName;

            enum class state {
                UNCHECKED,
                SUPPORTED,
                UNSUPPORTED
            };

            state _state;

        public:

            glext(const std::string& extName) :
            _extName(extName),
            _state(state::UNCHECKED) {
            }

            operator bool();
        };
    }
}