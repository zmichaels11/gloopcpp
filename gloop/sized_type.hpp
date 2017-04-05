/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include "type.hpp"

namespace gloop {
    struct sized_type {
        type type;
        GLint size;
    };
}