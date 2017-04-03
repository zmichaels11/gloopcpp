/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tools.hpp
 * Author: zmichaels
 *
 * Created on April 3, 2017, 9:56 AM
 */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <istream>
#include <fstream>

namespace gloop {
    namespace tools {
        std::string readAll(const std::istream& in);

        std::string readAll(std::ifstream& in);
    }
}

#endif /* TOOLS_HPP */

