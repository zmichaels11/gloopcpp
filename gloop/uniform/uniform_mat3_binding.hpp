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

        class uniform_mat3_binding : public uniform_binding {
		public:
            gloop::uint_t pId;
            gloop::uint_t loc;
            gloop::sizei_t count;
            
            const struct mat3 {
                struct vec3 {
                    gloop::float_t x;
                    gloop::float_t y;
                    gloop::float_t z;
                } row[3];
            } * values;

            virtual void apply() const override;
        };
    }
}
