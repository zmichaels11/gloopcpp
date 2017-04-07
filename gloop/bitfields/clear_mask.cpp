/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "clear_mask.hpp"

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
    }
}