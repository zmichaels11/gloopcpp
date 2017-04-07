/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace draw {
        enum class index_type : gloop::enum_t {
            UNSIGNED_BYTE = 0x1401,
            UNSIGNED_SHORT = 0x1403,
            UNSIGNED_INT = 0x1405
        };
    }
}