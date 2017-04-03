#include "gltools.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

namespace {

    std::string readFileLines(const char * fileName) {
        std::ifstream in(fileName, std::ios::in | std::ios::binary);

        if (in) {
            std::ostringstream contents;
            contents << in.rdbuf();
            contents << "\0";
            in.close();

            return contents.str();
        } else {
            throw "Unable to open input stream to file!";
        }
    }

    void printShaderLog(GLuint shader) {
        GLint logLength = 0;
        GLint maxLength = 0;

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        GLchar * infoLog = new GLchar[maxLength];

        std::cout << "log length: " << maxLength << std::endl;
        glGetShaderInfoLog(shader, maxLength, &logLength, infoLog);

        if (logLength > 0) {
            std::cerr << infoLog << std::endl;
        }

        delete[] infoLog;
    }
}

GLuint gltools::createShader(const GLenum shaderType, const char* fileName) {
    auto src = readFileLines(fileName);
    auto id = glCreateShader(shaderType);

    {
        const char * cstr = src.c_str();

        glShaderSource(id, 1, &cstr, nullptr);
    }

    glCompileShader(id);

    auto isCompiled = GL_FALSE;

    glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);

    if (isCompiled) {
        return id;
    } else {
        printShaderLog(id);
        throw "Unable to compile shader!";
    }
}

GLuint gltools::createProgram(const GLuint* shaders, const std::size_t count) {
    auto programId = glCreateProgram();

    for (auto it = shaders; it != shaders + count; it++) {
        glAttachShader(programId, *it);
    }    

    glLinkProgram(programId);

    for (auto it = shaders; it != shaders + count; it++) {
        glDetachShader(programId, *it);
    }

    auto linkSuccess = GL_FALSE;

    glGetProgramiv(programId, GL_LINK_STATUS, &linkSuccess);

    if (linkSuccess != GL_TRUE) {
        throw "Error linking program!";
    }

    return programId;
}