GL=glew
LDLIBS=`pkg-config --libs sdl2` `pkg-config --libs SDL2_image`

CXX=clang++
OBJ_EXT=.o

EMSCRIPTEN_FLAGS=-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'

ifeq ($(GL), webgl)
	CXX=em++
	OBJ_EXT=.bc
endif

ifeq ($(CXX), clang++)
	CXXFLAGS+= -emit-llvm
	OBJ_EXT=.bc
endif

ifeq ($(GL), glew)
	LDLIBS+= `pkg-config --libs glew`
	CXXFLAGS=-DGL=GLEW -DUSE_SDL_IMAGE
else ifeq ($(GL), gles3)
	LDLIBS+= `pkg-config --libs glesv2`
	CXXFLAGS=-DGL=GLES3 -DUSE_SDL_IMAGE
else ifeq ($(GL), gles2)
	LDLIBS+= `pkg-config --libs glesv2`
	CXXFLAGS=-DGL=GLES2 -DUSE_SDL_IMAGE
else ifeq ($(GL), webgl)
	LDLIBS=$(EMSCRIPTEN_FLAGS)
	CXXFLAGS=-DGL=GLES2 -DUSE_SDL_IMAGE $(EMSCRIPTEN_FLAGS)
endif

CXXFLAGS+= -std=c++14 -O2

GLOOP_SOURCES=\
gloop/bitfields/buffer_access_hint.cpp \
gloop/bitfields/buffer_immutable_storage_hint.cpp \
gloop/bitfields/clear_mask.cpp \
gloop/enums/framebuffer_attachment.cpp \
gloop/error/base_error.cpp \
gloop/exception/base_exception.cpp \
gloop/states/blend.cpp \
gloop/states/clear.cpp \
gloop/states/depth_range.cpp \
gloop/states/scissor.cpp \
gloop/states/texture2D_parameters.cpp \
gloop/states/viewport.cpp \
gloop/uniform/uniform_bindings.cpp \
gloop/uniform/uniform_block_binding.cpp \
gloop/wrapper/gles2_buffer_objects.cpp \
gloop/wrapper/gles2_drawing_commands.cpp \
gloop/wrapper/gles2_framebuffer_objects.cpp \
gloop/wrapper/gles2_gl.cpp \
gloop/wrapper/gles2_shaders_and_programs.cpp \
gloop/wrapper/gles2_states.cpp \
gloop/wrapper/gles2_texture_objects.cpp \
gloop/wrapper/gles2_vertex_arrays.cpp \
gloop/wrapper/gles3_buffer_objects.cpp \
gloop/wrapper/gles3_drawing_commands.cpp \
gloop/wrapper/gles3_framebuffer_objects.cpp \
gloop/wrapper/gles3_gl.cpp \
gloop/wrapper/gles3_shaders_and_programs.cpp \
gloop/wrapper/gles3_states.cpp \
gloop/wrapper/gles3_texture_objects.cpp \
gloop/wrapper/gles3_vertex_arrays.cpp \
gloop/wrapper/glew_buffer_objects.cpp \
gloop/wrapper/glew_drawing_commands.cpp \
gloop/wrapper/glew_framebuffer_objects.cpp \
gloop/wrapper/glew_gl.cpp \
gloop/wrapper/glew_shaders_and_programs.cpp \
gloop/wrapper/glew_states.cpp \
gloop/wrapper/glew_texture_objects.cpp \
gloop/wrapper/glew_vertex_arrays.cpp \
gloop/wrapper/wrapper.cpp \
gloop/application.cpp \
gloop/buffer.cpp \
gloop/draw_calls.cpp \
gloop/framebuffer.cpp \
gloop/matrices.cpp \
gloop/pixel_formats.cpp \
gloop/program.cpp \
gloop/program_uniform_binding.cpp \
gloop/renderbuffer.cpp \
gloop/shader.cpp \
gloop/texture2D.cpp \
gloop/tools.cpp \
gloop/vertex_array.cpp \
gloop/vertex_attribute_binding.cpp \
gloop/vertex_attributes.cpp

GLGFX_SOURCES=\
glgfx/renderers/line_renderer.cpp \
glgfx/renderers/masked_image_renderer.cpp \
glgfx/renderers/solid_renderer.cpp \
glgfx/renderers/sprite_renderer.cpp \
glgfx/sprite_buffers/vbo_sprite_buffer.cpp \
glgfx/blend_mode.cpp \
glgfx/graphics.cpp \
glgfx/skyline_packer.cpp \
glgfx/sprite_sheet.cpp

TEST_SOURCES=\
sprite_test.cpp

GLOOP_OBJECTS=$(GLOOP_SOURCES:.cpp=$(OBJ_EXT))
GLGFX_OBJECTS=$(GLGFX_SOURCES:.cpp=$(OBJ_EXT))
TEST_OBJECTS=$(TEST_SOURCES:.cpp=$(OBJ_EXT))

TARGET_LIBS=libGLOOP.bc libGLGFX.bc
TARGET_TESTS=\
sprite_test.exe \
sprite_test.html sprite_test.js sprite_test.data sprite_test.html.mem

all: $(TARGET_LIBS)

%.bc: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

libGLOOP.bc: $(GLOOP_OBJECTS)
	llvm-link $(GLOOP_OBJECTS) -o $@
	opt -std-link-opts -O3 $@ -o $@

libGLGFX.bc: $(GLGFX_OBJECTS)
	llvm-link $(GLGFX_OBJECTS) -o $@
	opt -std-link-opts -O3 $@ -o $@

sprite_test.exe: sprite_test.bc libGLOOP.bc libGLGFX.bc
	clang++ $(LDFLAGS) sprite_test.bc libGLOOP.bc libGLGFX.bc -o $@ $(LDLIBS)

sprite_test.html: sprite_test.bc libGLOOP.bc libGLGFX.bc
	em++ $(LDFLAGS) sprite_test.bc libGLOOP.bc libGLGFX.bc -o $@ $(LDLIBS) --preload-file tests --preload-file tests/data --preload-file glgfx/shaders -O2

clean:
	rm -fv $(TARGET_TESTS)
	rm -fv $(TARGET_LIBS)
	rm -fv $(GLGFX_OBJECTS)
	rm -fv $(GLOOP_OBJECTS)
	rm -fv $(TEST_OBJECTS)

emsdk_env.mk: .emsdk_portable/emsdk_set_env.sh
	sed 's/"//g ; s/=/:=/' < $< > $@

emsdk_activate: emsdk_install
	.emsdk_portable/emsdk activate latest
	.emsdk_portable/emsdk construct_env

emsdk_install: emsdk_update
	.emsd_portable/emsdk update
