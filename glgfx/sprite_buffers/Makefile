SOURCES:=$(shell find ./src -name '*.cpp')
HEADERS:=$(shell find -name '*.hpp')

SOURCES:=$(SOURCES:./src/%=%)
HEADERS:=$(HEADERS:./%=%)

OBJECTS:=$(SOURCES:.cpp=.bc)
TARGET:=$(shell clang --version | grep "Target:" | awk '{print $$2}')
BINARY:=libGLGFX_sprite_buffers.bc

GLOOP_INC:=../..

CXXFLAGS:=-std=c++14 -I. -I$(GLOOP_INC) -Wall -Wno-missing-braces
EMXXFLAGS:=-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'
CXX:=clang++

TARGET_OBJECTS:=$(addprefix bin/$(TARGET)/, $(OBJECTS))

ifeq ($(TARGET), asmjs-unknown-emscripten)
	CXX:=em++
	CXXFLAGS+= $(EMXXFLAGS)
else
	CXXFLAGS+= -target $(TARGET)
endif

.PHONY: all directories libs

all: directories libs

libs: bin/$(TARGET)/$(BINARY)

directories:
	mkdir -p bin/$(TARGET)

bin/$(TARGET)/%.bc: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/$(BINARY): $(TARGET_OBJECTS)
	llvm-link $^ -o $@

clean:
	rm -rfv bin
