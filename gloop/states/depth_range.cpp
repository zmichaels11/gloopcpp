/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "depth_range.hpp"

#include "../wrapper/states.hpp"

namespace gloop {
    void depth_range::apply() const {
        gloop::wrapper::depthRange(near, far);
    }
}