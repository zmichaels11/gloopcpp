/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "draw_calls.hpp"

#include <GL/glew.h>

namespace gloop {

    void draw::elements::draw() const {
        glDrawElements(static_cast<GLenum> (drawMode), count, static_cast<GLenum> (indexType), indices);
    }

    void draw::arrays::draw() const {
        glDrawArrays(static_cast<GLenum> (drawMode), first, count);
    }

    void draw::elements_instanced::draw() const {
        glDrawElementsInstanced(static_cast<GLenum> (drawMode), count, static_cast<GLenum> (indexType), indices, primitiveCount);
    }

    void draw::arrays_instanced::draw() const {
        glDrawArraysInstanced(static_cast<GLenum> (drawMode), first, count, primitiveCount);
    }

    void draw::elements_base_vertex::draw() const {
        glDrawElementsBaseVertex(static_cast<GLenum> (drawMode), count, static_cast<GLenum> (indexType), indices, baseVertex);
    }

    void draw::range_elements::draw() const {
        glDrawRangeElements(static_cast<GLenum> (drawMode), start, end, count, static_cast<GLenum> (indexType), indices);
    }
}