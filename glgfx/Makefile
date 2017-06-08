SOURCES:=$(shell find ./src -name '*.cpp')
HEADERS:=$(shell find -name '*.hpp')

SOURCES:=$(SOURCES:./src/%=%)
HEADERS:=$(HEADERS:./%=%)

OBJECTS:=$(SOURCES:.cpp=.bc)
TARGET:=$(shell clang --version | grep "Target:" | awk '{print $$2}')

CXXFLAGS:=-std=c++14 -I. -Wall -Wno-missing-braces
CXX:=clang++

TARGET_OBJECTS:=$(addprefix bin/$(TARGET)/, $(OBJECTS))

MODULES:=\
libGLGFX_base.bc \
libGLGFX_sprite_buffers.bc \
libGLGFX_renderers.bc

ifeq ($(TARGET), asmjs-unknown-emscripten)
	CXX:=em++
else
	CXXFLAGS+= -target $(TARGET)
endif

TARGET_MODULES:=$(addprefix bin/$(TARGET)/, $(MODULES))

.PHONY: all directories libs modules renderers sprite_buffers headers

all: directories libs headers

libs: bin/$(TARGET)/libGLGFX_base.bc bin/$(TARGET)/libGLGFX.bc

modules: renderers sprite_buffers

headers: ../glgfx.hpp

renderers:
	$(MAKE) -C renderers
	ln -sf ../../renderers/bin/$(TARGET)/libGLGFX_renderers.bc bin/$(TARGET)/libGLGFX_renderers.bc

sprite_buffers:
	$(MAKE) -C sprite_buffers
	ln -sf ../../sprite_buffers/bin/$(TARGET)/libGLGFX_sprite_buffers.bc bin/$(TARGET)/libGLGFX_sprite_buffers.bc

directories:
	mkdir -p bin/$(TARGET)

bin/$(TARGET)/%.bc: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/libGLGFX_base.bc: $(TARGET_OBJECTS)
	llvm-link $^ -o $@

bin/$(TARGET)/libGLGFX.bc: modules
	llvm-link $(TARGET_MODULES) -o $@

../glgfx.hpp: $(HEADERS)
	echo $(HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \"glgfx/"$$h"\""}' > $@

clean:
	rm -rfv bin
	rm -rfv ../glgfx.hpp
	$(MAKE) -C renderers clean
	$(MAKE) -C sprite_buffers clean
