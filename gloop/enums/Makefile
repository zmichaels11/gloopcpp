SOURCES:=$(shell find -name '*.cpp')
HEADERS:=$(shell find -name '*.hpp')

SOURCES:=$(SOURCES:./src/%=%)
HEADERS:=$(HEADERS:./%=%)

OBJECTS:=$(SOURCES:.cpp=.bc)
TARGET:=$(shell clang --version | grep "Target:" | awk '{print $$2}')
BINARY:=libGLOOP_enums.bc

CXXFLAGS:=-std=c++14 -I. -Wall
CXX:=clang++

TARGET_OBJECTS:=$(addprefix bin/$(TARGET)/, $(OBJECTS))

ifeq ($(TARGET), asmjs-unknown-emscripten)
	CXX:=em++
else
	CXXFLAGS+= -target $(TARGET)
endif

.PHONY: all directories libs headers clean

all: directories libs headers

libs: bin/$(TARGET)/$(BINARY)

headers: ../enums.hpp
	$(CXX) $(CXXFLAGS) -o $<.gch $<

directories:
	mkdir -p bin/$(TARGET)

bin/$(TARGET)/%.bc: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -emit-llvm -o $@ $<

bin/$(TARGET)/$(BINARY): $(TARGET_OBJECTS)
	llvm-link $^ -o $@

../enums.hpp: $(HEADERS)
	echo $(HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \"enums/"$$h"\""}' > $@

clean:
	rm -rfv bin
	rm -fv ../enums.hpp
	rm -fv ../enums.hpp.gch
