include sources.mk

GLOOP_OBJECTS=$(GLOOP_SOURCES:.cpp=.bc)
GLGFX_OBJECTS=$(GLGFX_SOURCES:.cpp=.bc)
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.bc)

GLEW_GLOOP_OBJECTS=$(addprefix bin/glew/, $(GLOOP_OBJECTS))
GLEW_GLGFX_OBJECTS=$(addprefix bin/glew/, $(GLGFX_OBJECTS))
GLEW_TEST_OBJECTS=$(addprefix bin/glew/, $(TEST_OBJECTS))

ASMJS_GLOOP_OBJECTS=$(addprefix bin/asmjs/, $(GLOOP_OBJECTS))
ASMJS_GLGFX_OBJECTS=$(addprefix bin/asmjs/, $(GLGFX_OBJECTS))
ASMJS_TEST_OBJECTS=$(addprefix bin/asmjs/, $(TEST_OBJECTS))

GLES3_GLOOP_OBJECTS=$(addprefix bin/gles3/, $(GLOOP_OBJECTS))
GLES3_GLGFX_OBJECTS=$(addprefix bin/gles3/, $(GLGFX_OBJECTS))
GLES3_TEST_OBJECTS=$(addprefix bin/gles3/, $(TEST_OBJECTS))

TESTS=sprite_test.exe
GLES3_TESTS=$(addprefix bin/gles3/, $(TESTS))
GLEW_TESTS=$(addprefix bin/glew/, $(TESTS))
LIBS=\
libGLOOP \
libGLGFX

LLVM_GLEW_LIBS=$(addsuffix .bc, $(addprefix bin/glew/, $(LIBS)))
LLVM_GLES3_LIBS=$(addsuffix .bc, $(addprefix bin/gles3/, $(LIBS)))
LLVM_ASMJS_LIBS=$(addsuffix .bc, $(addprefix bin/asmjs/, $(LIBS)))

STATIC_GLEW_LIBS=$(addsuffix .a, $(addprefix bin/glew/, $(Libs)))
STATIC_GLES3_LIBS=$(addsuffix .a, $(addprefix bin/gles3/, $(LIBS)))
STATIC_ASMJS_LIBS=$(addsuffix .a, $(addprefix bin/asmjs/, $(LIBS)))

GLOOP_HEADERS:=$(shell find gloop -type f -name "*.hpp")
GLGFX_HEADERS:=$(shell find glgfx -type -f -name "*.hpp")

.PHONY: all tests static_libs llvm_libs directories clean emsdk_activate emsdk_install

all: tests

tests: $(GLEW_TESTS) $(GLES3_TESTS)

static_libs: $(STATIC_GLEW_LIBS) $(STATIC_GLES3_LIBS)

llvm_libs: $(LLVM_GLEW_LIBS) $(LLVM_GLES3_LIBS)

directories:
	mkdir -p $(addprefix bin/glew/, $(GLOOP_DIRECTORIES))
	mkdir -p $(addprefix bin/gles3/, $(GLOOP_DIRECTORIES))
	mkdir -p $(addprefix bin/asmjs/, $(GLOOP_DIRECTORIES))
	mkdir -p $(addprefix bin/glew/, $(GLGFX_DIRECTORIES))
	mkdir -p $(addprefix bin/gles3/, $(GLGFX_DIRECTORIES))
	mkdir -p $(addprefix bin/asmjs/, $(GLGFX_DIRECTORIES))
	mkdir -p headers

gloop.hpp: $(GLOOP_HEADERS)
	find gloop -type f -name "*.hpp" > gloop.tmp
	awk '$$0="#include \""$$0"\""' gloop.tmp > gloop.hpp
	rm gloop.tmp

glgfx.hpp: $(GLGFX_HEADERS)
	find glgfx -type f -name "*.hpp" > glgfx.tmp
	awk '$$0="#include \""$$0"\""' glgfx.tmp > glgfx.hpp
	rm glgfx.tmp

bin/glew/gloop.hpp: gloop.hpp
	clang++ -DGL=GLEW -DUSE_SDL_IMAGE -E -std=c++14 -o $@ $<

bin/glew/%.bc: %.cpp
	clang++ -DGL=GLEW -DUSE_SDL_IMAGE -emit-llvm -std=c++14 -O3 -c -o $@ $<

bin/gles3/%.bc: %.cpp
	clang++ -DGL=GLES3 -DUSE_SDL_IMAGE -emit-llvm -std=c++14 -O3 -c -o $@ $<

