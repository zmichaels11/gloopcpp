/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   compute_indirect.hpp
 * Author: zmichaels
 *
 * Created on April 19, 2017, 3:08 PM
 */

#pragma once

#include "call.hpp"

#include "../glint.hpp"

namespace gloop {
    namespace draw {
        struct compute_indirect_commant {
            gloop::uint_t numGroupsX;
            gloop::uint_t numGroupsY;
            gloop::uint_t numGroupsZ;
        };
        
        struct compute_indirect : compute_call {
            gloop::intptr_t indirect;
            
            virtual void execute() const;
        };
    }
}