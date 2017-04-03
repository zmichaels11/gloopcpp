/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tools.hpp"

#include <string>
#include <istream>
#include <sstream>

std::string gloop::tools::readAll(const std::istream& in) {
    if (in) {
        std::ostringstream contents;
        
        contents << in.rdbuf();
        contents << std::endl;
        
        return contents.str();
    } else {
        throw "Unable to read contents of stream!";
    }
}

std::string gloop::tools::readAll(std::ifstream& in) {
    if (in) {
        std::ostringstream contents;
        
        contents << in.rdbuf();
        contents << std::endl;
        
        in.close();
        
        return contents.str();
    } else {
        throw "Unable to read contents of file input stream!";
    }
}