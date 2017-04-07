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

        struct uniform_vec4_binding : uniform_binding {
            gloop::uint_t pId;
            gloop::uint_t loc;

            struct vec4 {
                gloop::float_t x;
                gloop::float_t y;
                gloop::float_t z;
                gloop::float_t w;
            } value;

            virtual void apply() const;
        };
    }
}