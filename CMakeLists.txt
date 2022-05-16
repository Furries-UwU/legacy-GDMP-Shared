cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDMP-Shared)

set(VCPKG_TARGET_TRIPLET x86-windows-static)
set(OPENSSL_USE_STATIC_LIBS TRUE)
set(Protobuf_USE_STATIC_LIBS ON)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.c)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
	include
	external/GameNetworkingSockets/include
	external/fmt/include
)

find_package(OpenSSL REQUIRED)
find_package(protobuf CONFIG REQUIRED)

add_subdirectory(external/GameNetworkingSockets)
add_subdirectory(external/fmt)

target_link_libraries(${PROJECT_NAME}
		OpenSSL::Crypto
		protobuf::libprotobuf
		GameNetworkingSockets::static
		fmt)