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

        struct uniform_vec2_array_binding : uniform_binding {
            gloop::uint_t pId;
            gloop::uint_t loc;
            gloop::sizei_t count;
            
            const struct vec2 {
                gloop::float_t x;
                gloop::float_t y;
            } * values;

            virtual void apply() const;
        };
    }
}