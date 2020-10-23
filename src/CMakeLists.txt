#check if cmake version satisfies the required minimum
cmake_minimum_required(VERSION 3.2)
#declare the project
project(MPAGSCipher VERSION 0.1.0)
#output all command lines as default, can be run from command line as 'make VERBOSE=1'
set(CMAKE_VERBOSE_MAKEFILE ON)

#set a C++ stnadard directly (used before O.o)
#set(CMAKE_CXX_STANDARD 14)

#declare building the mpags-cipher main programme
add_executable(mpags-cipher 
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    MPAGSCipher/ProcessCommandLine.cpp
    )

#tell the compiler where to look for header/src files
target_include_directories(mpags-cipher PRIVATE MPAGSCipher)

#use the standard set of flags for the course
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

#make sure the compilrer knows hwich features from which library are used
target_compile_features(mpags-cipher
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
    )