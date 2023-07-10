cmake_minimum_required(VERSION 3.25)
project(BinaryTreeEvaluator)

set(CMAKE_CXX_STANDARD 23)

add_executable(BinaryTreeEvaluator
        src/main.cpp
        src/Token.hpp
        src/Evaluator.hpp
        src/Tokenizer.hpp
        src/Num.hpp
        src/Bracket.hpp
        src/Operator.hpp
        src/Visualizer.hpp)
