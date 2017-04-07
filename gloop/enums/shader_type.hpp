/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class shader_type : gloop::enum_t {
            UNKNOWN = 0,
            VERTEX = 0x8B31,
            FRAGMENT = 0x8B30,
            GEOMETRY = 0x8DD9,
            TESSELLATION_EVALUATION = 0x8E87,
            TESSELLATION_CONTROL = 0x8E88,
            COMPUTE = 0x91B9
        };
    }
}