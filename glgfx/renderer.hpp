/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   renderer.hpp
 * Author: zmichaels
 *
 * Created on April 21, 2017, 2:58 PM
 */

#pragma once

namespace glgfx {
    struct renderer {
        virtual void flush() = 0;
    };
}