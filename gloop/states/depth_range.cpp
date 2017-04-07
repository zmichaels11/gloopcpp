/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "depth_range.hpp"

#include <GL/glew.h>

namespace gloop {
    void depth_range::apply() const {
        glDepthRange(near, far);
    }
}