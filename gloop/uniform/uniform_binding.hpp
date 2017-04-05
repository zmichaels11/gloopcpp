/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

namespace gloop {    
    struct uniform_binding {
        virtual void apply() const = 0;

        inline virtual void operator()() {
            apply();
        }
    };
}