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
        
        inline std::ostream& operator<<(std::ostream& os, vertex_attribute_type type) {
            switch (type) {
                case vertex_attribute_type::FLOAT:
                    os << "FLOAT";
                    break;
                case vertex_attribute_type::INT:
                    os << "INT";
                    break;
                case vertex_attribute_type::UINT:
                    os << "UINT";
                    break;
                case vertex_attribute_type::VEC2:
                    os << "VEC2";
                    break;
                case vertex_attribute_type::VEC3:
                    os << "VEC3";
                    break;
                case vertex_attribute_type::VEC4:
                    os << "VEC4";
                    break;
                case vertex_attribute_type::IVEC2:
                    os << "IVEC2";
                    break;
                case vertex_attribute_type::IVEC3:
                    os << "IVEC3";
                    break;
                case vertex_attribute_type::IVEC4:
                    os << "IVEC4";
                    break;
                case vertex_attribute_type::UVEC2:
                    os << "UVEC2";
                    break;
                case vertex_attribute_type::UVEC3:
                    os << "UVEC3";
                    break;
                case vertex_attribute_type::UVEC4:
                    os << "UVEC4";
                    break;
                default:
                    os << "UNKNOWN";
                    break;
            }
            
            return os;
        }
    }
}