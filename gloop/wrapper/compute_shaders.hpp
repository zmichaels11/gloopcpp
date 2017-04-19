/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   compute_shaders.hpp
 * Author: zmichaels
 *
 * Created on April 19, 2017, 2:41 PM
 */

#pragma once

namespace gloop {
    namespace wrapper {
        void dispatchCompute(
                gloop::uint_t numGroupsX, 
                gloop::uint_t numGroupsY, 
                gloop::uint_t numGroupsZ);
        
        void dispatchComputeIndirect(gloop::intptr_t indirect);
    }
}