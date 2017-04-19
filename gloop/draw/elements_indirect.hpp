/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   elements_indirect.hpp
 * Author: zmichaels
 *
 * Created on April 19, 2017, 2:35 PM
 */

#pragma once

#include "../glint.hpp"
#include "call.hpp"
#include "mode.hpp"
#include "index_type.hpp"

namespace gloop {
    namespace draw {
        struct elements_indirect_command {
            gloop::uint_t count;
            gloop::uint_t primCount;
            gloop::uint_t firstIndex;
            gloop::uint_t baseVertex;
            gloop::uint_t baseInstance;
        };
        
        struct elements_indirect : draw_call {
            mode drawMode;
            index_type type;
            const elements_indirect_command * indirect;
            
            virtual void draw() const;
        };
    }
}