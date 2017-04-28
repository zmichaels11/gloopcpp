/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gl_gles3.hpp
 * Author: zmichaels
 *
 * Created on April 19, 2017, 1:23 PM
 */

#pragma once

#define GLES3 3
#if GL == GLES3

#include <functional>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {        
        // EXT_buffer_storage
        extern const std::function<void(gloop::enum_t, gloop::sizeiptr_t, const void *, gloop::bitfield_t)>& glBufferStorageEXT;
        extern const bool& EXT_buffer_storage;
        
        extern const bool& OPENGLES_3_0;
        
        // OpenGLES 3.1
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::int_t)>& glProgramUniform1i;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::int_t, gloop::int_t)>& glProgramUniform2i;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::int_t, gloop::int_t, gloop::int_t)>& glProgramUniform3i;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::int_t, gloop::int_t, gloop::int_t, gloop::int_t)>& glProgramUniform4i;
        
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::float_t)>& glProgramUniform1f;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::float_t, gloop::float_t)>& glProgramUniform2f;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::float_t, gloop::float_t, gloop::float_t)>& glProgramUniform3f;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::float_t, gloop::float_t, gloop::float_t, gloop::float_t)>& glProgramUniform4f;
        
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t*)>& glProgramUniform1iv;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t*)>& glProgramUniform2iv;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t*)>& glProgramUniform3iv;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t*)>& glProgramUniform4iv;
        
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t*)>& glProgramUniform1fv;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t*)>& glProgramUniform2fv;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t*)>& glProgramUniform3fv;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t*)>& glProgramUniform4fv;
        
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)>& glProgramUniformMatrix2fv;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)>& glProgramUniformMatrix3fv;
        extern const std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)>& glProgramUniformMatrix4fv;               
                
        extern const std::function<void(gloop::enum_t, const void*)>& glDrawArraysIndirect;
        extern const std::function<void(gloop::enum_t, gloop::enum_t, const void*)>& glDrawElementsIndirect;                
        
        extern const bool& OPENGLES_3_1;
        
        extern const std::function<void(gloop::uint_t, gloop::uint_t, gloop::uint_t)>& glDispatchCompute;
        
        extern const std::function<void(gloop::intptr_t)>& glDispatchComputeIndirect;
        
        extern const bool& OPENGLES_3_2;
        
        extern const std::function<gloop::uint64_t(gloop::uint_t)>& glGetTextureHandleNV;
        extern const std::function<void(gloop::uint64_t)>& glMakeTextureHandleResidentNV;
        extern const std::function<void(gloop::uint64_t)>& glMakeTextureHandleNonResidentNV;
        
        extern const bool& NV_bindless_texture;
    }
}

#endif
#undef GLES3