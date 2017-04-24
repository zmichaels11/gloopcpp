/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   draw_command.hpp
 * Author: zmichaels
 *
 * Created on April 21, 2017, 3:03 PM
 */

#pragma once

namespace glgfx {

    struct draw_command {
        virtual void draw() = 0;
    };
}