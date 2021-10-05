set(BINARY tasks)

file(GLOB_RECURSE SOURCES
    ${EMERGN_SRC}/*.cpp
    #"${PROJECT_SOURCE_DIR}/src/main/main.cpp"
)

add_executable( ${BINARY} ${SOURCES} )
