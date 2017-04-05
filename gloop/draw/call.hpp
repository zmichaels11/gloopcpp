/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   call.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:35 AM
 */

#ifndef CALL_HPP
#define CALL_HPP

namespace gloop {
    namespace draw {
        struct draw_call {
            virtual void draw() const = 0;
            
            inline void operator()() const {
                draw();
            }
        };
    }
}

#endif /* CALL_HPP */

