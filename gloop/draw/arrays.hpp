/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"
#include "call.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {
        struct arrays : draw_call {            
            mode drawMode;
            gloop::int_t first;
            gloop::sizei_t count;            
            
            virtual void draw() const;
        };
    }
}