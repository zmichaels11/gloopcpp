/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "../glint.hpp"
#include "call.hpp"
#include "index_type.hpp"
#include "mode.hpp"

namespace gloop {
    namespace draw {
        struct elements_base_vertex : draw_call {
            mode drawMode;
            gloop::sizei_t count;
            index_type indexType;
            const void * indices;
            gloop::int_t baseVertex;            

            virtual void draw() const;
        };
    }
}