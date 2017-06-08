/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <iostream>
#include <string>

#include "glint.hpp"

namespace gloop {

    namespace enums {
        enum class shader_type : gloop::enum_t;
    }
    
    class shader {
    private:
        enums::shader_type _type;
        std::string _src;
        gloop::uint_t _id;

        void init();
    public:

        shader() : shader(static_cast<enums::shader_type> (0), "") {
        }

        shader(enums::shader_type type, std::string src) :
        _type(type), 
		_src(src), 
		_id(0) {        }

        ~shader();

        shader(const shader&) = delete;

        shader(shader&&) = default;

        shader& operator=(const shader&) = delete;

        shader& operator=(shader&&) = default;

        friend std::ostream& operator<<(std::ostream& os, const shader& s);

        gloop::uint_t getId();

        void free();

        enums::shader_type getType() const;

        const std::string& getSource() const;

        bool isInitialized() const;

        operator bool();

        static shader makeVertexShader(const std::string& srcOrFileName);

        static shader makeFragmentShader(const std::string& srcOrFileName);

        static shader makeGeometryShader(const std::string& srcOrFileName);

        static shader makeTessellationControlShader(const std::string& srcOrFileName);

        static shader makeTessellationEvaluationShader(const std::string& srcOrFileName);

        static shader makeComputeShader(const std::string& srcOrFileName);
    };
}
