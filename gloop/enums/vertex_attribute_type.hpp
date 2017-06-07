/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class vertex_attribute_type : gloop::enum_t {
            UNKNOWN = 0,
            FLOAT,
            INT,
            UINT,
            VEC2,
            VEC3,
            VEC4,
            IVEC2,
            IVEC3,
            IVEC4,
            UVEC2,
            UVEC3,
            UVEC4
        };
        
        std::ostream& operator<<(std::ostream& os, vertex_attribute_type type);
    }
}
