/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sprite.hpp
 * Author: zmichaels
 *
 * Created on April 24, 2017, 4:13 PM
 */

#pragma once

#include <array>

namespace gloop {
    class texture2D;
}

namespace glgfx {
    enum class blend_mode : unsigned int;

    struct sprite {

        struct texture_data {
            float u0;
            float v0;
            float u1;
            float v1;
            gloop::texture2D * texture;
        } * textureData;

        std::array<float, 16> transformation;

        std::array<float, 25> colorTransform;

        bool hasColorTransform;

        blend_mode blendMode;
    };
}