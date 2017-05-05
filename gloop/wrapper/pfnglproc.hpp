/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pfnglproc.hpp
 * Author: zmichaels
 *
 * Created on May 5, 2017, 8:53 AM
 */

#pragma once

#include <functional>
#include <iostream>
#include <string>

#include <SDL2/SDL_video.h>

namespace gloop {
    namespace wrapper {

        template <typename T>
        class pfnglproc {
            std::string _fName;
            std::function<T> _func;

            enum class state {
                UNCHECKED,
                UNSUPPORTED,
                SUPPORTED
            };

            state _state;

            bool init() {
                auto addr = SDL_GL_GetProcAddress(_fName.c_str());

#if defined(WIN32) || defined(_WIN32) || defined (__WIN32) && !defined(__CYGWIN__)
                _func = std::function<T>(reinterpret_cast<__stdcall T*> (addr));
#else
                _func = std::function<T>(reinterpret_cast<T*> (addr));
#endif                
                
                if (_func == nullptr) {
                    _state = state::UNSUPPORTED;
                    return false;
                } else {
                    _state = state::SUPPORTED;
                    return true;
                }
            }
            
            bool check() {
                switch (_state) {
                    case state::UNCHECKED:
                        return init();                        
                    case state::SUPPORTED:
                        return true;
                    case state::UNSUPPORTED:
                        return false;
                    default:
                        return false;
                }
            }

        public:

            pfnglproc(const std::string& name) :
            _fName(name),
            _func(nullptr),
            _state(state::UNCHECKED) {
            }
            
            pfnglproc(const pfnglproc<T>&) = delete;
            pfnglproc(pfnglproc<T>&&) = delete;

            operator bool() {
                return check();
            }

            const std::function<T>& operator*() {
                check();

                return _func;
            }
        };
    }
}