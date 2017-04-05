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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/gloop/application.o \
	${OBJECTDIR}/gloop/buffer.o \
	${OBJECTDIR}/gloop/draw_calls.o \
	${OBJECTDIR}/gloop/error.o \
	${OBJECTDIR}/gloop/exception.o \
	${OBJECTDIR}/gloop/program.o \
	${OBJECTDIR}/gloop/program_uniform_binding.o \
	${OBJECTDIR}/gloop/program_uniform_block_binding.o \
	${OBJECTDIR}/gloop/shader.o \
	${OBJECTDIR}/gloop/state_objects/depth_range.o \
	${OBJECTDIR}/gloop/state_objects/scissor.o \
	${OBJECTDIR}/gloop/state_objects/viewport.o \
	${OBJECTDIR}/gloop/tools.o \
	${OBJECTDIR}/gloop/vertex_array.o \
	${OBJECTDIR}/gloop/vertex_attribute_binding.o \
	${OBJECTDIR}/gloop/vertex_attributes.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

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

${OBJECTDIR}/gloop/buffer.o: gloop/buffer.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/buffer.o gloop/buffer.cpp

${OBJECTDIR}/gloop/draw_calls.o: gloop/draw_calls.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/draw_calls.o gloop/draw_calls.cpp

${OBJECTDIR}/gloop/error.o: gloop/error.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/error.o gloop/error.cpp

${OBJECTDIR}/gloop/exception.o: gloop/exception.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/exception.o gloop/exception.cpp

${OBJECTDIR}/gloop/program.o: gloop/program.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program.o gloop/program.cpp

${OBJECTDIR}/gloop/program_uniform_binding.o: gloop/program_uniform_binding.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program_uniform_binding.o gloop/program_uniform_binding.cpp

${OBJECTDIR}/gloop/program_uniform_block_binding.o: gloop/program_uniform_block_binding.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program_uniform_block_binding.o gloop/program_uniform_block_binding.cpp

${OBJECTDIR}/gloop/shader.o: gloop/shader.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/shader.o gloop/shader.cpp

${OBJECTDIR}/gloop/state_objects/depth_range.o: gloop/state_objects/depth_range.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/state_objects
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/state_objects/depth_range.o gloop/state_objects/depth_range.cpp

${OBJECTDIR}/gloop/state_objects/scissor.o: gloop/state_objects/scissor.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/state_objects
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/state_objects/scissor.o gloop/state_objects/scissor.cpp

${OBJECTDIR}/gloop/state_objects/viewport.o: gloop/state_objects/viewport.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop/state_objects
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/state_objects/viewport.o gloop/state_objects/viewport.cpp

${OBJECTDIR}/gloop/tools.o: gloop/tools.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/tools.o gloop/tools.cpp

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

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
