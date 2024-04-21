cmake_minimum_required(VERSION 3.29.2)


set(CMAKE_TOOLCHAIN_FILE "C:/Users/Luca/Desktop/Package Managers/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(PROJECT_NAME SimpleChat)

project(${PROJECT_NAME})

add_executable(SimpleChat WIN32 main.cpp)
add_executable(socketServer socketServer.cpp)
# wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()
target_link_libraries(SimpleChat ${wxWidgets_LIBRARIES})
#easysocket
add_subdirectory(easysocket)
target_link_libraries(socketServer easy-socket)
target_link_libraries(SimpleChat easy-socket)
#sockpp
# find_package(sockpp REQUIRED)
# target_link_libraries(SimpleChat Sockpp::sockpp-static)
# target_link_libraries(socketServer Sockpp::sockpp-static)