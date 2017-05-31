# GLOOP - an Object-Oriented Graphics Library
Originally ported from a Java library I wrote of the same name. 
GLOOP is designed to abstract OpenGL, OpenGL ES, and WebGL into a unified library.

# Dependencies
* GLOOP uses SDL2 and SDL2_image. It is possible to disable SDL2_image (requires some editing of the Makefile)
* ASMJS builds require prior setup of an emscripten environment. 
* GLOOP is written against OpenGLES 3.0, OpenGL 3.0, and WebGL. It can be built for OpenGLES 2.0, but requires a handful of extensions.
* GLEW is required for the OpenGL builds.
* Currently builds only tested on linux. Confirmed working on Bash on Ubuntu on Windows (requires Ubuntu 16.04)
* Requires Clang compiler with support of C++14.

# ASMJS build
1. Setup emscripten environment.
2. Build ASMJS targets (bin/asmjs)

# Known bugs
* Build fails if using Bash on Ubuntu on Windows for ASMJS builds if repository is located on Windows.
* sprite_test segfaults if build is set to OpenGLES 2.0 and the extension ANGLE_instanced_arrays is not available.
