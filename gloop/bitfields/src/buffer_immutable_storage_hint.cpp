/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "buffer_immutable_storage_hint.hpp"

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
    }
}