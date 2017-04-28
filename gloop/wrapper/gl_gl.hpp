/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gl_gl.hpp
 * Author: zmichaels
 *
 * Created on April 28, 2017, 8:53 AM
 */

#ifndef GL_GL_HPP
#define GL_GL_HPP

#include <functional>
#include <string>

#include "../glint.hpp"

namespace gloop {
    namespace wrapper {        
        struct gl20 {            
            std::function<void(gloop::enum_t, gloop::uint_t)> bindBuffer;
            std::function<void(gloop::enum_t, gloop::sizeiptr_t, const void *, gloop::enum_t)> bufferData;
            std::function<void(gloop::sizei_t, gloop::uint_t *)> genBuffers;
            std::function<void(gloop::sizei_t, const gloop::uint_t *)> deleteBuffers;
            std::function<void * (gloop::enum_t, gloop::enum_t)> mapBuffer;
            std::function<void * (gloop::enum_t, gloop::intptr_t, gloop::sizeiptr_t, gloop::bitfield_t)> mapBufferRange;
            std::function<gloop::boolean_t(gloop::enum_t)> unmapBuffer; 
            std::function<void(gloop::enum_t, gloop::intptr_t, gloop::sizeiptr_t, const void *)> bufferSubData;
            std::function<void(gloop::enum_t, gloop::intptr_t, gloop::sizeiptr_t, void *)> getBufferSubData;
            
            std::function<void(gloop::enum_t, gloop::int_t, gloop::sizei_t)> drawArrays;
            std::function<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, const void *)> drawElements;
            std::function<void(gloop::enum_t, gloop::uint_t, gloop::uint_t, gloop::sizei_t, gloop::enum_t, const void*)> drawRangeElements;
            
            std::function<void(gloop::uint_t, gloop::enum_t, gloop::int_t *)> getShaderiv;
            std::function<void(gloop::uint_t, gloop::sizei_t, gloop::sizei_t *, gloop::char_t *)> getShaderInfoLog;
            std::function<gloop::uint_t(gloop::enum_t)> createShader;
            std::function<void(gloop::uint_t, gloop::sizei_t, const gloop::char_t **, const gloop::int_t *)> shaderSource;
            std::function<void(gloop::uint_t)> compileShader;
            std::function<void(gloop::uint_t)> deleteShader;
            std::function<void(gloop::uint_t, gloop::enum_t, gloop::int_t *)> getProgramiv;
            std::function<void(gloop::uint_t, gloop::sizei_t, gloop::sizei_t *, gloop::char_t *)> getProgramInfoLog;
            std::function<void(gloop::uint_t)> useProgram;
            std::function<gloop::uint_t()> createProgram;
            std::function<void(gloop::uint_t, gloop::uint_t)> attachShader;
            std::function<void(gloop::uint_t, gloop::uint_t)> detachShader;
            std::function<void(gloop::uint_t)> linkProgram;
            std::function<void(gloop::uint_t)> deleteProgram;
            std::function<gloop::int_t(gloop::uint_t, const gloop::char_t *)> getUniformLocation;
            std::function<void(gloop::uint_t, gloop::uint_t, const gloop::char_t *)> bindAttribLocation;
            
            std::function<void(gloop::int_t, gloop::sizei_t, const gloop::float_t *)> uniform1fv;
            std::function<void(gloop::int_t, gloop::sizei_t, const gloop::float_t *)> uniform2fv;
            std::function<void(gloop::int_t, gloop::sizei_t, const gloop::float_t *)> uniform3fv;
            std::function<void(gloop::int_t, gloop::sizei_t, const gloop::float_t *)> uniform4fv;
            
            std::function<void(gloop::int_t, gloop::sizei_t, const gloop::int_t *)> uniform1iv;
            std::function<void(gloop::int_t, gloop::sizei_t, const gloop::int_t *)> uniform2iv;
            std::function<void(gloop::int_t, gloop::sizei_t, const gloop::int_t *)> uniform3iv;
            std::function<void(gloop::int_t, gloop::sizei_t, const gloop::int_t *)> uniform4iv;
            
