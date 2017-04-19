/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arrays_indirect.hpp
 * Author: zmichaels
 *
 * Created on April 19, 2017, 2:31 PM
 */

#pragma once

#include "../glint.hpp"
#include "call.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {
        struct arrays_indirect_command {
            gloop::uint_t count;
            gloop::uint_t primCount;
            gloop::uint_t first;
            gloop::uint_t base;
        };
        
        struct arrays_indirect : draw_call {            
            mode drawMode;
            const arrays_indirect_command * indirect;
            
            virtual void draw() const;
        };
    }
}