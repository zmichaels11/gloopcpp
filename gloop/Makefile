SOURCES:=$(shell find ./src -name '*.cpp')
HEADERS:=$(shell find . -maxdepth 1 -name '*.hpp')

SOURCES:=$(SOURCES:./src/%=%)
HEADERS:=$(HEADERS:./%=%)

MODULE_HEADERS:=bitfields.hpp draw_calls.hpp enums.hpp errors.hpp exceptions.hpp states.hpp uniforms.hpp wrapper.hpp objects.hpp
HEADERS:=$(filter-out $(MODULE_HEADERS), $(HEADERS))

OBJECTS:=$(SOURCES:.cpp=.bc)
TARGET:=$(shell clang --version | grep "Target:" | awk '{print $$2}')

EMXXFLAGS:=-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'
CXXFLAGS:=-std=c++14 -I. -Wall -Wno-missing-braces
CXX:=clang++

TARGET_OBJECTS:=$(addprefix bin/$(TARGET)/, $(OBJECTS))

ifeq ($(TARGET), asmjs-unknown-emscripten)
	CXX:=em++
	CXXFLAGS+= $(EMXXFLAGS)
else
	CXXFLAGS+= -target $(TARGET)
endif

MODULES:=\
libGLOOP_bitfields.bc \
libGLOOP_draw_calls.bc \
libGLOOP_enums.bc \
libGLOOP_errors.bc \
libGLOOP_exceptions.bc \
libGLOOP_states.bc \
libGLOOP_uniforms.bc \
libGLOOP_base.bc

TARGET_MODULES:=$(addprefix bin/$(TARGET)/, $(MODULES))

.PHONY: all directories libs headers clean modules bitfields draw_calls enums errors exceptions states uniforms wrapper

all: directories libs headers

modules: bitfields draw_calls enums errors exceptions states uniforms wrapper

bitfields:
	$(MAKE) -C bitfields
	ln -sf ../../bitfields/bin/$(TARGET)/libGLOOP_bitfields.bc bin/$(TARGET)/libGLOOP_bitfields.bc

draw_calls:
	$(MAKE) -C draw
	ln -sf ../../draw/bin/$(TARGET)/libGLOOP_draw_calls.bc bin/$(TARGET)/libGLOOP_draw_calls.bc

enums:
	$(MAKE) -C enums
	ln -sf ../../enums/bin/$(TARGET)/libGLOOP_enums.bc bin/$(TARGET)/libGLOOP_enums.bc

errors:
	$(MAKE) -C error
	ln -sf ../../error/bin/$(TARGET)/libGLOOP_errors.bc bin/$(TARGET)/libGLOOP_errors.bc

exceptions:
	$(MAKE) -C exception
	ln -sf ../../exception/bin/$(TARGET)/libGLOOP_exceptions.bc bin/$(TARGET)/libGLOOP_exceptions.bc

states:
	$(MAKE) -C states
	ln -sf ../../states/bin/$(TARGET)/libGLOOP_states.bc bin/$(TARGET)/libGLOOP_states.bc

uniforms:
	$(MAKE) -C uniform
	ln -sf ../../uniform/bin/$(TARGET)/libGLOOP_uniforms.bc bin/$(TARGET)/libGLOOP_uniforms.bc

wrapper:
	$(MAKE) -C wrapper
	ln -sf ../../../wrapper/bin/$(TARGET)/glew/libGLOOP_wrapper.bc bin/$(TARGET)/glew/libGLOOP_wrapper.bc
	ln -sf ../../../wrapper/bin/$(TARGET)/gles2/libGLOOP_wrapper.bc bin/$(TARGET)/gles2/libGLOOP_wrapper.bc
	ln -sf ../../../wrapper/bin/$(TARGET)/gles3/libGLOOP_wrapper.bc bin/$(TARGET)/gles3/libGLOOP_wrapper.bc

libs: bin/$(TARGET)/libGLOOP_base.bc bin/$(TARGET)/glew/libGLOOP.bc bin/$(TARGET)/gles2/libGLOOP.bc bin/$(TARGET)/gles3/libGLOOP.bc

headers: objects.hpp ../gloop.hpp
	$(CXX) $(CXXFLAGS) -o objects.hpp.gch objects.hpp
	$(CXX) $(CXXFLAGS) -o ../gloop.hpp.gch ../gloop.hpp

directories:
	mkdir -p bin/$(TARGET) bin/$(TARGET)/glew bin/$(TARGET)/gles2 bin/$(TARGET)/gles3

bin/$(TARGET)/%.bc: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/libGLOOP_base.bc: $(TARGET_OBJECTS)
	llvm-link $^ -o $@

bin/$(TARGET)/glew/libGLOOP.bc: modules
	llvm-link $(TARGET_MODULES) bin/$(TARGET)/glew/libGLOOP_wrapper.bc -o $@

bin/$(TARGET)/gles2/libGLOOP.bc: modules
	llvm-link $(TARGET_MODULES) bin/$(TARGET)/gles2/libGLOOP_wrapper.bc -o $@

bin/$(TARGET)/gles3/libGLOOP.bc: modules
	llvm-link $(TARGET_MODULES) bin/$(TARGET)/gles3/libGLOOP_wrapper.bc -o $@

objects.hpp:
	echo $(HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \""$$h"\""}' > $@

../gloop.hpp:
	echo $(MODULE_HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \"gloop/"$$h"\""}' > $@

clean:
	rm -rfv bin
	rm -fv objects.hpp
	rm -fv objects.hpp.gch
	rm -fv ../gloop.hpp
	rm -fv ../gloop.hpp.gch
	$(MAKE) -C bitfields clean
	$(MAKE) -C draw clean
	$(MAKE) -C enums clean
	$(MAKE) -C error clean
	$(MAKE) -C exception clean
	$(MAKE) -C states clean
	$(MAKE) -C uniform clean
	$(MAKE) -C wrapper clean
