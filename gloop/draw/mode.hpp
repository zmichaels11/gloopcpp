/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace draw {

        enum class mode : gloop::enum_t {
            POINTS = 0x0000,
            LINE_STRIP = 0x0003,
            LINE_LOOP = 0x0002,
            LINES = 0x0001,
            LINE_STRIP_ADJACENCY = 0x000B,
            LINES_ADJACENCY = 0x000A,
            TRIANGLE_STRIP = 0x0005,
            TRIANGLE_FAN = 0x0006,
            TRIANGLES = 0x0004,
            TRIANGLE_STRIP_ADJACENCY = 0x000D,
            TRIANGLES_ADJACENCY = 0x000C,
            PATCHES = 0x000E
        };
    }
}