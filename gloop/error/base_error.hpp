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
    namespace error {

        class base_error : public std::exception {
        private:
            const std::string _msg;

        public:

            base_error(std::string msg) : _msg(msg) {
            }

            base_error() : _msg("An OpenGL error occurred! The GLContext is now invalid.") {
            }

            virtual const char * what() const throw ();
                        
            friend std::ostream& operator<<(std::ostream& os, const base_error& err);
        };
        
        inline std::ostream& operator<<(std::ostream& os, const base_error& err) {
            os << err._msg;
            return os;
        }
    }
}
