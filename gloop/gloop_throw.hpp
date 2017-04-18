/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   glthrow.hpp
 * Author: zmichaels
 *
 * Created on April 10, 2017, 4:21 PM
 */

#pragma once

#include "errors.hpp"
#include "exceptions.hpp"

#ifdef __EMSCRIPTEN__
#include <iostream>
#define gloop_throw(ex) std::cout << ex << std::endl; std::terminate()
#else
#define gloop_throw(ex) throw ex
#endif