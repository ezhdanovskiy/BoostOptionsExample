cmake_minimum_required(VERSION 3.3)
project(Signature)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(Signature ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(Signature ${Boost_LIBRARIES})
