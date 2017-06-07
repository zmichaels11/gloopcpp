#include "buffer_target.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<< (std::ostream& os, buffer_target enumval) {
			switch (enumval) {
				case buffer_target::ARRAY:
					return os << "ARRAY";
				case buffer_target::ELEMENT_ARRAY:
					return os << "ELEMENT_ARRAY";
				case buffer_target::ATOMIC_COUNTER:
					return os << "ATOMIC_COUNTER";
				case buffer_target::COPY_READ:
					return os << "COPY_READ";
				case buffer_target::COPY_WRITE:
					return os << "COPY_WRITE";
				case buffer_target::DISPATCH_INDIRECT:
					return os << "DISPATCH_INDIRECT";
				case buffer_target::PIXEL_PACK:
					return os << "PIXEL_PACK";
				case buffer_target::PIXEL_UNPACK:
					return os << "PIXEL_UNPACK";
				case buffer_target::QUERY:
					return os << "QUERY";
				case buffer_target::SHADER_STORAGE:
					return os << "SHADER_STORAGE";
				case buffer_target::UNIFORM:
					return os << "UNIFORM";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
