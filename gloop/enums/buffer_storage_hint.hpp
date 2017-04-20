/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer_storage_hint.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:01 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace enums {

        enum class buffer_storage_hint : gloop::enum_t {
            UNKNOWN = 0,
            STATIC_DRAW = 0x88E4,
            STATIC_READ = 0x88E5,
            STATIC_COPY = 0x88E6,
            DYNAMIC_DRAW = 0x88E8,
            DYNAMIC_READ = 0x88E9,
            DYNAMIC_COPY = 0x88EA,
            STREAM_DRAW = 0x88E0,
            STREAM_READ = 0x88E1,
            STREAM_COPY = 0x88E2
        };
        
        inline std::ostream& operator<<(std::ostream& os, buffer_storage_hint hint) {
            switch (hint) {
                case buffer_storage_hint::STATIC_DRAW:
                    os << "STATIC_DRAW";
                    break;
                case buffer_storage_hint::STATIC_READ:
                    os << "STATIC_READ";
                    break;
                case buffer_storage_hint::STATIC_COPY:
                    os << "STATIC_COPY";
                    break;
                case buffer_storage_hint::DYNAMIC_DRAW:
                    os << "DYNAMIC_DRAW";
                    break;
                case buffer_storage_hint::DYNAMIC_READ:
                    os << "DYNAMIC_READ";
                    break;
                case buffer_storage_hint::DYNAMIC_COPY:
                    os << "DYNAMIC_COPY";
                    break;
                case buffer_storage_hint::STREAM_DRAW:
                    os << "STREAM_DRAW";
                    break;
                case buffer_storage_hint::STREAM_READ:
                    os << "STREAM_READ";
                    break;
                case buffer_storage_hint::STREAM_COPY:
                    os << "STREAM_COPY";
                    break;
                default:
                    os << "UNKNOWN";
                    break;
            }
            
            return os;
        }
    }
}