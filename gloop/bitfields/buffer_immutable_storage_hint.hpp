/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer_immutable_storage_hint.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 10:11 AM
 */

#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        enum class buffer_immutable_storage_hint : gloop::bitfield_t {
            NONE = 0,
            READ = 0x0001,
            WRITE = 0x0002,
            DYNAMIC_STORAGE = 0x0100,
            CLIENT_STORAGE = 0x0200,
            COHERENT = 0x00000080,
            PERSISTENT = 0x00000040
        };

        buffer_immutable_storage_hint operator~(buffer_immutable_storage_hint lhs);
        buffer_immutable_storage_hint operator&(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint operator|(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint operator^(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint& operator&=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint& operator^=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs);
        buffer_immutable_storage_hint& operator|=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs);
        
        constexpr bool hasFlag(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs) {
            return (static_cast<gloop::bitfield_t> (lhs) & static_cast<gloop::bitfield_t> (rhs));
        }                
        
        inline std::ostream& operator<<(std::ostream& os, buffer_immutable_storage_hint hint) {
            switch (hint) {
                case buffer_immutable_storage_hint::READ:
                    os << "READ";
                    break;
                case buffer_immutable_storage_hint::WRITE:
                    os << "WRITE";
                    break;
                case buffer_immutable_storage_hint::DYNAMIC_STORAGE:
                    os << "DYNAMIC_STORAGE";
                    break;
                case buffer_immutable_storage_hint::CLIENT_STORAGE:
                    os << "CLIENT_STORAGE";
                    break;
                case buffer_immutable_storage_hint::COHERENT:
                    os << "COHERENT";
                    break;
                case buffer_immutable_storage_hint::PERSISTENT:
                    os << "PERSISTENT";
                    break;
                default:
                    os << "[";
                    
                    auto apply = [] (std::ostream& os, buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs, bool applyPipe){
                        if (hasFlag(lhs, rhs)) {
                            if (applyPipe) {
                                os << " | ";
                            }
                            
                            os << lhs;
                            
                            return true;
                        }
                        
                        return false;
                    };
                    
                    bool applyPipe = apply(os, hint, buffer_immutable_storage_hint::READ, false);
                    applyPipe = apply(os, hint, buffer_immutable_storage_hint::WRITE, applyPipe);
                    applyPipe = apply(os, hint, buffer_immutable_storage_hint::CLIENT_STORAGE, applyPipe);
                    applyPipe = apply(os, hint, buffer_immutable_storage_hint::DYNAMIC_STORAGE, applyPipe);
                    applyPipe = apply(os, hint, buffer_immutable_storage_hint::PERSISTENT, applyPipe);
                    applyPipe = apply(os, hint, buffer_immutable_storage_hint::COHERENT, applyPipe);
                    
                    os << "]";
                    break;
            }
            
            return os;
        }
    }
}