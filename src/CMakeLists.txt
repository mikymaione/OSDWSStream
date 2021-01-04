cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(asio-cmake
        GIT_REPOSITORY https://github.com/kingsamchen/asio-cmake.git
        GIT_TAG origin/master)

# Specify asio version
set(ASIO_CMAKE_ASIO_TAG asio-1-12-1)
FetchContent_MakeAvailable(asio-cmake)

find_package(OpenSSL REQUIRED)
find_package(ZLIB)

include_directories(${ZLIB_INCLUDE_DIRS})

add_executable(src
        main.cpp
        hashing.h hashing.cpp
        server_http.hpp
        server_http_impl.hpp
        server_ws.hpp
        server_ws_impl.hpp
        server_wss.hpp
        path_to_regex.hpp path_to_regex.cpp
        base64.hpp
        crypto.hpp
        osdcore.h osdcore.cpp
        osdcomm.h
        strformat.h strformat.cpp
        vecstream.h vecstream.cpp
        corestr.h corestr.cpp
        md5.h md5.cpp)

target_link_libraries(src
        PRIVATE asio
        OpenSSL::SSL
        ${ZLIB_LIBRARIES})
