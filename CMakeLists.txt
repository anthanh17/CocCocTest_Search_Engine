cmake_minimum_required(VERSION 3.24.1)

# Set the project name
project (HomeTest)

#set(CMAKE_XXX_STANDARD 17)

set(SOURCES
    src/invertedIndex.cpp
    src/tokenize.cpp
    src/search.cpp
    src/main.cpp
)

add_executable(coccoc ${SOURCES})

target_compile_features(coccoc PUBLIC cxx_std_17)

target_include_directories(coccoc
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)