cmake_minimum_required(VERSION 3.5.0)
project ( SerialiseDemo )
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread -fno-stack-protector")

find_package(Boost 1.55 REQUIRED system serialization)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/*)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
