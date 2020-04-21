project(PPPC4DMID C CXX)
cmake_minimum_required(VERSION 2.8)

set( CMAKE_VERBOSE_MAKEFILE off )
set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )
set( CMAKE_C_COMPILER "gcc" )
set( CMAKE_C_FLAGS "-O3" )
set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_CXX_FLAGS "-O3 -std=c++11" )
set( PPPC4DMID_INCLUDES )
set( PPPC4DMID_LIBRARIES )

# include
include_directories( "${CMAKE_SOURCE_DIR}/include" )

# GSL (external)
find_package(GSL)
if(GSL_FOUND)
    set(HAVE_LIBGSL 1)
    list(APPEND PPPC4DMID_INCLUDES ${GSL_INCLUDE_DIR})
    list(APPEND PPPC4DMID_LIBRARIES ${GSL_LIBRARIES})
else(GSL_FOUND)
    message(FATAL_ERROR "Require GSL: set GSL_HOME")
endif(GSL_FOUND)

# add source files
set( PPPC4DMID_SRCS
	src/dm-profile.cpp
	src/dm-spectrum.cpp
	)

# make library
include_directories (include ${PPPC4DMID_INCLUDES})
add_library( PPPC4DMID_LIB ${PPPC4DMID_SRCS} ${PPPC4DMID_INCLUDES} )

# make executables
add_executable(PPPC4DMID src/main.cpp)
target_link_libraries (PPPC4DMID PPPC4DMID_LIB ${PPPC4DMID_LIBRARIES})

# show summary
message (STATUS "CMAKE_SYSTEM .......... = ${CMAKE_SYSTEM}")
message (STATUS "BUILD_SHARED_LIBS ..... = ${BUILD_SHARED_LIBS}")
message (STATUS "CMAKE_C_COMPILER ...... = ${CMAKE_C_COMPILER}")
message (STATUS "CMAKE_C_FLAGS ......... = ${CMAKE_C_FLAGS}")
message (STATUS "CMAKE_CXX_COMPILER .... = ${CMAKE_CXX_COMPILER}")
message (STATUS "CMAKE_CXX_FLAGS ....... = ${CMAKE_CXX_FLAGS}")
message (STATUS "CMAKE_INCLUDE_PATH .... = ${CMAKE_INCLUDE_PATH}")
message (STATUS "PPPC4DMID_INCLUDES ...... = ${PPPC4DMID_INCLUDES}")
message (STATUS "PPPC4DMID_LIBRARIES ..... = ${PPPC4DMID_LIBRARIES}")
