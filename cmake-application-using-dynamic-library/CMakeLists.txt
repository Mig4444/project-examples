cmake_minimum_required(VERSION 3.10)
project (TestDynamicLibrary)
 
#For the shared library:
set ( PROJECT_LINK_LIBS libmylibrary.so )
link_directories(build-linux-x86)

include_directories(include)
 
add_executable(main src/main.cpp)
target_link_libraries(main ${PROJECT_LINK_LIBS} )
