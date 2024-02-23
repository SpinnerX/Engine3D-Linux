cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Engine3D)
set(CMAKE_CXX_STANDARD 20)

project(${PROJECT_NAME} VERSION 1.0)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

option(ENGINE_BUILD_UNIT_TESTS "Build the GameEngine unit tests" ON)
option(ENGINE_BUILD_TESTBED "Build the GameEngine testbed" ON)
option(ENGINE_BUILD_DOCS "Build the GameEngine documentation" OFF)
option(ENGINE_USER_SETTINGS "Override GameEngine settings with GameEngineUserSettings.h" OFF)

option(BUILD_SHARED_LIBS "Build Box2D as a shared library" OFF)

include(GNUInstallDirs)
include_directories(${PROJECT_SOURCE_DIR}/include/Engine3D)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message("Message = ${CMAKE_INSTALL_PREFIX}")

# add_subdirectory(Sandbox)
add_subdirectory(src)


# target_precompile_headers(${PROJECT_NAME} PUBLIC
# 	"$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_INSTALL_PREFIX}/include/GameEngine/GameEnginePrecompiledHeader.h>"
# )
target_precompile_headers(${PROJECT_NAME} PUBLIC
	"$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/include/Engine3D/Engine3DPrecompiledHeader.h>"
)

install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/Engine3D"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Installing to /usr/local/public/GameEngine/
# install(
#   DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assets"
#   DESTINATION "${CMAKE_INSTALL_LIBDIR}/GameEngine"
# )
