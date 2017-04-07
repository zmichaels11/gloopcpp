/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   drawing_commands.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 2:26 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        void drawArrays(
                gloop::enum_t mode,
                gloop::int_t first,
                gloop::sizei_t count);

        void drawElements(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices);

        void drawArraysInstanced(
                gloop::enum_t mode,
                gloop::int_t first,
                gloop::sizei_t count,
                gloop::sizei_t instanceCount);

        void drawElementsInstanced(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices,
                gloop::sizei_t instanceCount);
    }
}