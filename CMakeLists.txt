cmake_minimum_required(VERSION 3.27.1)
project(dark-souls-remastered-cheats)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(${INCLUDE_PATH})
link_directories(${LIBRARY_PATH})

link_libraries(procmemio)
add_executable(dark-souls-remastered-cheats
	src/main.cpp
	src/cheat-invincibility.cpp
	src/cheat-lockitemcount.cpp
	src/cheat-lockspellcount.cpp
)
