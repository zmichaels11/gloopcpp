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
CND_CONF=GLEW_Debug
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
	${OBJECTDIR}/gloop/states/viewport.o \
	${OBJECTDIR}/gloop/tools.o \
	${OBJECTDIR}/gloop/uniform/uniform_bindings.o \
	${OBJECTDIR}/gloop/uniform/uniform_block_binding.o \
	${OBJECTDIR}/gloop/vertex_array.o \
	${OBJECTDIR}/gloop/vertex_attribute_binding.o \
	${OBJECTDIR}/gloop/vertex_attributes.o \
	${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o \
	${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o \
	${OBJECTDIR}/gloop/wrapper/gles2_gl.o \
	${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o \
	${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o \
	${OBJECTDIR}/gloop/wrapper/glew_gl.o \
	${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o \
	${OBJECTDIR}/gloop/wrapper/glew_states.o \
	${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/basic_rect.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/camstreamtest

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/camstreamtest: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/camstreamtest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/gloop/application.o: gloop/application.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/application.o gloop/application.cpp

${OBJECTDIR}/gloop/bitfields/buffer_access_hint.o: gloop/bitfields/buffer_access_hint.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/buffer_access_hint.o gloop/bitfields/buffer_access_hint.cpp

${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint.o: gloop/bitfields/buffer_immutable_storage_hint.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint.o gloop/bitfields/buffer_immutable_storage_hint.cpp

${OBJECTDIR}/gloop/bitfields/clear_mask.o: gloop/bitfields/clear_mask.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/clear_mask.o gloop/bitfields/clear_mask.cpp

${OBJECTDIR}/gloop/buffer.o: gloop/buffer.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/buffer.o gloop/buffer.cpp

${OBJECTDIR}/gloop/draw_calls.o: gloop/draw_calls.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/draw_calls.o gloop/draw_calls.cpp

${OBJECTDIR}/gloop/error/base_error.o: gloop/error/base_error.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/error
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/error/base_error.o gloop/error/base_error.cpp

${OBJECTDIR}/gloop/exception/base_exception.o: gloop/exception/base_exception.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/exception/base_exception.o gloop/exception/base_exception.cpp

${OBJECTDIR}/gloop/program.o: gloop/program.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program.o gloop/program.cpp

${OBJECTDIR}/gloop/program_uniform_binding.o: gloop/program_uniform_binding.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program_uniform_binding.o gloop/program_uniform_binding.cpp

${OBJECTDIR}/gloop/shader.o: gloop/shader.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/shader.o gloop/shader.cpp

${OBJECTDIR}/gloop/states/blend.o: gloop/states/blend.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/blend.o gloop/states/blend.cpp

${OBJECTDIR}/gloop/states/clear.o: gloop/states/clear.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/clear.o gloop/states/clear.cpp

${OBJECTDIR}/gloop/states/depth_range.o: gloop/states/depth_range.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/depth_range.o gloop/states/depth_range.cpp

${OBJECTDIR}/gloop/states/scissor.o: gloop/states/scissor.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/scissor.o gloop/states/scissor.cpp

${OBJECTDIR}/gloop/states/viewport.o: gloop/states/viewport.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/viewport.o gloop/states/viewport.cpp

${OBJECTDIR}/gloop/tools.o: gloop/tools.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/tools.o gloop/tools.cpp

${OBJECTDIR}/gloop/uniform/uniform_bindings.o: gloop/uniform/uniform_bindings.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/uniform
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/uniform/uniform_bindings.o gloop/uniform/uniform_bindings.cpp

${OBJECTDIR}/gloop/uniform/uniform_block_binding.o: gloop/uniform/uniform_block_binding.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/uniform
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/uniform/uniform_block_binding.o gloop/uniform/uniform_block_binding.cpp

${OBJECTDIR}/gloop/vertex_array.o: gloop/vertex_array.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_array.o gloop/vertex_array.cpp

${OBJECTDIR}/gloop/vertex_attribute_binding.o: gloop/vertex_attribute_binding.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_attribute_binding.o gloop/vertex_attribute_binding.cpp

${OBJECTDIR}/gloop/vertex_attributes.o: gloop/vertex_attributes.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_attributes.o gloop/vertex_attributes.cpp

${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o: gloop/wrapper/gles2_buffer_objects.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o gloop/wrapper/gles2_buffer_objects.cpp

${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o: gloop/wrapper/gles2_drawing_commands.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o gloop/wrapper/gles2_drawing_commands.cpp

${OBJECTDIR}/gloop/wrapper/gles2_gl.o: gloop/wrapper/gles2_gl.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_gl.o gloop/wrapper/gles2_gl.cpp

${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o: gloop/wrapper/glew_buffer_objects.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o gloop/wrapper/glew_buffer_objects.cpp

${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o: gloop/wrapper/glew_drawing_commands.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o gloop/wrapper/glew_drawing_commands.cpp

${OBJECTDIR}/gloop/wrapper/glew_gl.o: gloop/wrapper/glew_gl.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_gl.o gloop/wrapper/glew_gl.cpp

${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o: gloop/wrapper/glew_shaders_and_programs.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o gloop/wrapper/glew_shaders_and_programs.cpp

${OBJECTDIR}/gloop/wrapper/glew_states.o: gloop/wrapper/glew_states.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_states.o gloop/wrapper/glew_states.cpp

${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o: gloop/wrapper/glew_vertex_arrays.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o gloop/wrapper/glew_vertex_arrays.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/basic_rect.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/basic_rect.o: tests/basic_rect.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/basic_rect.o tests/basic_rect.cpp


${OBJECTDIR}/gloop/application_nomain.o: ${OBJECTDIR}/gloop/application.o gloop/application.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/application.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/application_nomain.o gloop/application.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/application.o ${OBJECTDIR}/gloop/application_nomain.o;\
	fi

${OBJECTDIR}/gloop/bitfields/buffer_access_hint_nomain.o: ${OBJECTDIR}/gloop/bitfields/buffer_access_hint.o gloop/bitfields/buffer_access_hint.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/bitfields/buffer_access_hint.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/buffer_access_hint_nomain.o gloop/bitfields/buffer_access_hint.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/bitfields/buffer_access_hint.o ${OBJECTDIR}/gloop/bitfields/buffer_access_hint_nomain.o;\
	fi

${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint_nomain.o: ${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint.o gloop/bitfields/buffer_immutable_storage_hint.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint_nomain.o gloop/bitfields/buffer_immutable_storage_hint.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint.o ${OBJECTDIR}/gloop/bitfields/buffer_immutable_storage_hint_nomain.o;\
	fi

${OBJECTDIR}/gloop/bitfields/clear_mask_nomain.o: ${OBJECTDIR}/gloop/bitfields/clear_mask.o gloop/bitfields/clear_mask.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/bitfields
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/bitfields/clear_mask.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/bitfields/clear_mask_nomain.o gloop/bitfields/clear_mask.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/bitfields/clear_mask.o ${OBJECTDIR}/gloop/bitfields/clear_mask_nomain.o;\
	fi

${OBJECTDIR}/gloop/buffer_nomain.o: ${OBJECTDIR}/gloop/buffer.o gloop/buffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/buffer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/buffer_nomain.o gloop/buffer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/buffer.o ${OBJECTDIR}/gloop/buffer_nomain.o;\
	fi

${OBJECTDIR}/gloop/draw_calls_nomain.o: ${OBJECTDIR}/gloop/draw_calls.o gloop/draw_calls.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/draw_calls.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/draw_calls_nomain.o gloop/draw_calls.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/draw_calls.o ${OBJECTDIR}/gloop/draw_calls_nomain.o;\
	fi

${OBJECTDIR}/gloop/error/base_error_nomain.o: ${OBJECTDIR}/gloop/error/base_error.o gloop/error/base_error.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/error
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/error/base_error.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/error/base_error_nomain.o gloop/error/base_error.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/error/base_error.o ${OBJECTDIR}/gloop/error/base_error_nomain.o;\
	fi

${OBJECTDIR}/gloop/exception/base_exception_nomain.o: ${OBJECTDIR}/gloop/exception/base_exception.o gloop/exception/base_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/exception
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/exception/base_exception.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/exception/base_exception_nomain.o gloop/exception/base_exception.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/exception/base_exception.o ${OBJECTDIR}/gloop/exception/base_exception_nomain.o;\
	fi

${OBJECTDIR}/gloop/program_nomain.o: ${OBJECTDIR}/gloop/program.o gloop/program.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/program.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program_nomain.o gloop/program.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/program.o ${OBJECTDIR}/gloop/program_nomain.o;\
	fi

${OBJECTDIR}/gloop/program_uniform_binding_nomain.o: ${OBJECTDIR}/gloop/program_uniform_binding.o gloop/program_uniform_binding.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/program_uniform_binding.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program_uniform_binding_nomain.o gloop/program_uniform_binding.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/program_uniform_binding.o ${OBJECTDIR}/gloop/program_uniform_binding_nomain.o;\
	fi

${OBJECTDIR}/gloop/shader_nomain.o: ${OBJECTDIR}/gloop/shader.o gloop/shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/shader.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/shader_nomain.o gloop/shader.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/shader.o ${OBJECTDIR}/gloop/shader_nomain.o;\
	fi

${OBJECTDIR}/gloop/states/blend_nomain.o: ${OBJECTDIR}/gloop/states/blend.o gloop/states/blend.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/states/blend.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/blend_nomain.o gloop/states/blend.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/states/blend.o ${OBJECTDIR}/gloop/states/blend_nomain.o;\
	fi

${OBJECTDIR}/gloop/states/clear_nomain.o: ${OBJECTDIR}/gloop/states/clear.o gloop/states/clear.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/states/clear.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/clear_nomain.o gloop/states/clear.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/states/clear.o ${OBJECTDIR}/gloop/states/clear_nomain.o;\
	fi

${OBJECTDIR}/gloop/states/depth_range_nomain.o: ${OBJECTDIR}/gloop/states/depth_range.o gloop/states/depth_range.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/states/depth_range.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/depth_range_nomain.o gloop/states/depth_range.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/states/depth_range.o ${OBJECTDIR}/gloop/states/depth_range_nomain.o;\
	fi

${OBJECTDIR}/gloop/states/scissor_nomain.o: ${OBJECTDIR}/gloop/states/scissor.o gloop/states/scissor.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/states/scissor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/scissor_nomain.o gloop/states/scissor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/states/scissor.o ${OBJECTDIR}/gloop/states/scissor_nomain.o;\
	fi

${OBJECTDIR}/gloop/states/viewport_nomain.o: ${OBJECTDIR}/gloop/states/viewport.o gloop/states/viewport.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/states/viewport.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/states/viewport_nomain.o gloop/states/viewport.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/states/viewport.o ${OBJECTDIR}/gloop/states/viewport_nomain.o;\
	fi

${OBJECTDIR}/gloop/tools_nomain.o: ${OBJECTDIR}/gloop/tools.o gloop/tools.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/tools.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/tools_nomain.o gloop/tools.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/tools.o ${OBJECTDIR}/gloop/tools_nomain.o;\
	fi

${OBJECTDIR}/gloop/uniform/uniform_bindings_nomain.o: ${OBJECTDIR}/gloop/uniform/uniform_bindings.o gloop/uniform/uniform_bindings.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/uniform
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/uniform/uniform_bindings.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/uniform/uniform_bindings_nomain.o gloop/uniform/uniform_bindings.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/uniform/uniform_bindings.o ${OBJECTDIR}/gloop/uniform/uniform_bindings_nomain.o;\
	fi

${OBJECTDIR}/gloop/uniform/uniform_block_binding_nomain.o: ${OBJECTDIR}/gloop/uniform/uniform_block_binding.o gloop/uniform/uniform_block_binding.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/uniform
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/uniform/uniform_block_binding.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/uniform/uniform_block_binding_nomain.o gloop/uniform/uniform_block_binding.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/uniform/uniform_block_binding.o ${OBJECTDIR}/gloop/uniform/uniform_block_binding_nomain.o;\
	fi

${OBJECTDIR}/gloop/vertex_array_nomain.o: ${OBJECTDIR}/gloop/vertex_array.o gloop/vertex_array.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/vertex_array.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_array_nomain.o gloop/vertex_array.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/vertex_array.o ${OBJECTDIR}/gloop/vertex_array_nomain.o;\
	fi

${OBJECTDIR}/gloop/vertex_attribute_binding_nomain.o: ${OBJECTDIR}/gloop/vertex_attribute_binding.o gloop/vertex_attribute_binding.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/vertex_attribute_binding.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_attribute_binding_nomain.o gloop/vertex_attribute_binding.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/vertex_attribute_binding.o ${OBJECTDIR}/gloop/vertex_attribute_binding_nomain.o;\
	fi

${OBJECTDIR}/gloop/vertex_attributes_nomain.o: ${OBJECTDIR}/gloop/vertex_attributes.o gloop/vertex_attributes.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/vertex_attributes.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_attributes_nomain.o gloop/vertex_attributes.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/vertex_attributes.o ${OBJECTDIR}/gloop/vertex_attributes_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects_nomain.o: ${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o gloop/wrapper/gles2_buffer_objects.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects_nomain.o gloop/wrapper/gles2_buffer_objects.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects.o ${OBJECTDIR}/gloop/wrapper/gles2_buffer_objects_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands_nomain.o: ${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o gloop/wrapper/gles2_drawing_commands.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands_nomain.o gloop/wrapper/gles2_drawing_commands.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands.o ${OBJECTDIR}/gloop/wrapper/gles2_drawing_commands_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/gles2_gl_nomain.o: ${OBJECTDIR}/gloop/wrapper/gles2_gl.o gloop/wrapper/gles2_gl.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/gles2_gl.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/gles2_gl_nomain.o gloop/wrapper/gles2_gl.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/gles2_gl.o ${OBJECTDIR}/gloop/wrapper/gles2_gl_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/glew_buffer_objects_nomain.o: ${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o gloop/wrapper/glew_buffer_objects.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_buffer_objects_nomain.o gloop/wrapper/glew_buffer_objects.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/glew_buffer_objects.o ${OBJECTDIR}/gloop/wrapper/glew_buffer_objects_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/glew_drawing_commands_nomain.o: ${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o gloop/wrapper/glew_drawing_commands.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_drawing_commands_nomain.o gloop/wrapper/glew_drawing_commands.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/glew_drawing_commands.o ${OBJECTDIR}/gloop/wrapper/glew_drawing_commands_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/glew_gl_nomain.o: ${OBJECTDIR}/gloop/wrapper/glew_gl.o gloop/wrapper/glew_gl.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/glew_gl.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_gl_nomain.o gloop/wrapper/glew_gl.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/glew_gl.o ${OBJECTDIR}/gloop/wrapper/glew_gl_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs_nomain.o: ${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o gloop/wrapper/glew_shaders_and_programs.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs_nomain.o gloop/wrapper/glew_shaders_and_programs.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs.o ${OBJECTDIR}/gloop/wrapper/glew_shaders_and_programs_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/glew_states_nomain.o: ${OBJECTDIR}/gloop/wrapper/glew_states.o gloop/wrapper/glew_states.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/glew_states.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_states_nomain.o gloop/wrapper/glew_states.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/glew_states.o ${OBJECTDIR}/gloop/wrapper/glew_states_nomain.o;\
	fi

${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays_nomain.o: ${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o gloop/wrapper/glew_vertex_arrays.cpp 
	${MKDIR} -p ${OBJECTDIR}/gloop/wrapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays_nomain.o gloop/wrapper/glew_vertex_arrays.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays.o ${OBJECTDIR}/gloop/wrapper/glew_vertex_arrays_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
