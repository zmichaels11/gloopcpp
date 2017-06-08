SOURCES:=sprite_test.cpp

OBJECTS:=$(SOURCES:.cpp=.bc)

CXXFLAGS:=-std=c++14 -I. -Wall -Wno-missing-braces
EMXXFLAGS:=-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'

GLES2_LDFLAGS:=-lGLESv2 -lSDL2 -lSDL2_image
GLES3_LDFLAGS:=-lGLESv2 -lSDL2 -lSDL2_image
GLEW_LDFLAGS:=-lGL -lGLEW -lSDL2 -lSDL2_image
EMXX_LDFLAGS:=-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'

GLES2_LDLIBS:=
GLES3_LDLIBS:=
GLEW_LDLIBS:=
EMXX_LDLIBS:=--preload-file tests --preload-file tests/data --preload-file glgfx/shaders -O2

CXX:=clang++

TARGET:=$(shell clang --version | grep "Target:" | awk '{print $$2}')
ASMJS_TARGET:=asmjs-unknown-emscripten
BINARY_EXT:=exe

MODULES:=libGLOOP.bc libGLGFX.bc
GLOOP_MODULES:=gles2/libGLOOP.bc gles3/libGLOOP.bc glew/libGLOOP.bc

TARGET_OBJECTS:=$(addprefix bin/$(TARGET)/, $(OBJECTS))
TARGET_SPRITE_TEST_OBJECTS:=bin/$(TARGET)/sprite_test.bc bin/$(TARGET)/libGLGFX.bc
GLEW_GLOOP:=bin/$(TARGET)/glew/libGLOOP.bc
GLES2_GLOOP:=bin/$(TARGET)/gles2/libGLOOP.bc
GLES3_GLOOP:=bin/$(TARGET)/gles3/libGLOOP.bc
GLGFX:=bin/$(TARGET)/libGLGFX.bc

ifeq ($(TARGET), $(ASMJS_TARGET))
	CXX:=em++
	CXXFLAGS+= $(EMXXFLAGS)
	BINARY_EXT:=html
	GLES2_LDFLAGS:=$(EMXX_LDFLAGS)
	GLES3_LDFLAGS:=$(EMXX_LDFLAGS)
	GLEW_LDFLAGS:=$(EMXX_LDFLAGS)
	GLES2_LDLIBS:=$(EMXX_LDLIBS)
	GLES3_LDLIBS:=$(EMXX_LDLIBS) -s USE_WEBGL2=1
	GLEW_LDLIBS:=$(EMXX_LDLIBS)
else
	CXXFLAGS+= -target $(TARGET)
endif

TEST_BINARIES:=$(SOURCES:.cpp=.$(BINARY_EXT))
GLES2_TEST_BINARIES:=$(addprefix bin/$(TARGET)/gles2/, $(TEST_BINARIES))
GLES3_TEST_BINARIES:=$(addprefix bin/$(TARGET)/gles3/, $(TEST_BINARIES))
GLEW_TEST_BINARIES:=$(addprefix bin/$(TARGET)/glew/, $(TEST_BINARIES))
ALL_TEST_BINARIES:=$(GLES2_TEST_BINARIES) $(GLES3_TEST_BINARIES) $(GLEW_TEST_BINARIES)

.PHONY: all modules tests gloop glgfx clean

all: directories tests

tests: $(ALL_TEST_BINARIES)

directories:
	mkdir -p bin/$(TARGET)/gles2 bin/$(TARGET)/gles3 bin/$(TARGET)/glew
	
modules: gloop glgfx

bin/$(TARGET)/gles2/libGLOOP.bc: gloop
	ln -sf ../../../gloop/$(GLES2_GLOOP) $(GLES2_GLOOP)

bin/$(TARGET)/gles3/libGLOOP.bc: gloop
	ln -sf ../../../gloop/$(GLES3_GLOOP) $(GLES3_GLOOP)

bin/$(TARGET)/glew/libGLOOP.bc: gloop
	ln -sf ../../../gloop/$(GLEW_GLOOP) $(GLEW_GLOOP)

bin/$(TARGET)/libGLGFX.bc: glgfx
	ln -sf ../../glgfx/$(GLGFX) $(GLGFX)

gloop:
	$(MAKE) -C gloop

glgfx: gloop
	$(MAKE) -C glgfx


bin/$(TARGET)/%.bc: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/gles2/%.all.bc: bin/$(TARGET)/%.bc $(GLES2_GLOOP) $(GLGFX)
	llvm-link -o $@ $^

bin/$(TARGET)/gles3/%.all.bc: bin/$(TARGET)/%.bc $(GLES3_GLOOP) $(GLGFX)
	llvm-link -o $@ $^

bin/$(TARGET)/glew/%.all.bc: bin/$(TARGET)/%.bc $(GLEW_GLOOP) $(GLGFX)
	llvm-link -o $@ $^

bin/$(TARGET)/glew/%.opt.bc: bin/$(TARGET)/glew/%.all.bc
	opt -std-link-opts -O2 $< -o $@

bin/$(TARGET)/gles2/%.opt.bc: bin/$(TARGET)/gles2/%.all.bc
	opt -std-link-opts -O2 $< -o $@

bin/$(TARGET)/gles3/%.opt.bc: bin/$(TARGET)/gles3/%.all.bc
	opt -std-link-opts -O2 $< -o $@

bin/$(TARGET)/gles2/%.$(BINARY_EXT): bin/$(TARGET)/gles2/%.opt.bc
	$(CXX) $(GLES2_LDLIBS) -o $@ $< $(GLES2_LDFLAGS)

bin/$(TARGET)/gles3/%.$(BINARY_EXT): bin/$(TARGET)/gles3/%.opt.bc
	$(CXX) $(GLES3_LDLIBS) -o $@ $< $(GLES3_LDFLAGS)

bin/$(TARGET)/glew/%.$(BINARY_EXT): bin/$(TARGET)/glew/%.opt.bc
	$(CXX) $(GLEW_LDLIBS) -o $@ $< $(GLEW_LDFLAGS)

clean:
	rm -rfv bin
	$(MAKE) -C gloop clean
	$(MAKE) -C glgfx clean
