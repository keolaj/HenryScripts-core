# CMakeList.txt : CMake project for HenryScripts-core, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("HenryScripts-core")

# C:\Users\Keola\dev\c++\HenryScripts-core\ViGEmClient\include\ViGEm\Client.h

set(VIGEM_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/ViGEmClient/include)
set(SOL2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/out/build/${CMAKE_PRESET}/sol2/single/include)
set(LUAJIT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/luajit/src)
set(SOURCES main.cpp ${VIGEM_INCLUDE_DIR}/ViGEm/Client.h)

# Add source to this project's executable.
add_executable (HenryScripts-core ${SOURCES} "src/XInputHandler.cpp")

# ViGEm
add_subdirectory(ViGEmClient)

# sol2
set(SOL2_LUA_VERSION "LuaJIT" CACHE STRING "The version of Lua used")
set(SOL2_SINGLE "Enable generation and build of single header files" ON)
add_subdirectory(sol2)

#luajit (you have to build luajit first. see instructions in readme)
add_library(LuaJIT SHARED IMPORTED )
set_property(TARGET LuaJIT PROPERTY IMPORTED_LOCATION ${LUAJIT_INCLUDE_DIR}/lua51.dll)
set_property(TARGET LuaJIT PROPERTY IMPORTED_IMPLIB ${LUAJIT_INCLUDE_DIR}/lua51.lib)

target_include_directories(HenryScripts-core PRIVATE ${VIGEM_INCLUDE_DIR} ${SOL2_INCLUDE_DIR} ${LUAJIT_INCLUDE_DIR})
target_link_libraries(HenryScripts-core PUBLIC ViGEmClient LuaJIT)



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HenryScripts-core PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
