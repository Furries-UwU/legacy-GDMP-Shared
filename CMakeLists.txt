cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDMP-Shared)

###########################################################################

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES fmt/8.1.1 protobuf/3.20.0 enet/1.3.17
        GENERATORS cmake_find_package cmake_paths
        OPTIONS protobuf:shared=False
        fmt:shared=False
        enet:shared=False)

conan_cmake_autodetect(settings)

set(CONAN_SETTINGS ${settings} ${CONAN_SETTINGS})

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${CONAN_SETTINGS})

include(${CMAKE_CURRENT_BINARY_DIR}/conan_paths.cmake)

###########################################################################

find_package(enet REQUIRED)
find_package(fmt REQUIRED)
find_package(protobuf REQUIRED)

file(GLOB_RECURSE PROTO_SOURCE_FILES CONFIGURE_DEPENDS src/*.proto)
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.c)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCE_FILES})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${PROTO_SRCS} ${PROTO_HDRS})

cmake_path(GET PROTO_HDRS PARENT_PATH PROTO_PARENT_HDRS)

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        ${PROTO_PARENT_HDRS}
        ${CMAKE_CURRENT_BINARY_DIR}
        )

target_link_libraries(${PROJECT_NAME} enet::enet fmt::fmt protobuf::libprotobuf)