            std::function<void(gloop::int_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)> uniformMatrix2fv;
            std::function<void(gloop::int_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)> uniformMatrix3fv;
            std::function<void(gloop::int_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)> uniformMatrix4fv;
            
            std::function<void(gloop::enum_t)> enable;
            std::function<void(gloop::enum_t)> disable;
            std::function<void(gloop::enum_t, gloop::enum_t, gloop::enum_t, gloop::enum_t)> blendFuncSeparate;
            std::function<void(gloop::enum_t, gloop::enum_t)> blendEquationSeparate;
            std::function<void(gloop::bitfield_t)> clear;
            std::function<void(gloop::double_t, gloop::double_t)> depthRange;
            std::function<void(gloop::int_t, gloop::int_t, gloop::sizei_t, gloop::sizei_t)> scissor;
            std::function<void(gloop::int_t, gloop::int_t, gloop::sizei_t, gloop::sizei_t)> viewport;
            std::function<void(gloop::float_t, gloop::float_t, gloop::float_t, gloop::float_t)> clearColor;
            std::function<void(gloop::double_t)> clearDepth;
            std::function<void(gloop::int_t)> clearStencil;
            
            std::function<void(gloop::enum_t, gloop::uint_t)> bindTexture;
            std::function<void(gloop::enum_t, gloop::enum_t, gloop::float_t)> texParameterf;
            std::function<void(gloop::enum_t, gloop::enum_t, gloop::int_t)> texParameteri;
            std::function<void(gloop::sizei_t, gloop::uint_t *)> genTextures;
            std::function<void(gloop::sizei_t, gloop::uint_t *)> deleteTextures; 
            std::function<void(gloop::enum_t, gloop::int_t, gloop::int_t, gloop::sizei_t, gloop::sizei_t, gloop::int_t, gloop::enum_t, gloop::enum_t, const void *)> texImage2D;
            
            gl20();
        };
        
        struct gl30 {
            std::function<void(gloop::enum_t, gloop::uint_t, gloop::uint_t)> bindBufferBase;
            std::function<void(gloop::enum_t, gloop::uint_t, gloop::uint_t, gloop::intptr_t, gloop::sizeiptr_t)> bindBufferRange;
            
            std::function<void(gloop::sizei_t, gloop::uint_t *)> genRenderbuffers;
            std::function<void(gloop::sizei_t, gloop::uint_t *)> deleteRenderbuffers;
            std::function<void(gloop::enum_t, gloop::uint_t)> bindRenderbuffer;
            std::function<void(gloop::enum_t, gloop::enum_t, gloop::sizei_t, gloop::sizei_t)> renderbufferStorage;
            std::function<void(gloop::sizei_t, gloop::uint_t *)> genFramebuffers;
            std::function<void(gloop::sizei_t, gloop::uint_t *)> deleteFramebuffers;
            std::function<void(gloop::enum_t, gloop::enum_t, gloop::enum_t, gloop::uint_t)> framebufferRenderbuffer;
            std::function<void(gloop::enum_t, gloop::uint_t)> bindFramebuffer;
          
            gl30();
        };                
        
        struct gl31 {
            std::function<void(gloop::enum_t, gloop::int_t, gloop::sizei_t, gloop::sizei_t)> drawArraysInstanced;
            std::function<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, const void *, gloop::sizei_t)> drawElementsInstanced;
            std::function<gloop::uint_t(gloop::uint_t, const gloop::char_t *)> getUniformBlockIndex;
            std::function<void(gloop::uint_t, gloop::uint_t, gloop::uint_t)> uniformBlockBinding;
            
