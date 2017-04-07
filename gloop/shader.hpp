/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <string>

#include <GL/glew.h>

#include "shader_type.hpp"

namespace gloop {        
    class shader {
    private:
        GLuint _id;
        std::string _src;
        shader_type _type;

        void init();
    public:

        shader(
                shader_type type = shader_type::UNKNOWN, 
                std::string src = "") :
        _type(type), _src(src), _id(0) {
        }
        
        shader(shader&) = delete;
        
        shader(shader&&) = default;
        
        ~shader();

        GLuint getId();
        
        void free();
        
        shader_type getType() const;
        
        const std::string& getSource() const;
        
        bool isInitialized() const;
        
        operator bool();
        
        operator GLuint();
        
        static shader makeVertexShader(const std::string& srcOrFileName);
        
        static shader makeFragmentShader(const std::string& srcOrFileName);
        
        static shader makeGeometryShader(const std::string& srcOrFileName);
        
        static shader makeTessellationControlShader(const std::string& srcOrFileName);
        
        static shader makeTessellationEvaluationShader(const std::string& srcOrFileName);
        
        static shader makeComputeShader(const std::string& srcOrFileName);
    };
}