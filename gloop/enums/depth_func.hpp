#pragma once

#include <iostream>

#include "../glint.hpp"

namespace gloop {
	namespace enums {
		enum class depth_func : gloop::enum_t {
			UNKNOWN = 0xFFFF,
			NEVER = 512,
			ALWAYS = 519,
			LESS = 513,
			GREATER = 516,
			EQUAL = 514,
			LEQUAL = 515,
			GEQUAL = 518,
			NOTEQUAL = 517
		};

		std::ostream& operator<<(std::ostream& os, depth_func enumval);
	}
}