bin/asmjs/%.bc: %.cpp
	em++ -DGL=GLES2 -DUSE_SDL_IMAGE -emit-llvm -std=c++14 -O3 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -c -o $@ $<

bin/glew/%.a: %.bc
	llvm-ar rc $@ $<

bin/glew/libGLOOP.bc: $(GLEW_GLOOP_OBJECTS)
	llvm-link $(GLEW_GLOOP_OBJECTS) -o $@
	opt -std-link-opts -O3 $@ -o $@

bin/glew/libGLGFX.bc: $(GLEW_GLGFX_OBJECTS)
	llvm-link $(GLEW_GLGFX_OBJECTS) -o $@
	opt -std-link-opts -O3 $@ -o $@

bin/asmjs/libGLOOP.bc: $(ASMJS_GLOOP_OBJECTS)
	llvm-link $(ASMJS_GLOOP_OBJECTS) -o $@
	opt -std-link-opts -O3 $@ -o $@

bin/asmjs/libGLGFX.bc: $(ASMJS_GLGFX_OBJECTS)
	llvm-link $(ASMJS_GLGFX_OBJECTS) -o $@
	opt -std-link-opts -O3 $@ -o $@

bin/gles3/libGLOOP.bc: $(GLES3_GLOOP_OBJECTS)
	llvm-link $(GLES3_GLOOP_OBJECTS) -o $@
	opt -std-link-opts -O3 $@ -o $@

bin/gles3/libGLGFX.bc: $(GLES3_GLGFX_OBJECTS)
	llvm-link $(GLES3_GLGFX_OBJECTS) -o $@
	opt -std-link-opts -O3 $@ -o $@

bin/glew/sprite_test.exe: directories gloop.hpp glgfx.hpp bin/glew/sprite_test.bc bin/glew/libGLOOP.bc bin/glew/libGLGFX.bc
	clang++ bin/glew/sprite_test.bc bin/glew/libGLOOP.bc bin/glew/libGLGFX.bc -o $@ `pkg-config --libs sdl2` `pkg-config --libs SDL2_image` `pkg-config --libs glew`

bin/gles3/sprite_test.exe: directories gloop.hpp glgfx.hpp bin/gles3/sprite_test.bc bin/gles3/libGLOOP.bc bin/gles3/libGLGFX.bc
	clang++ bin/gles3/sprite_test.bc bin/gles3/libGLOOP.bc bin/gles3/libGLGFX.bc -o $@ `pkg-config --libs sdl2` `pkg-config --libs SDL2_image` `pkg-config --libs glesv2`

bin/asmjs/sprite_test.html: directories gloop.hpp glgfx.hpp bin/asmjs/sprite_test.bc bin/asmjs/libGLOOP.bc bin/asmjs/libGLGFX.bc
	em++ -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' bin/asmjs/sprite_test.bc bin/asmjs/libGLOOP.bc bin/asmjs/libGLGFX.bc -o $@ --preload-file tests --preload-file tests/data --preload-file glgfx/shaders -O3

clean:
	rm -fv $(GLEW_GLOOP_OBJECTS)
	rm -fv $(GLEW_GLGFX_OBJECTS)
	rm -fv $(GLEW_TEST_OBJECTS)
	rm -fv $(ASMJS_GLOOP_OBJECTS)
	rm -fv $(ASMJS_GLGFX_OBJECTS)
	rm -fv $(ASMJS_TEST_OBJECTS)
	rm -fv $(GLES3_GLOOP_OBJECTS)
	rm -fv $(GLES3_GLGFX_OBJECTS)	
	rm -fv $(GLES3_TEST_OBJECTS)
	rm -fv $(LLVM_GLEW_LIBS)
	rm -fv $(LLVM_GLES3_LIBS)
	rm -fv $(LLVM_ASMJS_LIBS)
	rm -fv $(STATIC_GLEW_LIBS)
	rm -fv $(STATIC_GLES3_LIBS)
	rm -fv $(STATIC_ASMJS_LIBS)

emsdk_env.mk: .emsdk_portable/emsdk_set_env.sh
	sed 's/"//g ; s/=/:=/' < $< > $@

emsdk_activate: emsdk_install
	.emsdk_portable/emsdk activate latest
	.emsdk_portable/emsdk construct_env

emsdk_install: emsdk_update
	.emsd_portable/emsdk update
