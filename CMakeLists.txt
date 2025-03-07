cmake_minimum_required(VERSION 3.27.1)
project(dark-souls-remastered-cheats)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(submodules/ProcMemIO)
include_directories(submodules/ProcMemIO/include)

link_libraries(procmemio)
add_executable(dark-souls-remastered-cheats
	src/main.cpp
	src/cheat-invincibility.cpp
	src/cheat-lockitemcount.cpp
	src/cheat-lockspellcount.cpp
)
