#include "texture_pixel_pack.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<< (std::ostream& os, texture_pixel_pack tpp) {
			switch (tpp) {
				case texture_pixel_pack::UINT8:
					return os << "UINT8";
				case texture_pixel_pack::UINT16:
					return os << "UINT16";
				case texture_pixel_pack::UINT32:
					return os << "UINT32";
				case texture_pixel_pack::FLOAT32:
					return os << "FLOAT32";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
