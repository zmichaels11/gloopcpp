#pragma once

#include <iostream>

namespace gloop {
	enum class context_profile {
		CORE,
		COMPATIBILITY,
		ES
	};

	std::ostream& operator<<(std::ostream& os, context_profile cp);

	struct context_hints {
		struct version_t {
			unsigned int major;
			unsigned int minor;
		} version;

		context_profile profile;
		int swapInterval;
		bool doubleBuffer;
	};

	std::ostream& operator<<(std::ostream& os, const context_hints& ch);
}
