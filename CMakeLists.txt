cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER g++)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

# Debug macros
add_definitions(-DMEMORY_PROTECTION)
add_definitions(-DREGISTERS_PROTECTION)
add_definitions(-DPRINT_DEBUG)

project(mips_emulator)

add_subdirectory(src)