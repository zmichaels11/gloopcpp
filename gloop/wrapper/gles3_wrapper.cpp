/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "glext.hpp"

#include <cstring>
#include <functional>

#include "../glint.hpp"
#include "pfnglproc.hpp"
#include "glversion.hpp"

extern const gloop::ubyte_t * glGetString(gloop::enum_t);

namespace {

    static bool hasExtension(const char * ext) {
        constexpr gloop::enum_t EXTENSIONS = 0x1F03;

        static gloop::wrapper::pfnglproc <const gloop::char_t * (gloop::enum_t) > getString("glGetString");
        static auto extensions = reinterpret_cast<const char *> ((*getString) (EXTENSIONS));

        return std::strstr(extensions, ext);
    }
}

namespace gloop {
    namespace wrapper {

        glext::operator bool() {
            switch (_state) {
                case state::UNCHECKED:
                    if (hasExtension(_extName.c_str())) {
                        _state = state::SUPPORTED;
                        return true;
                    } else {
                        _state = state::UNSUPPORTED;
                        return false;
                    }
                case state::SUPPORTED:
                    return true;
                case state::UNSUPPORTED:
                    return false;
            }
        }

        glversion::operator bool() {
            switch (_state) {
                case state::UNCHECKED:
                {
                    constexpr gloop::enum_t GL_MAJOR_VERSION = 0x821B;
                    constexpr gloop::enum_t GL_MINOR_VERSION = 0x821C;
                    
                    static pfnglproc<void(gloop::enum_t, gloop::int_t *)> getIntegerv("glGetIntegerv");
                    
                    gloop::int_t major = 0;
                    gloop::int_t minor = 0;

                    (*getIntegerv) (GL_MAJOR_VERSION, &major);
                    (*getIntegerv) (GL_MINOR_VERSION, &minor);

                    if (major > _major) {
                        _state = state::SUPPORTED;
                        return true;
                    } else if (major == _major) {
                        if (minor >= _minor) {
                            _state = state::SUPPORTED;
                            return true;
                        } else {
                            _state = state::UNSUPPORTED;
                            return false;
                        }
                    } else {
                        _state = state::UNSUPPORTED;
                        return false;
                    }
                }
                case state::SUPPORTED:
                    return true;
                case state::UNSUPPORTED:
                    return false;
            }
        }
    }
}

