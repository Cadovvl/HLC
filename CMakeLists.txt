cmake_minimum_required(VERSION 3.5.1)
project(HighLoadCup)

ADD_DEFINITIONS(
        -std=c++14
        -Wall
        -O2
)

set(SOURCE_FILES main.cpp MainListener.cpp MainListener.h src/EntityRequestHandlerFactory.cpp src/EntityRequestHandlerFactory.h src/MessageGetter.cpp src/MessageGetter.h src/MessagesQueue.cpp src/MessagesQueue.h src/MessageAdder.cpp src/MessageAdder.h)

add_subdirectory(contrib/json)
include_directories(contrib/json/src)


add_executable(HighLoadCup ${SOURCE_FILES})


find_library(POCO_FOUNDATION PocoFoundation)
find_library(POCO_UTIL PocoUtil)
find_library(POCO_NET PocoNet)
target_link_libraries(HighLoadCup ${POCO_FOUNDATION} ${POCO_UTIL} ${POCO_NET})
