SOURCES:=$(shell find ./src -name '*.cpp')
HEADERS:=$(shell find . -maxdepth 1 -name '*.hpp')

SOURCES:=$(SOURCES:./src/%=%)
HEADERS:=$(HEADERS:./%=%)

MODULE_HEADERS:=bitfields.hpp draw_calls.hpp enums.hpp errors.hpp exceptions.hpp states.hpp uniforms.hpp wrapper.hpp objects.hpp
HEADERS:=$(filter-out $(MODULE_HEADERS), $(HEADERS))

OBJECTS:=$(SOURCES:.cpp=.bc)
DIR:=bin/glew bin/gles3 bin/asmjs

CXXFLAGS:=-DUSE_SDL_IMAGE -std=c++14 -O3 -I.
EMXXFLAGS:=$(CXXFLAGS) -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'

GLEW_OBJECTS:=$(addprefix bin/glew/, $(OBJECTS))
GLES3_OBJECTS:=$(addprefix bin/gles3/, $(OBJECTS))
ASMJS_OBJECTS:=$(addprefix bin/asmjs/, $(OBJECTS))

MODULES:=\
libGLOOP_bitfields.bc \
libGLOOP_draw_calls.bc \
libGLOOP_enums.bc \
libGLOOP_errors.bc \
libGLOOP_exceptions.bc \
libGLOOP_states.bc \
libGLOOP_uniforms.bc \
libGLOOP_wrapper.bc \
libGLOOP_base.bc

GLEW_MODULES:=$(addprefix bin/glew/, $(MODULES))
GLES3_MODULES:=$(addprefix bin/gles3/, $(MODULES))
ASMJS_MODULES:=$(addprefix bin/asmjs/, $(MODULES))

.PHONY: all directories libs headers clean modules bitfields draw_calls enums errors exceptions states uniforms wrapper

all: directories libs headers

modules: bitfields draw_calls enums errors exceptions states uniforms wrapper

bitfields:
	$(MAKE) -C bitfields
	ln -sf ../../bitfields/bin/glew/libGLOOP_bitfields.bc bin/glew/libGLOOP_bitfields.bc
	ln -sf ../../bitfields/bin/gles3/libGLOOP_bitfields.bc bin/gles3/libGLOOP_bitfields.bc

draw_calls:
	$(MAKE) -C draw
	ln -sf ../../draw/bin/glew/libGLOOP_draw_calls.bc bin/glew/libGLOOP_draw_calls.bc
	ln -sf ../../draw/bin/gles3/libGLOOP_draw_calls.bc bin/gles3/libGLOOP_draw_calls.bc

enums:
	$(MAKE) -C enums
	ln -sf ../../enums/bin/glew/libGLOOP_enums.bc bin/glew/libGLOOP_enums.bc
	ln -sf ../../enums/bin/gles3/libGLOOP_enums.bc bin/gles3/libGLOOP_enums.bc

errors:
	$(MAKE) -C error
	ln -sf ../../error/bin/glew/libGLOOP_errors.bc bin/glew/libGLOOP_errors.bc
	ln -sf ../../error/bin/gles3/libGLOOP_errors.bc bin/gles3/libGLOOP_errors.bc

exceptions:
	$(MAKE) -C exception
	ln -sf ../../exception/bin/glew/libGLOOP_exceptions.bc bin/glew/libGLOOP_exceptions.bc
	ln -sf ../../exception/bin/gles3/libGLOOP_exceptions.bc bin/gles3/libGLOOP_exceptions.bc

states:
	$(MAKE) -C states
	ln -sf ../../states/bin/glew/libGLOOP_states.bc bin/glew/libGLOOP_states.bc
	ln -sf ../../states/bin/gles3/libGLOOP_states.bc bin/gles3/libGLOOP_states.bc

uniforms:
	$(MAKE) -C uniform
	ln -sf ../../uniform/bin/glew/libGLOOP_uniforms.bc bin/glew/libGLOOP_uniforms.bc
	ln -sf ../../uniform/bin/gles3/libGLOOP_uniforms.bc bin/gles3/libGLOOP_uniforms.bc

wrapper:
	$(MAKE) -C wrapper
	ln -sf ../../wrapper/bin/glew/libGLOOP_wrapper.bc bin/glew/libGLOOP_wrapper.bc
	ln -sf ../../wrapper/bin/gles3/libGLOOP_wrapper.bc bin/gles3/libGLOOP_wrapper.bc

libs: bin/glew/libGLOOP_base.bc bin/gles3/libGLOOP_base.bc bin/glew/libGLOOP.bc bin/gles3/libGLOOP.bc

headers: objects.hpp ../gloop.hpp

directories:
	mkdir -p $(DIR)

bin/glew/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLEW -o $@ $<

bin/gles3/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLES3 -o $@ $<

bin/asmjs/%.bc: src/%.cpp
	clang++ $(EMXXFLAGS) -c -emit-llvm -DGL=GLES2 -o $@ $<

bin/glew/libGLOOP_base.bc: $(GLEW_OBJECTS)
	llvm-link $(GLEW_OBJECTS) -o $@

bin/gles3/libGLOOP_base.bc: $(GLES3_OBJECTS)
	llvm-link $(GLES3_OBJECTS) -o $@

bin/asmjs/libGLOOP_base.bc: $(ASMJS_OBJECTS)
	llvm-link $(ASMJS_OBJECTS) -o $@

bin/glew/libGLOOP.bc: modules
	llvm-link $(GLEW_MODULES) -o $@

bin/gles3/libGLOOP.bc: modules
	llvm-link $(GLES3_MODULES) -o $@

bin/asmjs/libGLOOP.bc: modules
	llvm-link $(ASMJS_MODULES) -o $@

objects.hpp:
	echo $(HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \""$$h"\""}' > $@

../gloop.hpp:
	echo $(MODULE_HEADERS) | awk '{split($$0, a); print "#pragma once"; for(h in a) print "#include \"gloop/"$$h"\""}' > $@

clean:
	rm -rfv bin
	rm -fv objects.hpp
	rm -fv ../gloop.hpp
	$(MAKE) -C bitfields clean
	$(MAKE) -C draw clean
	$(MAKE) -C enums clean
	$(MAKE) -C error clean
	$(MAKE) -C exception clean
	$(MAKE) -C states clean
	$(MAKE) -C uniform clean
	$(MAKE) -C wrapper clean
