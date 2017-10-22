cmake_minimum_required(VERSION 3.5.1)
project(HighLoadCup)

ADD_DEFINITIONS(
        -std=c++14
        -Wall
        -O2
)

set(SOURCE_FILES main.cpp MainListener.cpp MainListener.h EntityRequestHandlerFactory.cpp EntityRequestHandlerFactory.h EntityRequestHandler.cpp EntityRequestHandler.h)

add_subdirectory(contrib/json)
include_directories(contrib/json/src)


add_executable(HighLoadCup ${SOURCE_FILES})


find_library(POCO_FOUNDATION PocoFoundation)
find_library(POCO_UTIL PocoUtil)
find_library(POCO_NET PocoNet)
target_link_libraries(HighLoadCup ${POCO_FOUNDATION} ${POCO_UTIL} ${POCO_NET})
