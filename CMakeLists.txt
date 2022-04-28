cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(SFML-Starter VERSION 0.1.0)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
        CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

configure_file(${CMAKE_SOURCE_DIR}/config.h.in ${CMAKE_SOURCE_DIR}/config.h)

add_executable(SFML-Starter 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/game.cpp
)
target_include_directories(SFML-Starter PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/sfml)

set(BUILD_SHARED_LIBS FALSE)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/libs/imgui)
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_IMGUI_DEMO ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/imgui-sfml)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/fmt)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/effolkronium-random)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/entt)

target_include_directories(SFML-Starter PRIVATE ${CMAKE_SOURCE_DIR}/libs/imgui-entt-entity-editor)

target_link_libraries(SFML-Starter PRIVATE 
    sfml-graphics sfml-audio 
    ImGui-SFML::ImGui-SFML 
    effolkronium_random
    EnTT::EnTT
    fmt::fmt 
)