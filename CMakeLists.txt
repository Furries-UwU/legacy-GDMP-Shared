cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDMP-Shared)

set(Protobuf_USE_STATIC_LIBS ON)
find_package(Protobuf REQUIRED)

file(GLOB_RECURSE PROTO_SOURCE_FILES CONFIGURE_DEPENDS src/*.proto)
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.c)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCE_FILES})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${PROTO_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        ${CMAKE_CURRENT_BINARY_DIR}
###########################################################################
        external/enet/include
        external/fmt/include
###########################################################################
        ${Protobuf_INCLUDE_DIRS}
        ${PROTO_HDRS}
        )

add_subdirectory(external/enet)
add_subdirectory(external/fmt)

target_link_libraries(${PROJECT_NAME} enet fmt ${Protobuf_LIBRARIES})