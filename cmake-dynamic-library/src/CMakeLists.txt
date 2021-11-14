cmake_minimum_required(VERSION 3.10)
project (TestLibrary)
 
#For the shared library:
set ( PROJECT_LINK_LIBS libmy_library.so )
link_directories(~/Documents/github/project-examples/cmake-dynamic-library/build-linux-x86)

include_directories(~/Documents/github/project-examples/cmake-dynamic-library/include)
 
add_executable(main main.cpp)
target_link_libraries(main ${PROJECT_LINK_LIBS} )
