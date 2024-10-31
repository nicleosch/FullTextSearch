cmake_minimum_required(VERSION 3.29)
project(fts)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled
        main.cpp
        src/Document.cpp
        src/algorithms/DummySearchEngine/DummySearchEngine.cpp
        src/algorithms/InvertedIndexEngine/InvertedIndexEngine.cpp
        src/algorithms/TrigramIndexEngine/TrigramIndexEngine.cpp
        src/algorithms/VectorSpaceModelEngine/VectorSpaceModelEngine.cpp
)
