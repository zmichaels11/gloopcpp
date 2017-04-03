/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "shader.hpp"

#include <string>
#include <fstream>

#include <GL/glew.h>

#include "exception.hpp"
#include "tools.hpp"

namespace {                
    static GLenum checkVertexShaderSupported() {                
        if (GLEW_VERSION_2_0 || GLEW_ARB_vertex_program) {
            return GL_VERTEX_SHADER;          
        } else {
            throw gloop::unsupported_shader_type_exception("Vertex shaders are not supported!");
        }        
    }
    
    static GLenum checkFragmentShaderSupported() {
        if (GLEW_VERSION_2_0 || GLEW_ARB_fragment_program) {
            return GL_FRAGMENT_SHADER;
        } else {
            throw gloop::unsupported_shader_type_exception("Fragment shaders are not supported!");
        }
    }
    
    static GLenum checkGeometryShaderSupported() {
        if (GLEW_VERSION_3_2 || GLEW_ARB_geometry_shader4) {
            return GL_GEOMETRY_SHADER;
        } else {
            throw gloop::unsupported_shader_type_exception("Geometry shaders are not supported!");
        }
    }
    
    static GLenum checkTessellationControlShaderSupported() {
        if (GLEW_VERSION_4_0 || GLEW_ARB_tessellation_shader) {
            return GL_TESS_CONTROL_SHADER;
        } else {
            throw gloop::unsupported_shader_type_exception("Tessellation shaders are not supported!");
        }
    }
    
    static GLenum checkTessellationEvaluationShaderSupported() {
        if (GLEW_VERSION_4_0 || GLEW_ARB_tessellation_shader) {
            return GL_TESS_EVALUATION_SHADER;
        } else {
            throw gloop::unsupported_shader_type_exception("Tessellation shaders are not supported!");
        }
    }
    
    static GLenum checkComputeShaderSupported() {
        if (GLEW_VERSION_4_3 || GLEW_ARB_compute_shader) {
            return GL_COMPUTE_SHADER;
        } else {
            throw gloop::unsupported_shader_type_exception("Compute shaders are not supported!");
        }
    }        
    
    static GLenum checkShaderSupported(gloop::shader_type type) {
        switch (type) {
            case gloop::shader_type::VERTEX:
                return checkVertexShaderSupported();
            case gloop::shader_type::FRAGMENT:
                return checkFragmentShaderSupported();
            case gloop::shader_type::GEOMETRY:
                return checkGeometryShaderSupported();
            case gloop::shader_type::TESSELLATION_CONTROL:
                return checkTessellationControlShaderSupported();
            case gloop::shader_type::TESSELLATION_EVALUATION:
                return checkTessellationEvaluationShaderSupported();
            case gloop::shader_type::COMPUTE:
                return checkComputeShaderSupported();
            default:
                throw gloop::unsupported_shader_type_exception("Unknown shader type!");
        }
    }
    
    static std::string getShaderLog(GLuint shader) {
        GLint logLength = 0;
        GLint maxLength = 0;
        
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
                
        GLchar * infoLog = new GLchar[maxLength];                
        
        glGetShaderInfoLog(shader, maxLength, &logLength, infoLog);
        
        std::string out;
        
        if (logLength > 0) {
            out = std::string(reinterpret_cast<char *> (infoLog));
        } else {
            out = "No shader log!";
        }
        
        delete[] infoLog;
        
        return out;
    }
    
    static bool hasSuffix(const std::string& str, const std::string& suffix) {
        return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }
    
    static gloop::shader readFromSrcOrFileName(const gloop::shader_type type, const std::string& suffix, const std::string& srcOrFile) {                
        if (hasSuffix(srcOrFile, suffix) || hasSuffix(srcOrFile, ".glsl")) {
            std::ifstream in(srcOrFile, std::ios::in | std::ios::binary);
            std::string src = gloop::tools::readAll(in);
            
            return gloop::shader(type, src);
        } else {
            return gloop::shader(type, srcOrFile);
        }
    }
}

void gloop::shader::init() {
    const GLenum glType = checkShaderSupported(this->_type);    
    const GLuint glId = glCreateShader(glType);
    
    {
        const char * cstr = this->_src.c_str();
        
        glShaderSource(glId, 1, &cstr, nullptr);
    }
    
    glCompileShader(glId);
    
    GLint isCompiled = GL_FALSE;
    
    glGetShaderiv(glId, GL_COMPILE_STATUS, &isCompiled);
    
    if (isCompiled) {
        this->_id = std::shared_ptr<GLuint>(new GLuint, [=](GLuint * id) {
            glDeleteShader(*id);            
            delete id;
        });
        
        *(this->_id) = glId;
    } else {
        std::string infoLog = getShaderLog(glId);
        
        glDeleteShader(glId);
        
        throw shader_compile_exception(infoLog);
    }
}

GLuint gloop::shader::getId() {
    if (this->_id.get() == nullptr) {
        this->init();
    }
    
    return *(this->_id);
}

void gloop::shader::free() {
    if (this->_id.get() != nullptr) {        
        glDeleteShader(*(this->_id));
        this->_id.reset();
    }
}

gloop::shader_type gloop::shader::getType() const {
    return this->_type;
}

const std::string gloop::shader::getSource() const {
    return this->_src;
}

gloop::shader gloop::shader::makeVertexShader(const std::string srcOrFileName) {
    return readFromSrcOrFileName(gloop::shader_type::VERTEX, ".vert", srcOrFileName);
}

gloop::shader gloop::shader::makeFragmentShader(const std::string srcOrFileName) {
    return readFromSrcOrFileName(gloop::shader_type::FRAGMENT, ".frag", srcOrFileName);
}

gloop::shader gloop::shader::makeGeometryShader(const std::string srcOrFileName) {
    return readFromSrcOrFileName(gloop::shader_type::GEOMETRY, ".geom", srcOrFileName);
}

gloop::shader gloop::shader::makeComputeShader(const std::string srcOrFileName) {
    return readFromSrcOrFileName(gloop::shader_type::COMPUTE, ".comp", srcOrFileName);
}

gloop::shader gloop::shader::makeTessellationControlShader(const std::string srcOrFileName) {
    return readFromSrcOrFileName(gloop::shader_type::TESSELLATION_CONTROL, ".tesc", srcOrFileName);
}

gloop::shader gloop::shader::makeTessellationEvaluationShader(const std::string srcOrFileName) {
    return readFromSrcOrFileName(gloop::shader_type::TESSELLATION_EVALUATION, ".tese", srcOrFileName);
}