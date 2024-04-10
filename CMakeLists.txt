cmake_minimum_required(VERSION 3.29)

set(PROJECT_NAME Engine3D-Linux)
set(CMAKE_CXX_STANDARD 20)

# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)

project(${PROJECT_NAME} VERSION 1.0)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)

option(ENGINE_BUILD_UNIT_TESTS "Build the GameEngine unit tests" ON)
option(ENGINE_BUILD_SANDBOX "Build the GameEngine Sandbox" ON)
option(ENGINE_BUILD_DOCS "Build the GameEngine documentation" OFF)
option(ENGINE_USER_SETTINGS "Override GameEngine settings with GameEngineUserSettings.h" OFF)

option(BUILD_SHARED_LIBS "Build Box2D as a shared library" OFF)

include(GNUInstallDirs)
include_directories(
    ${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/Engin3DLinux
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message("Message = ${CMAKE_INSTALL_PREFIX}")

if(WIN32)
set(VULKAN_ROOT "C:\\VulkanSDK\\1.3.280.0")
set(VULKAN_INCLUDE "${VULKAN_ROOT}\\Include")

if (EXISTS ${VULKAN_ROOT})
include_directories(${VULKAN_INCLUDE})
list(APPEND CMAKE_PREFIX_PATH "C:\\VulkanSDK\\1.3.280.0\\Bin")
endif()

include(CMakeFindDependencyMacro)
find_package(Vulkan REQUIRED)


find_dependency(OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} external/ImGuizmo/include external/box2d/include)

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set( GLAD_GL "" )
add_subdirectory(external/glfw)

option( GLFW-CMAKE-STARTER-USE-GLFW-GLAD "Use GLAD from GLFW" ON )

if( GLFW-CMAKE-STARTER-USE-GLFW-GLAD )
    include_directories("${GLFW_SOURCE_DIR}/deps")
    set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" )
endif()

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

add_subdirectory(external/glm)
add_subdirectory(external/yaml-cpp)
# add_subdirectory(external/box2d)
# find_package(box2d REQUIRED)

add_subdirectory(external/Box2D-cmake)

# include_directories(external/fmt/include)

include(FetchContent)
add_subdirectory(external/fmt)
# FetchContent_Declare(fmt
#   GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#   GIT_TAG master
# )
# FetchContent_MakeAvailable(fmt)

add_subdirectory(external/spdlog)

add_subdirectory(external/imgui)

add_subdirectory(external/ImGuizmo)

add_subdirectory(external/glad)

endif(WIN32)

# add_subdirectory(Sandbox)
add_subdirectory(src)

if (ENGINE_BUILD_SANDBOX)
	add_subdirectory(Sandbox-Internal)
    # add_subdirectory(Editor)
    add_subdirectory(Engine3D-Editor)

	# default startup project for Visual Studio
	if (MSVC)
		set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
		set_property(TARGET Sandbox PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/Sandbox")
	endif()
endif()

file(COPY assets2 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if(WIN32)

target_link_libraries(${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    glfw
    ${Vulkan_LIBRARIES}
    fmt::fmt
    spdlog::spdlog
    glm::glm
    tobanteGaming::Box2D
    yaml-cpp::yaml-cpp
    imgui
    ImGuizmo
	glad
	# box2d::box2d
)
endif(WIN32)

# target_precompile_headers(${PROJECT_NAME} PUBLIC
# 	"$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_INSTALL_PREFIX}/include/GameEngine/GameEnginePrecompiledHeader.h>"
# )

set(PRECOMPILED_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include/Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>")
set(INSTALLED_PRECOMPILED_PATH "${CMAKE_INSTALL_PREFIX}/include/Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>")

if(EXISTS ${INSTALLED_PRECOMPILED_PATH})
	set(PATH ${INSTALLED_PRECOMPILED_PATH})
elseif(EXISTS ${PRECOMPILED_PATH})
	set(PATH ${PRECOMPILED_PATH})
endif()


# target_precompile_headers(${PROJECT_NAME} PUBLIC
# 	"$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/include/Engine3D/Engine3DPrecompiledHeader.h>"
# )

target_precompile_headers(${PROJECT_NAME} PUBLIC
	"$<$<COMPILE_LANGUAGE:CXX>:>"
)

install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Engine3DLinux"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Installing to /usr/local/public/GameEngine/
# install(
#   DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assets"
#   DESTINATION "${CMAKE_INSTALL_LIBDIR}/GameEngine"
# )
