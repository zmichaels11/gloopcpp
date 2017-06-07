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

MODULES:=\
libGLGFX_base.bc \
libGLGFX_sprite_buffers.bc \
libGLGFX_renderers.bc

GLEW_MODULES:=$(addprefix bin/glew/, $(MODULES))
GLES3_MODULES:=$(addprefix bin/glew/, $(MODULES))
ASMJS_MODULES:=$(addprefix bin/asmjs/, $(MODULES))

.PHONY: all directories libs modules renderers sprite_buffers headers

all: directories libs headers

libs: bin/glew/libGLGFX_base.bc bin/gles3/libGLGFX_base.bc bin/glew/libGLGFX.bc bin/gles3/libGLGFX.bc

modules: renderers sprite_buffers

headers: ../glgfx.hpp

renderers:
	$(MAKE) -C renderers
	ln -sf ../../renderers/bin/glew/libGLGFX_renderers.bc bin/glew/libGLGFX_renderers.bc
	ln -sf ../../renderers/bin/gles3/libGLGFX_renderers.bc bin/gles3/libGLGFX_renderers.bc

sprite_buffers:
	$(MAKE) -C sprite_buffers
	ln -sf ../../sprite_buffers/bin/glew/libGLGFX_sprite_buffers.bc bin/glew/libGLGFX_sprite_buffers.bc
	ln -sf ../../sprite_buffers/bin/gles3/libGLGFX_sprite_buffers.bc bin/gles3/libGLGFX_sprite_buffers.bc

directories:
	mkdir -p $(DIR)

bin/glew/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLEW -o $@ $<

bin/gles3/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLES3 -o $@ $<

bin/asmjs/%.bc: src/%.cpp
	em++ $(EMXXFLAGS) -c -emit-llvm -DGL=GLES2 -o $@ $<

bin/glew/libGLGFX_base.bc: $(GLEW_OBJECTS)
	llvm-link $(GLEW_OBJECTS) -o $@

bin/gles3/libGLGFX_base.bc: $(GLES3_OBJECTS)
	llvm-link $(GLES3_OBJECTS) -o $@

bin/asmjs/libGLGFX_base.bc: $(ASMJS_OBJECTS)
	llvm-link $(ASMJS_OBJECTS) -o $@

bin/glew/libGLGFX.bc: modules bin/glew/libGLGFX_base.bc
	llvm-link $(GLEW_MODULES) -o $@

bin/gles3/libGLGFX.bc: modules bin/gles3/libGLGFX_base.bc
	llvm-link $(GLES3_MODULES) -o $@

bin/asmjs/libGLGFX.bc: modules bin/asmjs/libGLGFX_base.bc
	llvm-link $(ASMJS_MODULES) -o $@

../glgfx.hpp:
	echo $(HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \"glgfx/"$$h"\""}' > $@

clean:
	rm -rfv bin
	rm -rfv ../glgfx.hpp
	$(MAKE) -C renderers clean
	$(MAKE) -C sprite_buffers clean
