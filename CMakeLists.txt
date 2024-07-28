cmake_minimum_required(VERSION 3.5.0)
project(WindowsTest VERSION 1.0.0)

#set(CMAKE_CXX_FLAGS
   # "-g -pthread"
#)

set(CMAKE_CXX_STANDARD 14)
#specify whether the chosen C++ standard must be strictly adhered to by the compiler
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(TEST_LIB
    gtest_main
    gtest
)

link_directories(
    ${PROJECT_SOURCE_DIR}/lib
)

enable_testing()

#semaphare
add_executable(Semaphare ${PROJECT_SOURCE_DIR}/test/semaphare.cpp)
target_link_libraries(Semaphare gtest_main gtest)
add_custom_command(TARGET Semaphare
    COMMAND echo "compile semaphare test..."
)
