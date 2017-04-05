/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <string>
#include <istream>
#include <fstream>

namespace gloop {
    namespace tools {
        std::string readAll(const std::istream& in);

        std::string readAll(std::ifstream& in);
        
        void assertGLError(std::string customMsg);
        
        void assertGLError();
    }
}
