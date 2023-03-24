# CMakeList.txt : CMake project for HenryScripts-core, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("HenryScripts-core")

# Add source to this project's executable.
add_executable (HenryScripts-core "main.cpp" "src/headers/XInputHandler.h")

if(NOT PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  # Git auto-ignore out-of-source build directory
  file(GENERATE OUTPUT .gitignore CONTENT "*")
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HenryScripts-core PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
