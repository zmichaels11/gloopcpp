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

#include "../glint.hpp"

#include "pfnglproc.hpp"
#include "glext.hpp"
#include "glversion.hpp"

namespace gloop {
    namespace wrapper {
        struct ext_buffer_storage_support_t {
            glext support;
            pfnglproc<void(gloop::enum_t, gloop::sizeiptr_t, const void *, gloop::bitfield_t)> bufferStorageEXT;
            
            ext_buffer_storage_support_t() :
            support("EXT_buffer_storage"),
            bufferStorageEXT("glBufferStorageEXT") {}
            
            operator bool() {
                return support;
            }
        };
        
        extern ext_buffer_storage_support_t EXT_buffer_storage;

        struct gles30_support_t {
            glversion support;

            gles30_support_t() :
            support(3, 0) {
            }

            operator bool() {
                return support;
            }
        };

        extern gles30_support_t GLES30;

        struct gles31_support_t {
            glversion support;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t *) > programUniform1iv;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t *) > programUniform2iv;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t *) > programUniform3iv;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t *) > programUniform4iv;

            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t *) > programUniform1fv;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t *) > programUniform2fv;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t *) > programUniform3fv;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t *) > programUniform4fv;

            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *) > programUniformMatrix2fv;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *) > programUniformMatrix3fv;
            pfnglproc<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *) > programUniformMatrix4fv;

            pfnglproc<void(gloop::enum_t, const void*) > drawArraysIndirect;
            pfnglproc<void(gloop::enum_t, gloop::enum_t, const void*) > drawElementsIndirect;

            gles31_support_t() :
            support(3, 1),
            programUniform1iv("glProgramUniform1iv"),
            programUniform2iv("glProgramUniform2iv"),
            programUniform3iv("glProgramUniform3iv"),
            programUniform4iv("glProgramUniform4iv"),
            programUniform1fv("glProgramUniform1fv"),
            programUniform2fv("glProgramUniform2fv"),
            programUniform3fv("glProgramUniform3fv"),
            programUniform4fv("glProgramUniform4fv"),
            programUniformMatrix2fv("glProgramUniformMatrix2fv"),
            programUniformMatrix3fv("glProgramUniformMatrix3fv"),
            programUniformMatrix4fv("glProgramUniformMatrix4fv"),
            drawArraysIndirect("glDrawArraysIndirect"),
            drawElementsIndirect("glDrawElementsIndirect") {
            }

            operator bool() {
                return support;
            }
        };

        extern gles31_support_t GLES31;

        struct gles32_support_t {
            glversion support;

            pfnglproc<void(gloop::uint_t, gloop::uint_t, gloop::uint_t) > dispatchCompute;
            pfnglproc<void(gloop::intptr_t) > dispatchComputeIndirect;

            gles32_support_t() :
            support(3, 2),
            dispatchCompute("glDispatchCompute"),
            dispatchComputeIndirect("glDispatchComputeIndirect") {
            }
            
            operator bool() {
                return support;
            }
        };
        
        extern gles32_support_t GLES32;
    }
}

#endif
#undef GLES3