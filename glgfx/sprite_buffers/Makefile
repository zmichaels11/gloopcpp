SOURCES:=$(shell find ./src -name '*.cpp')
HEADERS:=$(shell find -name '*.hpp')

SOURCES:=$(SOURCES:./src/%=%)
HEADERS:=$(HEADERS:./%=%)

OBJECTS:=$(SOURCES:.cpp=.bc)
DIR:=bin/glew bin/asmjs bin/gles3

CXXFLAGS:=-DUSE_SDL_IMAGE -std=c++14 -O3 -I.
EMXXFLAGS:=$(CXXFLAGS)

GLEW_OBJECTS:=$(addprefix bin/glew/, $(OBJECTS))
GLES3_OBJECTS:=$(addprefix bin/gles3/, $(OBJECTS))
ASMJS_OBJECTS:=$(addprefix bin/asmjs/, $(OBJECTS))

.PHONY: all directories libs

all: directories libs

libs: bin/glew/libGLGFX_sprite_buffers.bc bin/gles3/libGLGFX_sprite_buffers.bc

directories:
	mkdir -p $(DIR)

bin/glew/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLEW -o $@ $<

bin/gles3/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLES3 -o $@ $<

bin/asmjs/%.bc: src/%.cpp
	em++ $(EMXXFLAGS) -c -emit-llvm -DGL=GLES2 -o $@ $<

bin/glew/libGLGFX_sprite_buffers.bc: $(GLEW_OBJECTS)
	llvm-link $(GLEW_OBJECTS) -o $@

bin/gles3/libGLGFX_sprite_buffers.bc: $(GLES3_OBJECTS) 
	llvm-link $(GLES3_OBJECTS) -o $@

bin/asmjs/libGLGFX_sprite_buffers.bc: $(ASMJS_OBJECTS)
	llvm-link $(ASMJS_OBJECTS) -o $@

clean:
	rm -rfv bin
