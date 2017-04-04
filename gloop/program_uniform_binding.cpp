/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "program.hpp"

#include <GL/glew.h>

bool gloop::uniform_binding::isValid() const {
    return (_pId.get() != nullptr);
}

gloop::uniform_binding::operator bool() const {
    return this->isValid();
}

void gloop::uniform_binding::pushFloat(const GLfloat* v, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniform1fv(_loc, count, v);
    }
}

void gloop::uniform_binding::pushVec2(const GLfloat* v, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniform2fv(_loc, count, v);
    }
}

void gloop::uniform_binding::pushVec3(const GLfloat* v, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniform3fv(_loc, count, v);
    }
}

void gloop::uniform_binding::pushVec4(const GLfloat* v, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniform4fv(_loc, count, v);
    }
}

void gloop::uniform_binding::pushInt(const GLint* v, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniform1iv(_loc, count, v);
    }
}

void gloop::uniform_binding::pushIVec2(const GLint* v, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniform2iv(_loc, count, v);
    }
}

void gloop::uniform_binding::pushIVec3(const GLint* v, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniform3iv(_loc, count, v);
    }
}

void gloop::uniform_binding::pushIVec4(const GLint* v, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniform4iv(_loc, count, v);
    }
}

void gloop::uniform_binding::pushMat2(const GLfloat* m, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniformMatrix2fv(_loc, count, GL_FALSE, m);
    }
}

void gloop::uniform_binding::pushMat3(const GLfloat* m, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniformMatrix3fv(_loc, count, GL_FALSE, m);
    }
}

void gloop::uniform_binding::pushMat4(const GLfloat* m, const GLsizei count) const {
    if (this->isValid()) {
        glUseProgram(*_pId);
        glUniformMatrix4fv(_loc, count, GL_FALSE, m);
    }
}