cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDMP-Shared)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES fmt/8.1.1 enet/1.3.17
        GENERATORS cmake_find_package cmake_paths
        fmt:shared=False
        enet:shared=False)

conan_cmake_autodetect(settings)

set(CONAN_SETTINGS ${settings} ${CONAN_SETTINGS})

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${CONAN_SETTINGS})

include(${CMAKE_CURRENT_BINARY_DIR}/conan_paths.cmake)

find_package(enet REQUIRED)
find_package(fmt REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        ${CMAKE_CURRENT_BINARY_DIR}
        )

target_link_libraries(${PROJECT_NAME} enet::enet fmt::fmt)