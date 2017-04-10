#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=GLEW_Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/gloop/application.o \
	${OBJECTDIR}/gloop/bitfields/buffer_access_hint.o \
	${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint.o \
	${OBJECTDIR}/gloop/bitfields/clear_mask.o \
	${OBJECTDIR}/gloop/buffer.o \
	${OBJECTDIR}/gloop/draw_calls.o \
	${OBJECTDIR}/gloop/error/base_error.o \
	${OBJECTDIR}/gloop/exception/base_exception.o \
	${OBJECTDIR}/gloop/program.o \
	${OBJECTDIR}/gloop/program_uniform_binding.o \
	${OBJECTDIR}/gloop/shader.o \
	${OBJECTDIR}/gloop/states/blend.o \
	${OBJECTDIR}/gloop/states/clear.o \
	${OBJECTDIR}/gloop/states/depth_range.o \
	${OBJECTDIR}/gloop/states/scissor.o \
	${OBJECTDIR}/gloop/states/texture2D_parameters.o \
	${OBJECTDIR}/gloop/states/viewport.o \
	${OBJECTDIR}/gloop/texture2D.o \
	${OBJECTDIR}/gloop/tools.o \
	${OBJECTDIR}/gloop/uniform/uniform_bindings.o \
	${OBJECTDIR}/gloop/uniform/uniform_block_binding.o \
	${OBJECTDIR}/gloop/vertex_array.o \
	${OBJECTDIR}/gloop/vertex_attribute_binding.o \
	${OBJECTDIR}/gloop/vertex_attributes.o \
	${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o \
	${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o \
	${OBJECTDIR}/gloop/wrapper/gles2_gl.o \
	${OBJECTDIR}/gloop/wrapper/gles2_shaders_and_programs.o \
	${OBJECTDIR}/gloop/wrapper/gles2_states.o \
	${OBJECTDIR}/gloop/wrapper/gles2_texture_objects.o \
	${OBJECTDIR}/gloop/wrapper/gles2_vertex_arrays.o \
	${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o \
	${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o \
	${OBJECTDIR}/gloop/wrapper/glew_gl.o \
	${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o \
	${OBJECTDIR}/gloop/wrapper/glew_states.o \
	${OBJECTDIR}/gloop/wrapper/glew_texture_objects.o \
	${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o \
	${OBJECTDIR}/simple_rect.o \
	${OBJECTDIR}/test_runner.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-DGL=GLEW
CXXFLAGS=-DGL=GLEW

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs sdl2` `pkg-config --libs glew`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gloopcpp_test

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gloopcpp_test: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gloopcpp_test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/gloop/application.o: gloop/application.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/application.o gloop/application.cpp

${OBJECTDIR}/gloop/bitfields/buffer_access_hint.o: gloop/bitfields/buffer_access_hint.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/buffer_access_hint.o gloop/bitfields/buffer_access_hint.cpp

${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint.o: gloop/bitfields/buffer_immutable_storage_hint.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint.o gloop/bitfields/buffer_immutable_storage_hint.cpp

${OBJECTDIR}/gloop/bitfields/clear_mask.o: gloop/bitfields/clear_mask.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/clear_mask.o gloop/bitfields/clear_mask.cpp

${OBJECTDIR}/gloop/buffer.o: gloop/buffer.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/buffer.o gloop/buffer.cpp

${OBJECTDIR}/gloop/draw_calls.o: gloop/draw_calls.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/draw_calls.o gloop/draw_calls.cpp

${OBJECTDIR}/gloop/error/base_error.o: gloop/error/base_error.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/error
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/error/base_error.o gloop/error/base_error.cpp

${OBJECTDIR}/gloop/exception/base_exception.o: gloop/exception/base_exception.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/exception
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/exception/base_exception.o gloop/exception/base_exception.cpp

${OBJECTDIR}/gloop/program.o: gloop/program.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program.o gloop/program.cpp

${OBJECTDIR}/gloop/program_uniform_binding.o: gloop/program_uniform_binding.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program_uniform_binding.o gloop/program_uniform_binding.cpp

${OBJECTDIR}/gloop/shader.o: gloop/shader.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/shader.o gloop/shader.cpp

${OBJECTDIR}/gloop/states/blend.o: gloop/states/blend.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/blend.o gloop/states/blend.cpp

${OBJECTDIR}/gloop/states/clear.o: gloop/states/clear.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/clear.o gloop/states/clear.cpp

${OBJECTDIR}/gloop/states/depth_range.o: gloop/states/depth_range.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/depth_range.o gloop/states/depth_range.cpp

${OBJECTDIR}/gloop/states/scissor.o: gloop/states/scissor.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/scissor.o gloop/states/scissor.cpp

${OBJECTDIR}/gloop/states/texture2D_parameters.o: gloop/states/texture2D_parameters.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/texture2D_parameters.o gloop/states/texture2D_parameters.cpp

${OBJECTDIR}/gloop/states/viewport.o: gloop/states/viewport.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/viewport.o gloop/states/viewport.cpp

${OBJECTDIR}/gloop/texture2D.o: gloop/texture2D.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/texture2D.o gloop/texture2D.cpp

${OBJECTDIR}/gloop/tools.o: gloop/tools.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/tools.o gloop/tools.cpp

${OBJECTDIR}/gloop/uniform/uniform_bindings.o: gloop/uniform/uniform_bindings.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/uniform
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/uniform/uniform_bindings.o gloop/uniform/uniform_bindings.cpp

${OBJECTDIR}/gloop/uniform/uniform_block_binding.o: gloop/uniform/uniform_block_binding.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/uniform
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/uniform/uniform_block_binding.o gloop/uniform/uniform_block_binding.cpp

${OBJECTDIR}/gloop/vertex_array.o: gloop/vertex_array.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_array.o gloop/vertex_array.cpp

${OBJECTDIR}/gloop/vertex_attribute_binding.o: gloop/vertex_attribute_binding.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_attribute_binding.o gloop/vertex_attribute_binding.cpp

${OBJECTDIR}/gloop/vertex_attributes.o: gloop/vertex_attributes.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_attributes.o gloop/vertex_attributes.cpp

${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o: gloop/wrapper/gles2_buffer_objects.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o gloop/wrapper/gles2_buffer_objects.cpp

${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o: gloop/wrapper/gles2_drawing_commands.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o gloop/wrapper/gles2_drawing_commands.cpp

${OBJECTDIR}/gloop/wrapper/gles2_gl.o: gloop/wrapper/gles2_gl.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_gl.o gloop/wrapper/gles2_gl.cpp

${OBJECTDIR}/gloop/wrapper/gles2_shaders_and_programs.o: gloop/wrapper/gles2_shaders_and_programs.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_shaders_and_programs.o gloop/wrapper/gles2_shaders_and_programs.cpp

${OBJECTDIR}/gloop/wrapper/gles2_states.o: gloop/wrapper/gles2_states.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_states.o gloop/wrapper/gles2_states.cpp

${OBJECTDIR}/gloop/wrapper/gles2_texture_objects.o: gloop/wrapper/gles2_texture_objects.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_texture_objects.o gloop/wrapper/gles2_texture_objects.cpp

${OBJECTDIR}/gloop/wrapper/gles2_vertex_arrays.o: gloop/wrapper/gles2_vertex_arrays.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_vertex_arrays.o gloop/wrapper/gles2_vertex_arrays.cpp

${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o: gloop/wrapper/glew_buffer_objects.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o gloop/wrapper/glew_buffer_objects.cpp

${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o: gloop/wrapper/glew_drawing_commands.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o gloop/wrapper/glew_drawing_commands.cpp

${OBJECTDIR}/gloop/wrapper/glew_gl.o: gloop/wrapper/glew_gl.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_gl.o gloop/wrapper/glew_gl.cpp

${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o: gloop/wrapper/glew_shaders_and_programs.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o gloop/wrapper/glew_shaders_and_programs.cpp

${OBJECTDIR}/gloop/wrapper/glew_states.o: gloop/wrapper/glew_states.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_states.o gloop/wrapper/glew_states.cpp

${OBJECTDIR}/gloop/wrapper/glew_texture_objects.o: gloop/wrapper/glew_texture_objects.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_texture_objects.o gloop/wrapper/glew_texture_objects.cpp

${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o: gloop/wrapper/glew_vertex_arrays.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o gloop/wrapper/glew_vertex_arrays.cpp

${OBJECTDIR}/simple_rect.o: simple_rect.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/simple_rect.o simple_rect.cpp

${OBJECTDIR}/test_runner.o: test_runner.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test_runner.o test_runner.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
