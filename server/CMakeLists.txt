cmake_minimum_required(VERSION 3.5)
project(server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)

set(SOURCE_FILES server.cpp)
#add_executable(server server.cpp)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost 1.83.0 COMPONENTS ALL PATHS /usr/local/Cellar/boost/)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(Server ${SOURCE_FILES})
    target_link_libraries(Server ${Boost_LIBRARIES})
else(Boost_FOUND)
    message(FATAL_ERROR "Boost not found.")
endif(Boost_FOUND)