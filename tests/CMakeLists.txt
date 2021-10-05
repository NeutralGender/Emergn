set(BINARY tests)

file(GLOB_RECURSE SOURCES
    ${EMERGN_SRC}/*.cpp
    ${EMERGN_TESTS}/*.cpp
    "${PROJECT_SOURCE_DIR}/tests/main.cpp"
)

add_executable( ${BINARY} ${SOURCES} )

target_link_libraries(${BINARY} gtest pthread)
