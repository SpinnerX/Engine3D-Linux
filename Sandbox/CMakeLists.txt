cmake_minimum_required (VERSION 3.15)

set(PROJECT_NAME Sandbox)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)
project(${PROJECT_NAME})

find_package(Engine3D REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(imgui REQUIRED)
find_package(Vulkan REQUIRED)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)


# Create the executable
add_executable(${PROJECT_NAME} main.cpp)

# Link the static library from subproject1 using its alias sub::lib1
# Link the header only library from subproject2 using its alias sub::lib2
# This will cause the include directories for that target to be added to this project

# Log::Log1 is the alias we made when we created an alias in the Logger CMakeLists.txt file
target_link_libraries(
    ${PROJECT_NAME}
	Engine3D::Engine3D
	glfw
	${OPENGL_gl_LIBRARY}
	GLEW::GLEW
	${GLUT_LIBRARIES}
	imgui::imgui
	Vulkan::Vulkan
	glm::glm
	fmt::fmt
	spdlog::spdlog
	glad::glad
)
