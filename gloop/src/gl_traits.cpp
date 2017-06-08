#include "gl_traits.hpp"

#include "context_hints.hpp"

#include "../wrapper/gl.hpp"

namespace gloop {
	bool isGL() {
		static bool _isGL = wrapper::getDefaultContextHints().profile == context_profile::CORE;

		return _isGL;
	}

	bool isGLES() {
		return !isGL();
	}

	bool isGLES2() {
		static bool isGLES2 = wrapper::getDefaultContextHints().version.major == 2;

		return isGLES() && isGLES2;
	}

	bool isGLES3() {
		static bool isGLES3 = wrapper::getDefaultContextHints().version.major == 3;

		return isGLES() && isGLES3;
	}

	bool isGLEW() {
		return !isGLES();
	}
}
