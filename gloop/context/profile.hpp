/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   profile.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 2:02 PM
 */

#pragma once

namespace gloop {
    namespace context {
        enum class profile {
            DONT_CARE,
            CORE,
            COMPATIBILITY,
            ES
        };
    }
}