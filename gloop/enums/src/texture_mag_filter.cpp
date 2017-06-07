#include "texture_mag_filter.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, texture_mag_filter filter) {
			switch (filter) {
				case texture_mag_filter::NEAREST:
					return os << "NEAREST";
				case texture_mag_filter::LINEAR:
					return os << "LINEAR";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
