/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <iostream>
#include <map>
#include <string>

#include "buffer.hpp"
#include "enums/vertex_attribute_type.hpp"
#include "glint.hpp"
#include "vertex_attribute_binding.hpp"

namespace gloop {

    class vertex_attribute {
    private:
        const gloop::uint_t _id;

    public:

        vertex_attribute(gloop::uint_t id) :
        _id(id) {
        };

        inline friend std::ostream& operator<<(std::ostream& os, const vertex_attribute& va) {
            return os << "vertex_attribute: [id: "
                    << va._id
                    << "]";
        }

        gloop::uint_t getId() const;

        vertex_attribute_binding bindBuffer(
                const buffer * bufId,
                const enums::vertex_attribute_type,
                const gloop::sizei_t stride = 0, const void * ptr = nullptr,
                const gloop::uint_t divisor = 0) const;

        void enable() const;

        void disable() const;
    };

    class vertex_attributes {
    private:
        std::map<std::string, gloop::int_t> _nameMap;

    public:

        inline friend std::ostream& operator<<(std::ostream& os, const vertex_attributes& va) {
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

        void setLocation(std::string name, gloop::int_t index);

        gloop::int_t getLocation(const std::string& name) const;

        bool hasAttribute(const std::string& name) const;

        void bindAttributes(gloop::uint_t program) const;

        void enableAttributes() const;

        void disableAttributes() const;

        const vertex_attribute operator[](const std::string& name) const;
    };
}