cmake_minimum_required (VERSION 3.1)

# Project step I: Check dependencies
# ------------------------------------------------------------------------------------------------------
include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)

set(CMAKE_CXX_STANDARD 11)

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
add_subdirectory(tricky)
