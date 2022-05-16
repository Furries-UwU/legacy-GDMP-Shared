cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDMP-Shared)

set(VCPKG_TARGET_TRIPLET x86-windows-static)

execute_process(COMMAND ${CMAKE_COMMAND}
		-G "${CMAKE_GENERATOR}"
		-Dprotobuf_BUILD_TESTS=OFF -Dprotobuf_MODULE_COMPATIBLE=ON -Dprotobuf_BUILD_SHARED_LIBS=OFF
		-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/protobuf
		-S ${CMAKE_CURRENT_SOURCE_DIR}/external/protobuf/cmake
		-B ${CMAKE_BINARY_DIR}/build_protobuf
		-A Win32
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external/protobuf)
execute_process(COMMAND ${CMAKE_COMMAND}
		--build "${CMAKE_BINARY_DIR}/build_protobuf"
		--config ${CMAKE_BUILD_TYPE}
		--target install)
set(Protobuf_USE_STATIC_LIBS ON)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/protobuf/bin")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/protobuf/cmake")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/protobuf/include")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/protobuf/lib")

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