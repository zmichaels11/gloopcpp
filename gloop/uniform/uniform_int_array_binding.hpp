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

        class uniform_int_array_binding : public uniform_binding {
		public:
            gloop::uint_t pId;
            gloop::uint_t loc;
            gloop::sizei_t count;
            const gloop::int_t * values;            

            virtual void apply() const override;
        };
    }
}
