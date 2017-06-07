GENERIC_SOURCES:=$(shell find ./src -name '*.cpp')
ASMJS_SOURCES:=$(shell find ./gles2_src -name '*.cpp')
GLES3_SOURCES:=$(shell find ./gles3_src -name '*.cpp')
GLEW_SOURCES:=$(shell find ./glew_src -name '*.cpp')

$(info "RAW GLES3 Sources: [$(GLES3_SOURCES)]")

HEADERS:=$(shell find -path ./impl -prune -o -name '*.hpp')
HEADERS:=$(filter-out ./impl, $(HEADERS))
HEADERS:=$(HEADERS:./%=%)
GENERIC_SOURCES:=$(GENERIC_SOURCES:./src/%=%)
ASMJS_SOURCES:=$(ASMJS_SOURCES:./gles2_src/%=%)
GLES3_SOURCES:=$(GLES3_SOURCES:./gles3_src/%=%)
GLEW_SOURCES:=$(GLEW_SOURCES:./glew_src/%=%)

GLES3_SOURCES+= $(GENERIC_SOURCES)
ASMJS_SOURCES+= $(GENERIC_SOURCES)
GLEW_SOURCES+= $(GENERIC_SOURCES)

$(info "GLES3 Sources: [$(GLES3_SOURCES)]")

GLEW_OBJECTS:=$(GLEW_SOURCES:.cpp=.bc)
ASMJS_OBJECTS:=$(ASMJS_SOURCES:.cpp=.bc)
GLES3_OBJECTS:=$(GLES3_SOURCES:.cpp=.bc)

GLEW_OBJECTS:=$(addprefix bin/glew/, $(GLEW_OBJECTS))
ASMJS_OBJECTS:=$(addprefix bin/asmjs/, $(ASMJS_OBJECTS))
GLES3_OBJECTS:=$(addprefix bin/gles3/, $(GLES3_OBJECTS))

CXXFLAGS:=-DUSE_SDL_IMAGE -std=c++14 -O3 -I. -Iimpl
EMXXFLAGS:=$(CXXFLAGS)

DIR:= bin/generic bin/asmjs bin/gles3 bin/glew

.PHONY: all directories libs headers clean

all: directories headers libs

libs: bin/gles3/libGLOOP_wrapper.bc bin/glew/libGLOOP_wrapper.bc

headers: ../wrapper.hpp

directories:
	mkdir -p $(DIR)

bin/glew/%.bc: glew_src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLEW -o $@ $<

bin/gles3/%.bc: gles3_src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLES3 -o $@ $<

bin/asmjs/%.bc: gles2_src/%.cpp
	em++ $(EMXXFLAGS) -c -emit-llvm -DGL=GLES2 -o $@ $<

bin/gles3/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLES3 -o $@ $<

bin/glew/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLEW -o $@ $<

bin/asmjs/%.bc: src/%.cpp
	em++ $(EMXXFLAGS) -c -emit-llvm -DGL=GLES2 -o $@ $<

bin/glew/libGLOOP_wrapper.bc: $(GLEW_OBJECTS)
	llvm-link $(GLEW_OBJECTS) -o $@

bin/gles3/libGLOOP_wrapper.bc: $(GLES3_OBJECTS)
	llvm-link $(GLES3_OBJECTS) -o $@

bin/asmjs/libGLOOP_wrapper.bc: $(ASMJS_OBJECTS)
	llvm-link $(ASMJS_OBJECTS) -o $@

../wrapper.hpp:
	echo $(HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \"wrapper/"$$h"\""}' > $@

clean:
	rm -rfv bin
	rm -fv ../wrapper.hpp
