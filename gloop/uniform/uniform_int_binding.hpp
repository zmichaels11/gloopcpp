/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"
#include "uniform_binding.hpp"

namespace gloop {
	class texture2D;

    namespace uniform {

        class uniform_int_binding : public uniform_binding {
		public:
            gloop::uint_t pId;
            gloop::uint_t loc;
            gloop::int_t value;            

            virtual void apply() const override;

			using uniform_binding::operator();

			virtual void operator()(const gloop::texture2D& img) const;
        };
    }
}
