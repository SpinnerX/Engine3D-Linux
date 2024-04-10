cmake_minimum_required (VERSION 3.15)

set(PROJECT_NAME Editor)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)
project(${PROJECT_NAME})

include_directories(
    ../Engine3DLinux/
    ../Engine3DLinux/Core
)


add_executable(
	${PROJECT_NAME}
	Application.cpp
    EditorLayer.cpp
	Panels/SceneHeirarchyPanel.cpp
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    Engine3D-Linux
    glfw
    ${Vulkan_LIBRARIES}
    fmt
    spdlog
    glm
    tobanteGaming::Box2D
    yaml-cpp
    imgui
    ImGuizmo
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
