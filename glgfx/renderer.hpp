/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   renderer.hpp
 * Author: zmichaels
 *
 * Created on April 26, 2017, 5:00 PM
 */

#pragma once

namespace glgfx {
    class renderer {
	public:
        virtual void flush() = 0;
        
        virtual void reset() = 0;
    };
}
