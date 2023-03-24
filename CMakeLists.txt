# CMakeList.txt : CMake project for HenryScripts-core, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("HenryScripts-core")

# C:\Users\Keola\dev\c++\HenryScripts-core\ViGEmClient\include\ViGEm\Client.h

set(VIGEM_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/ViGEmClient/include)
set(SOURCES main.cpp ${VIGEM_INCLUDE_DIR}/ViGEm/Client.h)

# Add source to this project's executable.
add_executable (HenryScripts-core ${SOURCES})
target_include_directories(HenryScripts-core PRIVATE ${VIGEM_INCLUDE_DIR})


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HenryScripts-core PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
