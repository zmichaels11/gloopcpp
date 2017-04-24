/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <cstddef>
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "glint.hpp"

namespace gloop {
    
    class shader;
    class vertex_attributes;
    
    namespace uniform {
        class uniform_block_binding;
        class uniform_float_binding;
        class uniform_int_binding;
        class uniform_vec2_binding;
        class uniform_vec3_binding;
        class uniform_vec4_binding;
        class uniform_ivec2_binding;
        class uniform_ivec3_binding;
        class uniform_ivec4_binding;
        class uniform_int_array_binding;
        class uniform_float_array_binding;
        class uniform_vec2_array_binding;
        class uniform_vec3_array_binding;
        class uniform_vec4_array_binding;
        class uniform_ivec2_array_binding;
        class uniform_ivec3_array_binding;
        class uniform_ivec4_array_binding;
        class uniform_mat2_binding;
        class uniform_mat3_binding;
        class uniform_mat4_binding;
    }
    
    class program {
    private:
        gloop::uint_t _id;
        std::unique_ptr<vertex_attributes> _attribs;
        std::map<std::string, gloop::uint_t> _uniforms;
        std::map<std::string, uniform::uniform_block_binding> _uniformBlocks;
        gloop::uint_t getUniform(const std::string& uniformName);

    public:

        program();
        
        ~program();

        program(const program&) = delete;

        program(program&&) = default;
        
        program& operator=(const program&) = delete;
        
        program& operator=(program&&) = default;                

        void setVertexAttributes(const vertex_attributes& attribs);
        
        const vertex_attributes& getVertexAttributes() const;

        void linkShaders(shader * shaders, const std::size_t count);

        gloop::uint_t getId() const;

        bool isInitialized() const;

        void use() const;

        void free();

        operator bool() const;

        const uniform::uniform_block_binding bindUniformBlock(const std::string& uniformName);

        const uniform::uniform_block_binding getUniformBlock(const std::string& uniformName) const;

        const uniform::uniform_float_binding getUniformFloatBinding(
                const std::string& uniformName,
                const gloop::float_t x);

        const uniform::uniform_float_array_binding getUniformFloatArrayBinding(
                const std::string& uniformName,
                const gloop::float_t * values,
                const gloop::sizei_t count);

        const uniform::uniform_int_binding getUniformIntBinding(
                const std::string& uniformName,
                const gloop::int_t x);

        const uniform::uniform_int_array_binding getUniformIntArrayBinding(
                const std::string& uniformName,
                const gloop::int_t * values,
                const gloop::sizei_t count);

        const uniform::uniform_vec2_binding getUniformVec2Binding(
                const std::string& uniformName,
                const gloop::float_t x,
                const gloop::float_t y);

        const uniform::uniform_vec2_array_binding getUniformVec2ArrayBinding(
                const std::string& uniformName,
                const gloop::float_t * values,
                const gloop::sizei_t count);

        const uniform::uniform_vec3_binding getUniformVec3Binding(
                const std::string& uniformName,
                const gloop::float_t x,
                const gloop::float_t y,
                const gloop::float_t z);

        const uniform::uniform_vec3_array_binding getUniformVec3ArrayBinding(
                const std::string& uniformName,
                const gloop::float_t * values,
                const gloop::sizei_t count);

        const uniform::uniform_vec4_binding getUniformVec4Binding(
                const std::string& uniformName,
                const gloop::float_t x,
                const gloop::float_t y,
                const gloop::float_t z,
                const gloop::float_t w);

        const uniform::uniform_vec4_array_binding getUniformVec4ArrayBinding(
                const std::string& uniformName,
                const gloop::float_t * values,
                const gloop::sizei_t count);

        const uniform::uniform_ivec2_binding getUniformIVec2Binding(
                const std::string& uniformName,
                const gloop::int_t x,
                const gloop::int_t y);

        const uniform::uniform_ivec3_binding getUniformIVec3Binding(
                const std::string& uniformName,
                const gloop::int_t x,
                const gloop::int_t y,
                const gloop::int_t z);

        const uniform::uniform_ivec4_binding getUniformIVec4Binding(
                const std::string& uniformName,
                const gloop::int_t x,
                const gloop::int_t y,
                const gloop::int_t z,
                const gloop::int_t w);

        const uniform::uniform_ivec2_array_binding getUniformIVec2ArrayBinding(
                const std::string& uniformName,
                const gloop::int_t * values,
                const gloop::sizei_t count);

        const uniform::uniform_ivec3_array_binding getUniformIVec3ArrayBinding(
                const std::string& uniformName,
                const gloop::int_t * values,
                const gloop::sizei_t count);

        const uniform::uniform_ivec4_array_binding getUniformIVec4ArrayBinding(
                const std::string& uniformName,
                const gloop::int_t * values,
                const gloop::sizei_t count);

        const uniform::uniform_mat2_binding getUniformMat2Binding(
                const std::string& uniformName,
                const gloop::float_t * values,
                const gloop::sizei_t count = 1);

        const uniform::uniform_mat3_binding getUniformMat3Binding(
                const std::string& uniformName,
                const gloop::float_t * values,
                const gloop::sizei_t count = 1);

        const uniform::uniform_mat4_binding getUniformMat4Binding(
                const std::string& uniformName,
                const gloop::float_t * values,
                const gloop::sizei_t count = 1);
    };
}