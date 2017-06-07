#include "texture_min_filter.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<<(std::ostream& os, texture_min_filter filter) {
			switch (filter) {
				case texture_min_filter::NEAREST:
					return os << "NEAREST";
				case texture_min_filter::LINEAR:
					return os << "LINEAR";
				case texture_min_filter::NEAREST_MIPMAP_NEAREST:
					return os << "NEAREST_MIPMAP_NEAREST";	
				case texture_min_filter::NEAREST_MIPMAP_LINEAR:
					return os << "NEAREST_MIPMAP_LINEAR";	
				case texture_min_filter::LINEAR_MIPMAP_NEAREST:
					return os << "NEAREST_MIPMAP_LINEAR";
				case texture_min_filter::LINEAR_MIPMAP_LINEAR:
					return os << "LINERA_MIPMAP_LINEAR";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
