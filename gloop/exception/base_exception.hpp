/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <exception>
#include <iostream>
#include <string>

namespace gloop {
    namespace exception {
        class base_exception : public std::exception {
        private:
            const std::string _msg;

        public:

            base_exception(std::string msg) : _msg(msg) {
            }

            base_exception() : _msg("An OpenGL exception occurred! The offending operation was ignored.") {
            }

            virtual const char * what() const throw ();
            
            friend std::ostream& operator<< (std::ostream& os, const base_exception& ex);
        };
        
        inline std::ostream& operator<<(std::ostream& os, const base_exception& ex) {
            os << ex._msg;
            return os;
        }
    }
}