/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "shader.hpp"

#include <string>
#include <fstream>

#include <GL/glew.h>

#include "shader_compile_exception.hpp"
#include "shader_type.hpp"
#include "tools.hpp"
#include "unsupported_shader_type_exception.hpp"

namespace {

    static std::string getShaderLog(const GLuint shader) {
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

    static bool hasSuffix(
            const std::string& str,
            const std::string& suffix) {

        return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    static gloop::shader readFromSrcOrFileName(
            const gloop::shader_type type,
            const std::string& suffix,
            const std::string& srcOrFile) {

        if (hasSuffix(srcOrFile, suffix) || hasSuffix(srcOrFile, ".glsl")) {
            std::ifstream in(srcOrFile, std::ios::in | std::ios::binary);
            std::string src = gloop::tools::readAll(in);

            return gloop::shader(type, src);
        } else {
            return gloop::shader(type, srcOrFile);
        }
    }
}

namespace gloop {

    void shader::init() {
        auto glType = static_cast<GLenum> (_type);
        auto glId = glCreateShader(glType);

        {
            auto cstr = this->_src.c_str();

            glShaderSource(glId, 1, &cstr, nullptr);
        }

        glCompileShader(glId);

        GLint isCompiled = GL_FALSE;

        glGetShaderiv(glId, GL_COMPILE_STATUS, &isCompiled);

        if (isCompiled) {
            this->_id = std::shared_ptr<GLuint>(new GLuint, [ = ](GLuint * id){
                if (id != nullptr) {
                    glDeleteShader(*id);
                            delete id;
                }
            });

            *(this->_id) = glId;
        } else {
            std::string infoLog = getShaderLog(glId);

            glDeleteShader(glId);

            throw shader_compile_exception(infoLog);
        }
    }

    GLuint shader::getId() {
        if (!this->isInitialized()) {
            this->init();
        }

        return *(this->_id);
    }

    void shader::free() {
        if (this->isInitialized()) {
            glDeleteShader(*(this->_id));
            this->_id.reset();
        }
    }

    shader_type shader::getType() const {
        return this->_type;
    }

    const std::string& shader::getSource() const {
        return this->_src;
    }

    bool shader::isInitialized() const {
        return this->_id.get() != nullptr;
    }

    shader::operator bool() {
        return this->getId() != 0;
    }

    shader::operator GLuint() {
        return this->getId();
    }

    shader shader::makeVertexShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(shader_type::VERTEX, ".vert", srcOrFileName);
    }

    shader shader::makeFragmentShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(shader_type::FRAGMENT, ".frag", srcOrFileName);
    }

    shader shader::makeGeometryShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(shader_type::GEOMETRY, ".geom", srcOrFileName);
    }

    shader shader::makeComputeShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(shader_type::COMPUTE, ".comp", srcOrFileName);
    }

    shader shader::makeTessellationControlShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(shader_type::TESSELLATION_CONTROL, ".tesc", srcOrFileName);
    }

    shader shader::makeTessellationEvaluationShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(shader_type::TESSELLATION_EVALUATION, ".tese", srcOrFileName);
    }
}