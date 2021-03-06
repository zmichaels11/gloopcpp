/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "clear_mask.hpp"

#include <iostream>

#include "../glint.hpp"

namespace gloop {
    namespace bitfields {

        clear_mask operator|(clear_mask lhs, clear_mask rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield | rhsBitfield;
            
            return static_cast<clear_mask> (outBitfield);
        }

        clear_mask operator&(clear_mask lhs, clear_mask rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield & rhsBitfield;
            
            return static_cast<clear_mask> (outBitfield);
        }

        clear_mask operator^ (clear_mask lhs, clear_mask rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield ^ rhsBitfield;
            
            return static_cast<clear_mask> (outBitfield);
        }

        clear_mask operator~(clear_mask lhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto outBitfield = ~lhsBitfield;
            
            return static_cast<clear_mask> (outBitfield);
        }

        clear_mask& operator|=(clear_mask& lhs, clear_mask rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield | rhsBitfield;
            
            lhs = static_cast<clear_mask> (outBitfield);
            
            return lhs;
        }

        clear_mask& operator&=(clear_mask& lhs, clear_mask rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield & rhsBitfield;
            
            lhs = static_cast<clear_mask> (outBitfield);
            
            return lhs;
        }

        clear_mask& operator^=(clear_mask& lhs, clear_mask rhs) {
            auto lhsBitfield = static_cast<gloop::bitfield_t> (lhs);
            auto rhsBitfield = static_cast<gloop::bitfield_t> (rhs);
            auto outBitfield = lhsBitfield ^ rhsBitfield;
            
            lhs = static_cast<clear_mask> (outBitfield);
            
            return lhs;
        }

		std::ostream& operator<<(std::ostream& os, clear_mask m) {
			switch (m) {
				case clear_mask::NONE:
					return os << "NONE";
				case clear_mask::COLOR:
					return os << "COLOR";
				case clear_mask::DEPTH:
					return os << "DEPTH";
				case clear_mask::STENCIL:
					return os << "STENCIL";
				default:
					os << "[";
                    
                    auto apply = [] (std::ostream& os, clear_mask lhs, clear_mask rhs, bool applyPipe) {
                        if (hasFlag(lhs, rhs)) {
                            if (applyPipe) {
                                os << " | ";                                
                            }
                            
                            os << lhs;
                            return true;
                        }
                        
                        return false;
                    };
                    
                    bool applyPipe = apply(os, m, clear_mask::COLOR, false);
                    applyPipe = apply(os, m, clear_mask::DEPTH, applyPipe);
                    applyPipe = apply(os, m, clear_mask::STENCIL, applyPipe);
                    
                    os << "]";

					return os;
			}
		}
    }
}
