/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"
#include "uniform_binding.hpp"

namespace gloop {
    namespace uniform {

        struct uniform_ivec3_binding : uniform_binding {
            gloop::uint_t pId;
            gloop::uint_t loc;
            
            struct ivec3 {
                gloop::int_t x;
                gloop::int_t y;
                gloop::int_t z;
            } value;        

            virtual void apply() const;
        };
    }
}