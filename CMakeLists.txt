cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDMP-Shared)

set(VCPKG_TARGET_TRIPLET x86-windows-static)

set(Protobuf_USE_STATIC_LIBS ON)

execute_process(COMMAND ${CMAKE_COMMAND}
		-G "${CMAKE_GENERATOR}"
		-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
		-Dprotobuf_BUILD_TESTS=OFF -Dprotobuf_MODULE_COMPATIBLE=ON
		-DCMAKE_INSTALL_PREFIX=${PROJECT_SOURCE_DIR}/build/protobuf
		-S ${PROJECT_SOURCE_DIR}/external/protobuf/cmake
		-B ${PROJECT_SOURCE_DIR}/build/protobuf
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/external/protobuf)
execute_process(COMMAND ${CMAKE_COMMAND}
		--build "${PROJECT_SOURCE_DIR}/build/protobuf"
		--config ${CMAKE_BUILD_TYPE}
		--target install)

set(Protobuf_LIBRARIES ${PROJECT_SOURCE_DIR}/build/protobuf/lib)
set(Protobuf_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/build/protobuf/include)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.c)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
	include
	external/GameNetworkingSockets/include
	external/fmt/include
)

add_subdirectory(external/GameNetworkingSockets)
add_subdirectory(external/fmt)

target_link_libraries(${PROJECT_NAME}
		OpenSSL::Crypto
		libprotobuf
		GameNetworkingSockets::static
		fmt)