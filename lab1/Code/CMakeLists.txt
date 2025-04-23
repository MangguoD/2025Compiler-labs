cmake_minimum_required(VERSION 3.5)
project(CminusCompiler)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

BISON_TARGET(Parser syntax.y ${CMAKE_CURRENT_BINARY_DIR}/syntax.tab.c)
FLEX_TARGET(Lexer lexical.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(cc main.c ${BISON_Parser_OUTPUTS} ${FLEX_Lexer_OUTPUTS}
        Node.h)
