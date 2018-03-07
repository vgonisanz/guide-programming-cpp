# The following loop create an executable from each source file
# ------------------------------------------------------------------------------------------------------
file(GLOB ALL_FILES_CURRENT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" "*.cpp")

foreach(CURRENT_FILE ${ALL_FILES_CURRENT_PATH})
    get_filename_component(FILENAME ${CURRENT_FILE} NAME_WE)
    MESSAGE("Compiling file: ${FILENAME}")
    add_executable(${FILENAME} ${FILENAME}.cpp)
endforeach()
