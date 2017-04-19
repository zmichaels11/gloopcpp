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

        void drawArraysInstanced(
                gloop::enum_t mode,
                gloop::int_t first,
                gloop::sizei_t count,
                gloop::sizei_t instanceCount);

        void drawArraysIndirect(
                gloop::enum_t mode,
                const void * indirect);

        void drawElements(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices);

        void drawElementsInstanced(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices,
                gloop::sizei_t instanceCount);

        void drawRangeElements(
                gloop::enum_t mode,
                gloop::uint_t starg, gloop::uint_t end,
                gloop::sizei_t count,
                gloop::enum_t type, const void * indices);

        void drawElementsBaseVertex(
                gloop::enum_t mode,
                gloop::uint_t start,
                gloop::uint_t end,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices,
                gloop::int_t baseVertex);

        void drawElementsInstancedBaseVertex(
                gloop::enum_t mode,
                gloop::sizei_t count,
                gloop::enum_t type,
                const void * indices,
                gloop::sizei_t instanceCount,
                gloop::int_t baseVertex);

        void drawElementsIndirect(
                gloop::enum_t mode,
                gloop::enum_t type,
                const void * indices);

        void dispatchCompute(
                gloop::uint_t numGroupsX,
                gloop::uint_t numGroupsY,
                gloop::uint_t numGroupsZ);
        
        void dispatchComputeIndirect(gloop::intptr_t indirect);
    }
}