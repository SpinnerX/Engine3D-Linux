include_directories(
	Engine3DLinux
	../
)

set(
	INCLUDE_DIR
	Engine3DLinux
)

set(
  all_src

  ${INCLUDE_DIR}/Core/EntryPoint.cpp
  ${INCLUDE_DIR}/Core/Application.cpp
  ${INCLUDE_DIR}/Core/EngineLogger.cpp
  ${INCLUDE_DIR}/Events/InputPoll.cpp
  ${INCLUDE_DIR}/interfaces/Layer.cpp
  ${INCLUDE_DIR}/Core/LayerStack.cpp

  ${INCLUDE_DIR}/ImGui/ImGuiLayer.cpp

  ${INCLUDE_DIR}/OpenGL/OpenGLInputPoll.cpp
  ${INCLUDE_DIR}/OpenGL/OpenGLWindow.cpp

  ${INCLUDE_DIR}/OpenGL/OpenGLContext.cpp
)

set(
  all_headers
  ../${INCLUDE_DIR}/Core/Application.h
  ../${INCLUDE_DIR}/Core/core.h
  ../${INCLUDE_DIR}/Core/EngineLogger.h
  ../${INCLUDE_DIR}/Core/EntryPoint.h

  ../${INCLUDE_DIR}/Events/InputPoll.h
  ../${INCLUDE_DIR}/interfaces/Window.h
  ../${INCLUDE_DIR}/interfaces/Layer.h
  ../${INCLUDE_DIR}/Core/LayerStack.h
  ../${INCLUDE_DIR}/Entt/entt.h

  ../${INCLUDE_DIR}/Events/ApplicationEvent.h
  ../${INCLUDE_DIR}/Events/Event.h
  ../${INCLUDE_DIR}/Events/KeyEvent.h
  ../${INCLUDE_DIR}/Events/MouseEvent.h
  ../${INCLUDE_DIR}/OpenGL/OpenGLInputPoll.h
  ../${INCLUDE_DIR}/OpenGL/OpenGLContext.h

  ../${INCLUDE_DIR}/image/stb_image.h
)

# if(UNIX AND NOT APPLE)
find_package(glfw3 REQUIRED)
# endif(UNIX AND NOT APPLE)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
# find_package(GLUT REQUIRED)

find_package(imgui REQUIRED)
find_package(ImGuizmo REQUIRED)
# find_package(Vulkan REQUIRED)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)

find_package(box2d REQUIRED)
find_package(yaml-cpp REQUIRED)

add_library( ${PROJECT_NAME} ${all_src} ${all_headers} )

# NOTE: Using {OPENGL_gl_LIBRARY}, if compiling on Apple.

if(UNIX AND NOT APPLE)
	target_link_libraries(
		${PROJECT_NAME}
		glfw
		# ${OPENGL_gl_LIBRARY}
		OpenGL::GL
		# Vulkan::Vulkan
		imgui::imgui
		ImGuizmo::ImGuizmo
		fmt::fmt
		glm::glm
		spdlog::spdlog
		glad::glad
		box2d::box2d
		yaml-cpp
	)
endif(UNIX AND NOT APPLE)

if(APPLE)
target_link_libraries(
	${PROJECT_NAME}
	glfw
	imgui::imgui
	ImGuizmo::ImGuizmo
	fmt::fmt
	glm::glm
	spdlog::spdlog
	glad::glad
	GLEW::GLEW
)
endif(APPLE)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../${INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)


set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

if(MSVC)
	set_target_properties(${PROJECT_NAME} PROPERTIES
    COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	COMPILE_PDB_NAME ${PROJECT_NAME}
  )

  install(
	  FILES "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/${PROJECT_NAME}.pdb"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    OPTIONAL
  )
endif()

if (BUILD_SHARED_LIBS)
	target_compile_definitions(${PROJECT_NAME}
    PUBLIC
	${PROJECT_NAME}_SHARED
  )
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "src" FILES ${all_src})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../${INCLUDE_DIR}" PREFIX "include" FILES ${all_headers})

install(
	TARGETS ${PROJECT_NAME}
	EXPORT ${PROJECT_NAME}Config
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
	EXPORT ${PROJECT_NAME}Config
	NAMESPACE Engine3D-Linux::
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  COMPATIBILITY SameMajorVersion
)

install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)
