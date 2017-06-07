#include "texture_internal_format.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, texture_internal_format fmt) {
			switch (fmt) {
				case texture_internal_format::R8_G8_B8_UNORM:
					return os << "R8_G8_B8_UNORM";
				case texture_internal_format::R8_G8_B8_A8_UNORM:
					return os << "R8_G8_B8_A8_UNORM";
				case texture_internal_format::R32_G32_B32_FLOAT:
					return os << "R32_G32_B32_FLOAT";
				case texture_internal_format::R32_G32_B32_A32_FLOAT:
					return os << "R32_G32_B32_A32_FLOAT";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
