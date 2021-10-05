cmake_minimum_required(VERSION 3.18)

project(EmergnInterview)

get_filename_component(DIR_ROOT ${CMAKE_CURRENT_SOURCE_DIR} PATH)

set(EMERGN ${DIR_ROOT}/Emergn)
set(EMERGN_SRC ${EMERGN}/src)
set(EMERGN_TESTS ${EMERGN}/tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -fconcepts --pedantic")

install(DIRECTORY "bin" DESTINATION ${EMERGN})

include_directories(${EMERGN_SRC})
include_directories(${EMERGN_TESTS})

set(EXECUTABLE_OUTPUT_PATH ${EMERGN}/bin)

include(${EMERGN}/etc/cmake/gtest.cmake)

add_subdirectory(tests)
