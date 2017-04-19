/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   compute.hpp
 * Author: zmichaels
 *
 * Created on April 19, 2017, 3:07 PM
 */

#pragma once

#include "call.hpp"

#include "../glint.hpp"

namespace gloop {
    namespace draw {
        struct compute : compute_call {
            gloop::uint_t numGroupsX;
            gloop::uint_t numGroupsY;
            gloop::uint_t numGroupsZ;
            
            virtual void execute() const;
        };
    }
}