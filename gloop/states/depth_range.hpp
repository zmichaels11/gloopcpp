/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace states {

        struct depth_range {
            gloop::double_t near;
            gloop::double_t far;

            void apply() const;

            inline void operator()() const {
                apply();
            }

            friend std::ostream& operator<<(std::ostream& os, const depth_range& d);
        };
    }
}