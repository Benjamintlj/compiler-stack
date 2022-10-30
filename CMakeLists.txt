cmake_minimum_required(VERSION 3.23)
project(nom_nom)

set(CMAKE_CXX_STANDARD 14)

add_executable(nom_nom
        main.cpp
        source/InputParser.cpp
        source/Tokenizer.cpp
        source/SymbolTable.cpp
        source/ParseTree.cpp
        source/ThreeAddressLogicGenerator.cpp)
