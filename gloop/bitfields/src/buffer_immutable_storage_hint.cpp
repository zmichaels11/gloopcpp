/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer_immutable_storage_hint.hpp"

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        buffer_immutable_storage_hint operator~(buffer_immutable_storage_hint lhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto outBitfield = ~lhsBitfield;

            return static_cast<buffer_immutable_storage_hint> (outBitfield);
        }

        buffer_immutable_storage_hint operator&(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield & rhsBitfield;

            return static_cast<buffer_immutable_storage_hint> (outBitfield);
        }

        buffer_immutable_storage_hint operator|(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield | rhsBitfield;

            return static_cast<buffer_immutable_storage_hint> (outBitfield);
        }

        buffer_immutable_storage_hint operator^(buffer_immutable_storage_hint lhs, buffer_immutable_storage_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield ^ rhsBitfield;

            return static_cast<buffer_immutable_storage_hint> (outBitfield);
        }

        buffer_immutable_storage_hint& operator&=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield & rhsBitfield;
            
            lhs = static_cast<buffer_immutable_storage_hint> (outBitfield);
            
            return lhs;
        }

        buffer_immutable_storage_hint& operator^=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield ^ rhsBitfield;
            
            lhs = static_cast<buffer_immutable_storage_hint> (outBitfield);
            
            return lhs;
        }

        buffer_immutable_storage_hint& operator|=(buffer_immutable_storage_hint& lhs, buffer_immutable_storage_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield | rhsBitfield;
            
            lhs = static_cast<buffer_immutable_storage_hint> (outBitfield);
            
            return lhs;
        }

		std::ostream& operator<<(std::ostream& os, buffer_immutable_storage_hint hint) {
			switch (hint) {
				case buffer_immutable_storage_hint::READ:
					return os << "READ";
				case buffer_immutable_storage_hint::WRITE:
					return os << "WRITE";
				case buffer_immutable_storage_hint::DYNAMIC_STORAGE:
					return os << "DYNAMIC_STORAGE";
				case buffer_immutable_storage_hint::CLIENT_STORAGE:
					return os << "CLIENT_STORAGE";
				case buffer_immutable_storage_hint::COHERENT:
					return os << "COHERENT";
				case buffer_immutable_storage_hint::PERSISTENT:
					return os << "PERSISTENT";
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
					return os;				
			}
		}
    }
}
