#include "texture_wrap.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, texture_wrap wrap) {
			switch (wrap) {
				case texture_wrap::CLAMP_TO_EDGE:
					return os << "CLAMP_TO_EDGE";
				case texture_wrap::MIRRORED_REPEAT:
					return os << "MIRRORED_REPEAT";
				case texture_wrap::REPEAT:
					return os << "REPEAT";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
