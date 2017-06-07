#include "shader_type.hpp"

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, shader_type type) {
			switch (type) {
				case shader_type::VERTEX:
					return os << "VERTEX";
				case shader_type::FRAGMENT:
					return os << "FRAGMENET";
				case shader_type::GEOMETRY:
					return os << "GEOMETRY";
				case shader_type::TESSELLATION_CONTROL:
					return os << "TESSELLATION_CONTROL";
				case shader_type::TESSELLATION_EVALUATION:
					return os << "TESSELLATION_EVALUATION";
				case shader_type::COMPUTE:
					return os << "COMPUTE";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
