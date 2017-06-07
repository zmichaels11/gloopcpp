#include "texture_format.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, texture_format fmt) {
			switch (fmt) {
				case texture_format::RGB:
					return os << "RGB";
				case texture_format::BGR:
					return os << "BGR";
				case texture_format::RGBA:
					return os << "RBGA";
				case texture_format::BGRA:
					return os << "BGRA";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
