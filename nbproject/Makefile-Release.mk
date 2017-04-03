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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/application.o \
	${OBJECTDIR}/gloop/buffer.o \
	${OBJECTDIR}/gloop/exception.o \
	${OBJECTDIR}/gloop/program.o \
	${OBJECTDIR}/gloop/shader.o \
	${OBJECTDIR}/gloop/tools.o \
	${OBJECTDIR}/gloop/vertex_array.o \
	${OBJECTDIR}/gloop/vertex_attributes.o \
	${OBJECTDIR}/gltools.o \
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

${OBJECTDIR}/application.o: application.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/application.o application.cpp

${OBJECTDIR}/gloop/buffer.o: gloop/buffer.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/buffer.o gloop/buffer.cpp

${OBJECTDIR}/gloop/exception.o: gloop/exception.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/exception.o gloop/exception.cpp

${OBJECTDIR}/gloop/program.o: gloop/program.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/program.o gloop/program.cpp

${OBJECTDIR}/gloop/shader.o: gloop/shader.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/shader.o gloop/shader.cpp

${OBJECTDIR}/gloop/tools.o: gloop/tools.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/tools.o gloop/tools.cpp

${OBJECTDIR}/gloop/vertex_array.o: gloop/vertex_array.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_array.o gloop/vertex_array.cpp

${OBJECTDIR}/gloop/vertex_attributes.o: gloop/vertex_attributes.cpp
	${MKDIR} -p ${OBJECTDIR}/gloop
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gloop/vertex_attributes.o gloop/vertex_attributes.cpp

${OBJECTDIR}/gltools.o: gltools.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gltools.o gltools.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `pkg-config --cflags sdl2` `pkg-config --cflags glew` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
