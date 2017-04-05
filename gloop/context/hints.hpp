/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hints.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 2:03 PM
 */

#pragma once

#include "profile.hpp"

namespace gloop {
    namespace context {
        struct hints {
            struct version {
                unsigned int major;
                unsigned int minor;
            } version;
        };
        
        profile profile;
        int swaptInterval;
    }
}