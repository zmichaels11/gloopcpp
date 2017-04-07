/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   glint.hpp
 * Author: zmichaels
 *
 * Created on April 6, 2017, 9:23 AM
 */

#pragma once

#include <cstdint>

// based on khrplatform.h and gl2.h

namespace gloop {
    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef signed short int int16_t;
    typedef unsigned short int uint16_t;
    typedef std::int32_t int32_t;
    typedef std::uint32_t uint32_t;    
    typedef std::int64_t int64_t;
    typedef std::uint64_t uint64_t;
    
#ifdef _WIN64
    typedef signed long long int intptr_t;
    typedef unsigned long long int uintptr_t;
    typedef signed long long int ssize_t;
    typedef unsigned long long int usize_t;
#else
    typedef signed long int intptr_t;
    typedef unsigned long int uintptr_t;
    typedef signed long int ssize_t;
    typedef unsigned long int usize_t;
#endif
    
    typedef float float_t;
    typedef int8_t byte_t;
    typedef float_t clampf_t;
    typedef int32_t fixed_t;
    typedef short short_t;
    typedef unsigned short ushort_t;
    typedef void void_t;
    typedef unsigned int enum_t;
    typedef unsigned int uint_t;
    typedef char char_t;
    typedef ssize_t sizeiptr_t;
    typedef unsigned int bitfield_t;
    typedef int int_t;
    typedef unsigned char boolean_t;
    typedef int sizei_t;
    typedef uint8_t ubyte_t;
}