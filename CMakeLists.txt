cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDMP-Shared)

###########################################################################

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES fmt/8.1.1 protobuf/3.20.0 openssl/3.0.3
        GENERATORS cmake_find_package)
        # OPTIONS protobuf:shared=False
        # fmt:shared=False
        # openssl:shared=False)

conan_cmake_autodetect(settings)

set(CONAN_SETTINGS ${settings} ${CONAN_SETTINGS})

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${CONAN_SETTINGS})

###########################################################################

find_package(fmt REQUIRED)
find_package(protobuf REQUIRED)

set(Protobuf_IMPORT_DIRS ${Protobuf_IMPORT_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/external/GameNetworkingSockets/src/common  ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${protobuf_INCLUDE_DIRS})

# set(Protobuf_USE_STATIC_LIBS ON)
# set(OPENSSL_USE_STATIC_LIBS ON)
# set(BUILD_SHARED_LIB OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/GameNetworkingSockets)

file(GLOB_RECURSE PROTO_SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.proto)
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCE_FILES})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${PROTO_SRCS} ${PROTO_HDRS})

cmake_path(GET PROTO_HDRS PARENT_PATH PROTO_PARENT_HDRS)

target_include_directories(${PROJECT_NAME} PUBLIC
                include 
                ${PROTO_PARENT_HDRS}
                ${protobuf_INCLUDE_DIRS}
                )

target_link_libraries(${PROJECT_NAME} GameNetworkingSockets::static fmt::fmt ${Protobuf_LIBRARIES})