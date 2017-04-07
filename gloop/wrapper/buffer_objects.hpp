/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer_objects.hpp
 * Author: zmichaels
 *
 * Created on April 7, 2017, 2:49 PM
 */

#pragma once

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {
        void bindBuffer(
                gloop::enum_t target,
                gloop::uint_t buffer);

        void namedBufferData(
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::enum_t usage);

        void namedBufferStorage(
                gloop::uint_t buffer,
                gloop::sizeiptr_t size,
                const void * data,
                gloop::bitfield_t flags);

        void createBuffers(
                gloop::sizei_t n,
                gloop::uint_t * buffers);

        void deleteBuffers(
                gloop::sizei_t n,
                const gloop::uint_t * buffers);

        void bindBufferBase(
                gloop::enum_t target,
                gloop::uint_t buffer);

        void bindBufferRange(
                gloop::enum_t target,
                gloop::uint_t index,
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size);

        void namedBufferSubData(
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t size,
                const void * data);

        void getNamedBufferSubData(
                gloop::uint_t buffer,
                gloop::intptr_t offset,
                gloop::sizeiptr_t size,
                void * data);

        void * mapNamedBufferRange(
                gloop::uint_t buffer,
                gloop::intptr_t offset, gloop::sizeiptr_t length,
                gloop::bitfield_t access);

        void unmapNamedBuffer(gloop::uint_t buffer);
    }
}