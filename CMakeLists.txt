cmake_minimum_required(VERSION 4.3)
project(NMouseJoy)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(libs/SDL EXCLUDE_FROM_ALL)

set(IMGUI
        libs/ImGui/imgui.cpp
        libs/ImGui/imgui.h
        libs/ImGui/backends/imgui_impl_sdl3.cpp
        libs/ImGui/backends/imgui_impl_sdl3.h
        libs/ImGui/backends/imgui_impl_sdlrenderer3.cpp
        libs/ImGui/backends/imgui_impl_sdlrenderer3.h
) 

add_executable(NMouseJoy NMJ.cpp
        NMJLog.cpp
        NMJLog.h)
target_include_directories(NMouseJoy PRIVATE libs/ImGui)
target_link_libraries(NMouseJoy PRIVATE SDL3::SDL3)