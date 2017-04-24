/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vertex_attributes.hpp"

#include <iostream>
#include <string>
#include <map>

#include "buffer.hpp"
#include "enums/vertex_attribute_type.hpp"
#include "vertex_array.hpp"
#include "vertex_attribute_binding.hpp"
#include "wrapper/shaders_and_programs.hpp"
#include "wrapper/vertex_arrays.hpp"

namespace gloop {

    std::ostream& operator<<(std::ostream& os, const vertex_attribute& va) {
        return os << "vertex_attribute: [id: "
                << va._id
                << "]";
    }
    
    std::ostream& operator<<(std::ostream& os, const vertex_attributes& va) {
            os << "vertex_attributes: [";

            int i = 0;
            for (auto it = va._nameMap.begin(); it != va._nameMap.end(); it++) {
                os << it->first
                        << ": "
                        << it->second;

                if (i < va._nameMap.size() - 1) {
                    os << ", ";
                }
                
                i++;
            }

            return os << "]";
        }

    void vertex_attributes::setLocation(std::string name, gloop::int_t index) {
        this->_nameMap[name] = index;
    }

    gloop::int_t vertex_attributes::getLocation(const std::string& name) const {
        const auto it = this->_nameMap.find(name);

        if (it == this->_nameMap.end()) {
            return -1;
        } else {
            return it->second;
        }
    }

    bool vertex_attributes::hasAttribute(const std::string& name) const {
        return (this->_nameMap.find(name) != this->_nameMap.end());
    }

    void vertex_attributes::bindAttributes(gloop::uint_t program) const {
        for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
            gloop::wrapper::bindAttribLocation(program, it->second, it->first.c_str());
        }
    }

    void vertex_attributes::enableAttributes() const {
        for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
            gloop::wrapper::enableVertexAttribArray(it->second);
        }
    }

    void vertex_attributes::disableAttributes() const {
        for (auto it = this->_nameMap.begin(); it != this->_nameMap.end(); it++) {
            gloop::wrapper::disableVertexAttribArray(it->second);
        }
    }

    vertex_attribute_binding vertex_attribute::bindBuffer(
            const buffer * buffer,
            const enums::vertex_attribute_type type,
            const gloop::sizei_t stride, const void* ptr,
            const gloop::uint_t divisor) const {

        return vertex_attribute_binding(this->_id, buffer, type, stride, ptr, divisor);
    }

    const vertex_attribute vertex_attributes::operator[](const std::string& name) const {
        return gloop::vertex_attribute(this->getLocation(name));
    }

    void vertex_attribute::disable() const {
        gloop::wrapper::disableVertexAttribArray(_id);
    }

    void vertex_attribute::enable() const {
        gloop::wrapper::enableVertexAttribArray(_id);
    }

    gloop::uint_t vertex_attribute::getId() const {
        return this->_id;
    }
}