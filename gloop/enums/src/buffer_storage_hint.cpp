#include "buffer_storage_hint.hpp"

#include <iostream>

namespace gloop {
	namespace enums {
		std::ostream& operator<< (std::ostream& os, buffer_storage_hint hint) {
			switch (hint) {
				case buffer_storage_hint::STATIC_DRAW:
					return os << "STATIC_DRAW";
				case buffer_storage_hint::STATIC_READ:
					return os << "STATIC_READ";
				case buffer_storage_hint::STATIC_COPY:
					return os << "STATIC_COPY";
				case buffer_storage_hint::DYNAMIC_DRAW:
					return os << "DYNAMIC_DRAW";
				case buffer_storage_hint::DYNAMIC_READ:
					return os << "DYNAMIC_READ";
				case buffer_storage_hint::DYNAMIC_COPY:
					return os << "DYNAMIC_COPY";
				case buffer_storage_hint::STREAM_DRAW:
					return os << "STREAM_DRAW";	
				case buffer_storage_hint::STREAM_READ:
					return os << "STREAM_READ";
				case buffer_storage_hint::STREAM_COPY:
					return os << "STREAM_COPY";
				default:
					return os << "UNKNOWN";
			}
		}
	}
}
