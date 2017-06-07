MAKEFLAGS:=-j4

SOURCES:=sprite_test.cpp

OBJECTS:=$(SOURCES:.cpp=.bc)
DIR:=bin/glew bin/gles3 bin/asmjs

CXXFLAGS:=-DUSE_SDL_IMAGE -std=c++14 -O3 -I.
EMXXFLAGS:=$(CXXFLAGS) -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'

GLEW_OBJECTS:=$(addprefix bin/glew/, $(OBJECTS))
GLES3_OBJECTS:=$(addprefix bin/gles3/, $(OBJECTS))
ASMJS_OBJECTS:=$(addprefix bin/asmjs/, $(OBJECTS))

MODULES:=libGLOOP.bc libGLGFX.bc

GLEW_MODULES:=$(addprefix bin/glew/, $(MODULES))
GLES3_MODULES:=$(addprefix bin/gles3/, $(MODULES))
ASMJS_MODULES:=$(addprefix bin/asmjs/, $(MODULES))

.PHONY: all modules tests gloop glgfx clean

all: directories modules tests

tests: modules
	$(MAKE) bin/glew/sprite_test.exe
	$(MAKE) bin/gles3/sprite_test.exe

directories:
	mkdir -p $(DIR)

modules: gloop glgfx

gloop:
	$(MAKE) -C gloop
	ln -sf ../../gloop/bin/glew/libGLOOP.bc bin/glew/libGLOOP.bc
	ln -sf ../../gloop/bin/gles3/libGLOOP.bc bin/gles3/libGLOOP.bc

glgfx: gloop
	$(MAKE) -C glgfx
	ln -sf ../../glgfx/bin/glew/libGLGFX.bc bin/glew/libGLGFX.bc
	ln -sf ../../glgfx/bin/gles3/libGLGFX.bc bin/gles3/libGLGFX.bc

bin/glew/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLEW -o $@ $<

bin/gles3/%.bc: src/%.cpp
	clang++ $(CXXFLAGS) -c -emit-llvm -DGL=GLES3 -o $@ $<

bin/asmjs/%.bc: src/%.cpp
	em++ $(EMXXFLAGS) -c -emit-llvm -DGL=GLES2 -o $@ $<

bin/glew/sprite_test.exe: modules $(GLEW_OBJECTS)
	clang++ bin/glew/libGLOOP.bc bin/glew/libGLGFX.bc $(GLEW_OBJECTS) -O3 -o $@ -lGL -lGLEW -lSDL2 -lSDL2_image

bin/gles3/sprite_test.exe: modules $(GLES3_OBJECTS)
	clang++ bin/gles3/libGLOOP.bc bin/gles3/libGLGFX.bc $(GLES3_OBJECTS) -O3 -o $@ -lGLESv2 -lSDL2 -lSDL2_image

bin/asmjs/sprite_test.html: modules $(ASMJS_OBJECTS)
	em++ bin/asmjs/libGLOOP.bc bin/asmjs/libGLGFX.bc $(ASMJS_OBJECTS) -O3 -o $@

clean:
	rm -rfv bin
	$(MAKE) -C gloop clean
	$(MAKE) -C glgfx clean
