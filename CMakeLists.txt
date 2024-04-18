cmake_minimum_required(VERSION 3.29.2)


set(CMAKE_TOOLCHAIN_FILE "C:/Users/Luca/Desktop/Package Managers/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(PROJECT_NAME Downloader)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} WIN32 main.cpp)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})