            gl31();
        };
        
        struct gl32 {
            std::function<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, const void *, gloop::int_t)> drawElementsBaseVertex;
            std::function<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, void *, gloop::sizei_t, gloop::int_t)> drawElementsInstancedBaseVertex;
            std::function<void(gloop::enum_t, gloop::enum_t, gloop::uint_t, gloop::int_t)> framebufferTexture;
            
            gl32();
        };
        
        struct gl40 {
            std::function<void(gloop::enum_t, const void *)> drawArraysIndirect;
            std::function<void(gloop::enum_t, gloop::enum_t, const void *)> drawElementsIndirect;
            
            gl40();
        };
        
        struct gl41 {
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t *)> programUniform1fv;
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t *)> programUniform2fv;
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t *)> programUniform3fv;
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::float_t *)> programUniform4fv;
            
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t *)> programUniform1iv;
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t *)> programUniform2iv;
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t *)> programUniform3iv;
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, const gloop::int_t *)> programUniform4iv;
            
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)> programUniformMatrix2fv;
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)> programUniformMatrix3fv;
            std::function<void(gloop::uint_t, gloop::int_t, gloop::sizei_t, gloop::boolean_t, const gloop::float_t *)> programUniformMatrix4fv;
            
            gl41();
        };
        
        struct gl42 {
            std::function<void(gloop::enum_t, gloop::sizei_t, gloop::enum_t, gloop::sizei_t, gloop::sizei_t)> texStorage2D;
        };
        
        struct gl43 {
            std::function<void(gloop::uint_t, gloop::uint_t, gloop::uint_t)> dispatchCompute;
            std::function<void(gloop::intptr_t)> dispatchComputeIndirect;
            
            gl43();
        };
        
        struct gl45 {            
            std::function<void(gloop::uint_t, gloop::sizeiptr_t, const void *, gloop::enum_t)> namedBufferData;
            std::function<void(gloop::sizei_t, gloop::uint_t *)> createBuffers;           
            std::function<void * (gloop::uint_t, gloop::enum_t)> mapNamedBuffer;
            std::function<void * (gloop::uint_t, gloop::intptr_t, gloop::sizeiptr_t, gloop::bitfield_t)> mapNamedBufferRange;
            std::function<gloop::boolean_t(gloop::uint_t)> unmapNamedBuffer; 
            std::function<void(gloop::uint_t, gloop::intptr_t, gloop::sizeiptr_t, const void *)> namedBufferSubData;            
            std::function<void(gloop::uint_t, gloop::intptr_t, gloop::sizei_t, void *)> getNamedBufferSubData;
            
            std::function<void(gloop::sizei_t, gloop::uint_t *)> createRenderbuffers;
            std::function<void(gloop::uint_t, gloop::enum_t, gloop::sizei_t, gloop::sizei_t)> namedRenderbufferStorage;
            std::function<void(gloop::sizei_t, gloop::uint_t *)> createFramebuffers;
            std::function<void(gloop::uint_t, gloop::enum_t, gloop::enum_t, gloop::uint_t)> namedFramebufferRenderbuffer;
            std::function<void(gloop::uint_t, gloop::enum_t, gloop::uint_t, gloop::int_t)> namedFramebufferTexture;
            
            std::function<void(gloop::uint_t, gloop::enum_t, gloop::float_t)> textureParameterf;
            std::function<void(gloop::uint_t, gloop::enum_t, gloop::int_t)> textureParameteri;
            std::function<void(gloop::enum_t, gloop::sizei_t, gloop::uint_t *)> createTextures;
            std::function<void(gloop::uint_t, gloop::sizei_t, gloop::enum_t, gloop::sizei_t, gloop::sizei_t)> textureStorage2D;
            
            gl45();
        };
        
        struct arb_bindless_texture {
            std::function<gloop::uint64_t(gloop::uint_t)> getTextureHandleARB;
            std::function<void(gloop::uint64_t)> makeTextureHandleResident;
            std::function<void(gloop::uint64_t)> makeTextureHandleNonResident;
        };
        
        extern const gl20 * GL20;
        extern const gl30 * GL30;
        extern const gl31 * GL31;
        extern const gl40 * GL40;
        extern const gl41 * GL41;
        extern const gl43 * GL43;
        extern const gl45 * GL45;
    }
}

#endif /* GL_GL_HPP */

