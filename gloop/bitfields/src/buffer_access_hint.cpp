/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer_access_hint.hpp"

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {
        buffer_access_hint operator~(buffer_access_hint lhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto outBitfield = ~lhsBitfield;
            
            return static_cast<buffer_access_hint> (outBitfield);
        }
        
        buffer_access_hint operator|(buffer_access_hint lhs, buffer_access_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield | rhsBitfield;
            
            return static_cast<buffer_access_hint> (outBitfield);
        }
        
        buffer_access_hint operator&(buffer_access_hint lhs, buffer_access_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield & rhsBitfield;
            
            return static_cast<buffer_access_hint> (outBitfield);
        }
        
        buffer_access_hint operator^(buffer_access_hint lhs, buffer_access_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield ^ rhsBitfield;
            
            return static_cast<buffer_access_hint> (outBitfield);
        }
        
        buffer_access_hint& operator|= (buffer_access_hint& lhs, buffer_access_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield | rhsBitfield;
            
            lhs = static_cast<buffer_access_hint> (outBitfield);
            
            return lhs;
        }
        
        buffer_access_hint& operator&= (buffer_access_hint& lhs, buffer_access_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield & rhsBitfield;
            
            lhs = static_cast<buffer_access_hint> (outBitfield);
            
            return lhs;
        }
        
        buffer_access_hint& operator^=(buffer_access_hint& lhs, buffer_access_hint rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield ^ rhsBitfield;
            
            lhs = static_cast<buffer_access_hint> (outBitfield);
            
            return lhs;
        }

		std::ostream& operator<<(std::ostream& os, buffer_access_hint bitfield) {
			switch (bitfield) {
				case buffer_access_hint::NONE:
					return os << "NONE";
				case buffer_access_hint::READ:
					return os << "READ";
				case buffer_access_hint::WRITE:
					return os << "WRITE";
				case buffer_access_hint::PERSISTENT:
					return os << "PERSISTENT";
				case buffer_access_hint::COHERENT:
					return os << "COHERENT";
				case buffer_access_hint::INVALIDATE_BUFFER:
					return os << "INVALIDATE_BUFFER";
				case buffer_access_hint::INVALIDATE_RANGE:
					return os << "INVALIDATE_RANGE";
				case buffer_access_hint::FLUSH_EXPLICIT:
					return os << "FLUSH_EXPLICIT";
				case buffer_access_hint::UNSYNCHRONIZED:
					return os << "UNSYNCHRONIZED";
				default:
					os << "[";
                                        
                    auto apply = [] (std::ostream& os, buffer_access_hint lhs, buffer_access_hint rhs, bool applyPipe) {
                        if (hasFlag(lhs, rhs)) {
                            if (applyPipe) {
                                os << " | ";
                            }
                            
                            os << lhs;                                                        
                            
                            return true;
                        }               
                        
                        return false;
                    };
                    
                    bool hasPipe = apply(os, bitfield, buffer_access_hint::READ, false);
                    hasPipe = apply(os, bitfield, buffer_access_hint::WRITE, hasPipe);
                    hasPipe = apply(os, bitfield, buffer_access_hint::PERSISTENT, hasPipe);
                    hasPipe = apply(os, bitfield, buffer_access_hint::COHERENT, hasPipe);
                    hasPipe = apply(os, bitfield, buffer_access_hint::INVALIDATE_BUFFER, hasPipe);
                    hasPipe = apply(os, bitfield, buffer_access_hint::INVALIDATE_RANGE, hasPipe);
                    hasPipe = apply(os, bitfield, buffer_access_hint::FLUSH_EXPLICIT, hasPipe);
                    hasPipe = apply(os, bitfield, buffer_access_hint::UNSYNCHRONIZED, hasPipe);
                    
                    os << "]";
					return os;
			}
		}
    }
}
