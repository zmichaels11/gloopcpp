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

        class uniform_ivec4_binding : public uniform_binding {
		public:
            gloop::uint_t pId;
            gloop::uint_t loc;

            struct ivec4 {
                gloop::int_t x;
                gloop::int_t y;
                gloop::int_t z;
                gloop::int_t w;
            } value;

            virtual void apply() const;
        };
    }
}
