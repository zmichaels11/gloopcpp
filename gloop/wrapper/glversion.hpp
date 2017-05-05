/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   glversion.hpp
 * Author: zmichaels
 *
 * Created on May 5, 2017, 9:31 AM
 */

#pragma once

namespace gloop {
    namespace wrapper {

        class glversion {
            int _major;
            int _minor;
            
            enum class state {
                UNCHECKED,
                SUPPORTED,
                UNSUPPORTED
            };
            
            state _state;

        public:

            glversion(int major, int minor) :
            _major(major),
            _minor(minor),
            _state(state::UNCHECKED) {
            }
            
            glversion(const glversion&) = delete;
            glversion(glversion&&) = delete;
            
            operator bool();
        };
    }
}