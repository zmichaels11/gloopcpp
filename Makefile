SOURCES:=sprite_test.cpp

OBJECTS:=$(SOURCES:.cpp=.bc)

CXXFLAGS:=-std=c++14 -I. -Wall -Wno-missing-braces
EMXXFLAGS:=-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'

GLES2_LDFLAGS:=-lGLESv2 -lSDL2 -lSDL2_image
GLES3_LDFLAGS:=-lGLESv2 -lSDL2 -lSDL2_image
GLEW_LDFLAGS:=-lGL -lGLEW -lSDL2 -lSDL2_image
EMXX_LDFLAGS:=-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'

CXX:=clang++

TARGET:=$(shell clang --version | grep "Target:" | awk '{print $$2}')
ASMJS_TARGET:=asmjs-unknown-emscripten
BINARY_EXT:=exe

MODULES:=libGLOOP.bc libGLGFX.bc

TARGET_OBJECTS:=$(addprefix bin/$(TARGET)/, $(OBJECTS))
TARGET_SPRITE_TEST_OBJECTS:=bin/$(TARGET)/sprite_test.bc bin/$(TARGET)/libGLGFX.bc

ifeq ($(TARGET), $(ASMJS_TARGET))
	CXX:=em++
	CXXFLAGS+= $(EMXXFLAGS)
	BINARY_EXT:=html
	GLES2_LDFLAGS:=$(EMXX_LINKFLAGS)
	GLES3_LDFLAGS:=$(EMXX_LINKFLAGS)
	GLEW_LDFLAGS:=$(EMXX_LINKFLAGS)
else
	CXXFLAGS+= -target $(TARGET)
endif

.PHONY: all modules tests gloop glgfx clean

all: directories modules tests

tests: modules
	$(MAKE) bin/$(TARGET)/glew/sprite_test.exe
	$(MAKE) bin/$(TARGET)/gles3/sprite_test.exe

directories:
	mkdir -p bin/$(TARGET)/gles2 bin/$(TARGET)/gles3 bin/$(TARGET)/glew

modules: gloop glgfx

gloop:
	$(MAKE) -C gloop
	ln -sf ../../../gloop/bin/$(TARGET)/gles2/libGLOOP.bc bin/$(TARGET)/gles2/libGLOOP.bc
	ln -sf ../../../gloop/bin/$(TARGET)/gles3/libGLOOP.bc bin/$(TARGET)/gles3/libGLOOP.bc
	ln -sf ../../../gloop/bin/$(TARGET)/glew/libGLOOP.bc bin/$(TARGET)/glew/libGLOOP.bc

glgfx: gloop
	$(MAKE) -C glgfx
	ln -sf ../../glgfx/bin/$(TARGET)/libGLGFX.bc bin/$(TARGET)/libGLGFX.bc

bin/$(TARGET)/%.bc: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/gles2/sprite_test.$(BINARY_EXT): bin/$(TARGET)/sprite_test.bc gloop glgfx
	$(CXX) -o $@ bin/$(TARGET)/gles2/libGLOOP.bc $(TARGET_SPRITE_TEST_OBJECTS) $(GLES2_LDFLAGS)

bin/$(TARGET)/gles3/sprite_test.$(BINARY_EXT): bin/$(TARGET)/sprite_test.bc gloop glgfx
	$(CXX) -o $@ bin/$(TARGET)/gles3/libGLOOP.bc $(TARGET_SPRITE_TEST_OBJECTS) $(GLES3_LDFLAGS)

bin/$(TARGET)/glew/sprite_test.$(BINARY_EXT): bin/$(TARGET)/sprite_test.bc gloop glgfx
	$(CXX) -o $@ bin/$(TARGET)/glew/libGLOOP.bc $(TARGET_SPRITE_TEST_OBJECTS) $(GLEW_LDFLAGS)

clean:
	rm -rfv bin
	$(MAKE) -C gloop clean
	$(MAKE) -C glgfx clean
