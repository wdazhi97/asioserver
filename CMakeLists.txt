cmake_minimum_required(VERSION 3.21)
project (server)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/include)

link_directories(usr/local/lib)

file(GLOB_RECURSE net_src net/*.cpp)

add_subdirectory(net)

add_subdirectory(service)

add_executable(test main.cpp ${net_src})

file(GLOB_RECURSE echo_src service/echo/*.cpp)

add_executable(echo ${echo_src} ${net_src})

target_link_libraries(echo boost_thread boost_system)
target_link_libraries(test boost_thread boost_system)