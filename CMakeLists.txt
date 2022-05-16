cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDMP-Shared)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.c)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        external/enet/include
        external/json/include
        external/fmt/include)

add_subdirectory(external/enet)
add_subdirectory(external/json)
add_subdirectory(external/fmt)

target_link_libraries(${PROJECT_NAME}
	  nlohmann_json
        enet
        fmt)

