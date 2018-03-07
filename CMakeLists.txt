cmake_minimum_required (VERSION 3.1)

# Project step I: Check dependencies
# ------------------------------------------------------------------------------------------------------
include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)

# Check CPP11
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# Project step II: Set up project name
# ------------------------------------------------------------------------------------------------------
set(PROJ_MAIN_NAME guide-programming-cpp)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install" CACHE PATH "Changing default install path" FORCE)
endif()

# Project step III: Add all folders
# ------------------------------------------------------------------------------------------------------
add_subdirectory(basics)
add_subdirectory(vitals)
