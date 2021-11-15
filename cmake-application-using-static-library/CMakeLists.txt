cmake_minimum_required(VERSION 3.10)
project (TestStaticLibrary)
 
#For the static library:
set ( PROJECT_LINK_LIBS liblibCalcInterExtraPolation.a )
link_directories(~/Documents/github/project-examples/cmake-static-library/build-linux-x86)

include_directories(include)
 
add_executable(main src/main.cpp)
target_link_libraries(main ${PROJECT_LINK_LIBS} )
