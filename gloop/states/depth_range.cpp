/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "depth_range.hpp"

#include <iostream>

#include "../wrapper/states.hpp"

namespace gloop {
    namespace states {

        void depth_range::apply() const {
            gloop::wrapper::depthRange(near, far);
        }

        
    }
}