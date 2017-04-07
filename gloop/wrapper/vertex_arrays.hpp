/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vertex_arrays.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 4:25 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        void createVertexArrays(gloop::sizei_t n, gloop::uint_t * arrays);
        
        void bindVertexArray(gloop::uint_t vertexArray);
        
        void enableVertexAttribArray(gloop::uint_t attrib);
        
        void disableVertexAttribArray(gloop::uint_t attrib);
        
        void deleteVertexArrays(gloop::sizei_t n, const gloop::uint_t * arrays);
        
        void vertexAttribDivisor(gloop::uint_t index, gloop::uint_t divisor);
        
        void vertexAttribPointer(gloop::uint_t index, gloop::int_t size, gloop::enum_t type, gloop::boolean_t normalized, gloop::sizei_t stride, const void * pointer);
        
        void vertexAttribIPointer(gloop::uint_t index, gloop::int_t size, gloop::enum_t type, gloop::sizei_t stride, const void * pointer);                
    }
}