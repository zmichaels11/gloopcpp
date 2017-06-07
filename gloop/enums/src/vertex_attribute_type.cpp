#include "vertex_attribute_type.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, vertex_attribute_type type) {
			switch (type) {
				case vertex_attribute_type::FLOAT:
					return os << "FLOAT";
				case vertex_attribute_type::INT:
					return os << "INT";
				case vertex_attribute_type::UINT:
					return os << "UINT";
				case vertex_attribute_type::VEC2:
					return os << "VEC2";
				case vertex_attribute_type::VEC3:
					return os << "VEC3";
				case vertex_attribute_type::VEC4:
					return os << "VEC4";
				case vertex_attribute_type::IVEC2:
					return os << "IVEC2";
				case vertex_attribute_type::IVEC3:
					return os << "IVEC3";
				case vertex_attribute_type::IVEC4:
					return os << "IVEC4";
				case vertex_attribute_type::UVEC2:
					return os << "UVEC2";
				case vertex_attribute_type::UVEC3:
					return os << "UVEC3";
				case vertex_attribute_type::UVEC4:
					return os << "UVEC4";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}

