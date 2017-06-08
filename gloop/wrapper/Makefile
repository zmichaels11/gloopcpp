GENERIC_SOURCES:=$(shell find ./src -name '*.cpp')
GLES2_SOURCES:=$(shell find ./gles2_src -name '*.cpp')
GLES3_SOURCES:=$(shell find ./gles3_src -name '*.cpp')
GLEW_SOURCES:=$(shell find ./glew_src -name '*.cpp')

HEADERS:=$(shell find -path ./impl -prune -o -name '*.hpp')
HEADERS:=$(filter-out ./impl, $(HEADERS))
HEADERS:=$(HEADERS:./%=%)

GENERIC_SOURCES:=$(GENERIC_SOURCES:./src/%=%)
GLES2_SOURCES:=$(GLES2_SOURCES:./gles2_src/%=%)
GLES3_SOURCES:=$(GLES3_SOURCES:./gles3_src/%=%)
GLEW_SOURCES:=$(GLEW_SOURCES:./glew_src/%=%)

GENERIC_OBJECTS:=$(GENERIC_SOURCES:.cpp=.bc)
GLEW_OBJECTS:=$(GLEW_SOURCES:.cpp=.bc)
GLES2_OBJECTS:=$(GLES2_SOURCES:.cpp=.bc)
GLES3_OBJECTS:=$(GLES3_SOURCES:.cpp=.bc)

TARGET:=$(shell clang --version | grep "Target:" | awk '{print $$2}')
TARGET_GENERIC_OBJECTS:=$(addprefix bin/$(TARGET)/, $(GENERIC_OBJECTS))
BINARY:=libGLOOP_wrapper.bc

GLEW_OBJECTS:=$(addprefix bin/$(TARGET)/glew/, $(GLEW_OBJECTS))
GLES2_OBJECTS:=$(addprefix bin/$(TARGET)/gles2/, $(GLES2_OBJECTS))
GLES3_OBJECTS:=$(addprefix bin/$(TARGET)/gles3/, $(GLES3_OBJECTS))

GLEW_OBJECTS+=$(TARGET_GENERIC_OBJECTS)
GLES2_OBJECTS+=$(TARGET_GENERIC_OBJECTS)
GLES3_OBJECTS+=$(TARGET_GENERIC_OBJECTS)

GLEWFLAGS:=-DGL=GLEW
GLES2FLAGS:=-DGL=GLES2
GLES3FLAGS:=-DGL=GLES3
CXXFLAGS:=-std=c++14 -I. -Iimpl
CXX:=clang++

ifeq ($(TARGET), asmjs-unknown-emscripten)
	CXX:=em++
else
	CXXFLAGS+= -target $(TARGET)
endif

.PHONY: all directories libs headers clean

all: directories headers libs

libs: bin/$(TARGET)/glew/$(BINARY) bin/$(TARGET)/gles2/$(BINARY) bin/$(TARGET)/gles3/$(BINARY)

headers: ../wrapper.hpp

directories:
	mkdir -p bin/$(TARGET)/glew bin/$(TARGET)/gles2 bin/$(TARGET)/gles3

bin/$(TARGET)/%.bc: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/glew/%.bc: glew_src/%.cpp
	$(CXX) $(CXXFLAGS) $(GLEWFLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/gles2/%.bc: gles2_src/%.cpp
	$(CXX) $(CXXFLAGS) $(GLES2FLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/gles3/%.bc: gles3_src/%.cpp
	$(CXX) $(CXXFLAGS) $(GLES3FLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/glew/$(BINARY): $(GLEW_OBJECTS)
	llvm-link $^ -o $@

bin/$(TARGET)/gles2/$(BINARY): $(GLES2_OBJECTS)
	llvm-link $^ -o $@

bin/$(TARGET)/gles3/$(BINARY): $(GLES3_OBJECTS)
	llvm-link $^ -o $@

../wrapper.hpp: $(HEADERS)
	echo $(HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \"wrapper/"$$h"\""}' > $@

clean:
	rm -rfv bin
	rm -fv ../wrapper.hpp
