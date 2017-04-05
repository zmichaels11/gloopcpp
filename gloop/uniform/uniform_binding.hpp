/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uniform_binding.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 11:01 AM
 */

#ifndef UNIFORM_BINDING_HPP
#define UNIFORM_BINDING_HPP

namespace gloop {    
    struct uniform_binding {
        virtual void apply() const = 0;

        inline virtual void operator()() {
            apply();
        }
    };
}

#endif /* UNIFORM_BINDING_HPP */

