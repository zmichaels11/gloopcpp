# WebGL build
1. install emscripten (see emscripten_README.md for installation instructions)
2. run `make -f nbproject/Makefile-WEBGL_Debug.mk QMAKE= SUBPROJECTS= .build-conf`
3. run the html binary in `dist/WEBGL_Debug`

## Virtual Filesystem
Currently files are included in the virtual file system using the linker.

# Change test build
1. Create a function for the entry point. Must be the declared as `int func(int argc, char** argv)` where `func` is a unique function name in global namespace.
2. Add the compiler option `-Dtest_name` where `test_name` is the entry point
