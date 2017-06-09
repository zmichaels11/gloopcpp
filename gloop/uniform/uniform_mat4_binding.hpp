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

        class uniform_mat4_binding : public uniform_binding {
		public:
            gloop::uint_t pId;
            gloop::uint_t loc;
            gloop::sizei_t count;
            
            const struct mat4 {
                struct vec4 {
                    gloop::float_t x;
                    gloop::float_t y;
                    gloop::float_t z;
                    gloop::float_t w;
                } row[4];
            } * values;

            virtual void apply() const override;
        };
    }
}
