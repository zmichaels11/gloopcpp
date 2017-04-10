/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "shader.hpp"

#include <string>

#include <SDL2/SDL_rwops.h>

#include "enums/shader_type.hpp"
#include "exception/shader_compile_exception.hpp"
#include "exception/unsupported_shader_type_exception.hpp"
#include "glint.hpp"
#include "tools.hpp"
#include "wrapper/gl.hpp"
#include "wrapper/shaders_and_programs.hpp"

namespace {

    static std::string getShaderLog(const gloop::uint_t shader) {
        gloop::int_t logLength = 0;
        gloop::int_t maxLength = 0;

        gloop::wrapper::getShaderiv(shader, gloop::wrapper::INFO_LOG_LENGTH, &maxLength);

        auto infoLog = new gloop::char_t[maxLength];

        gloop::wrapper::getShaderInfoLog(shader, maxLength, &logLength, infoLog);

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
            const gloop::enums::shader_type type,
            const std::string& suffix,
            const std::string& srcOrFile) {

        if (hasSuffix(srcOrFile, suffix) || hasSuffix(srcOrFile, ".glsl")) {
            auto file = SDL_RWFromFile(srcOrFile.c_str(), "rb");
            auto src = gloop::tools::readAll(file);

            return gloop::shader(type, src);
        } else {
            return gloop::shader(type, srcOrFile);
        }
    }
}

namespace gloop {
    shader::~shader() {
        free();
    }

    void shader::init() {
        auto glType = static_cast<gloop::enum_t> (_type);
        auto glId = gloop::wrapper::createShader(glType);

        {
            auto cstr = this->_src.c_str();

            gloop::wrapper::shaderSource(glId, 1, &cstr, nullptr);
        }

        gloop::wrapper::compileShader(glId);

        gloop::int_t isCompiled = gloop::wrapper::FALSE;

        gloop::wrapper::getShaderiv(glId, gloop::wrapper::COMPILE_STATUS, &isCompiled);

        if (isCompiled) {
            this->_id = glId;
        } else {
            std::string infoLog = getShaderLog(glId);

            gloop::wrapper::deleteShader(glId);

            throw exception::shader_compile_exception(infoLog);
        }
    }

    gloop::uint_t shader::getId() {
        if (!this->isInitialized()) {
            this->init();
        }

        return this->_id;
    }

    void shader::free() {
        if (this->isInitialized()) {
            gloop::wrapper::deleteShader(_id);
            this->_id = 0;
        }
    }

    enums::shader_type shader::getType() const {
        return this->_type;
    }

    const std::string& shader::getSource() const {
        return this->_src;
    }

    bool shader::isInitialized() const {
        return this->_id != 0;
    }

    shader::operator bool() {
        return this->getId() != 0;
    }    

    shader shader::makeVertexShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(enums::shader_type::VERTEX, ".vert", srcOrFileName);
    }

    shader shader::makeFragmentShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(enums::shader_type::FRAGMENT, ".frag", srcOrFileName);
    }

    shader shader::makeGeometryShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(enums::shader_type::GEOMETRY, ".geom", srcOrFileName);
    }

    shader shader::makeComputeShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(enums::shader_type::COMPUTE, ".comp", srcOrFileName);
    }

    shader shader::makeTessellationControlShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(enums::shader_type::TESSELLATION_CONTROL, ".tesc", srcOrFileName);
    }

    shader shader::makeTessellationEvaluationShader(const std::string& srcOrFileName) {
        return readFromSrcOrFileName(enums::shader_type::TESSELLATION_EVALUATION, ".tese", srcOrFileName);
    }
}