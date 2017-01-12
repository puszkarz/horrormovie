cmake_minimum_required(VERSION 3.5)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

set(SOURCE_FILES
    citizen.h
    helper.h
    horror_example.cc
    monster.h
    smalltown.h smalltown.cc monster.cc citizen.cc helper.cc)

set(TEST1
        citizen.h
        helper.h
        test1.cc
        monster.h
        smalltown.h smalltown.cc monster.cc citizen.cc helper.cc)


add_executable(src ${SOURCE_FILES})
add_executable(test1 ${TEST1})