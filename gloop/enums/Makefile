SOURCES:=$(shell find -name '*.cpp')
HEADERS:=$(shell find -name '*.hpp')

SOURCES:=$(SOURCES:./src/%=%)
HEADERS:=$(HEADERS:./%=%)

OBJECTS:=$(SOURCES:.cpp=.bc)
DIR:=bin/glew bin/gles3 bin/asmjs

CXXFLAGS:=-DUSE_SDL_IMAGE -std=c++14 -O3 -I.
EMXXFLAGS:=$(CXXFLAGS)

GLEW_OBJECTS:=$(addprefix bin/glew/, $(OBJECTS))
GLES3_OBJECTS:=$(addprefix bin/gles3/, $(OBJECTS))
ASMJS_OBJECTS:=$(addprefix bin/asmjs/, $(OBJECTS))

.PHONY: all directories libs headers clean

all: directories libs headers

libs: bin/glew/libGLOOP_enums.bc bin/gles3/libGLOOP_enums.bc

headers: ../enums.hpp

directories:
	mkdir -p $(DIR)

bin/glew/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLEW -o $@ $<

bin/gles3/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLES3 -o $@ $<

bin/asmjs/%.bc: src/%.cpp
	em++ $(EMXXFLAGS) -c -emit-llvm -DGL=GLES2 -o $@ $<

bin/glew/libGLOOP_enums.bc: $(GLEW_OBJECTS)
	llvm-link $(GLEW_OBJECTS) -o $@

bin/gles3/libGLOOP_enums.bc: $(GLES3_OBJECTS)
	llvm-link $(GLES3_OBJECTS) -o $@

bin/asmjs/libGLOOP_enums.bc: $(ASMJS_OBJECTS)
	llvm-link $(ASMJS_OBJECTS) -o $@

../enums.hpp:
	echo $(HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \"enums/"$$h"\""}' > $@

clean:
	rm -rfv bin
	rm -fv ../enums.hpp
