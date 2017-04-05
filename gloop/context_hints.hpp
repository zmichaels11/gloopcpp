/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   context_hints.hpp
 * Author: zmichaels
 *
 * Created on April 5, 2017, 2:06 PM
 */

#pragma once

#include "context_profile.hpp"

namespace gloop {
    struct context_hints {

        struct version {
            unsigned int major;
            unsigned int minor;
        } version;

        context_profile profile;
        int swapInterval;
    };
}