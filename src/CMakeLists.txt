set(
	all_src
	Engine3D/Core/core.cpp
	Engine3D/Core/Application.cpp
	Engine3D/Core/EntryPoint.cpp
	Engine3D/Core/EngineLogger.cpp
	Engine3D/platforms/Linux/LinuxWindow.cpp
)

set(
	all_headers
	../include/Engine3D/Core/core.h
	../include/Engine3D/Core/Application.h
	../include/Engine3D/Core/EntryPoint.h
	../include/Engine3D/Core/EngineLogger.h
	../include/Engine3D/Events/Event.h
	../include/Engine3D/Events/KeyEvent.h
	../include/Engine3D/Events/MouseEvent.h
	../include/Engine3D/Events/ApplicationEvent.h
	../include/Engine3D/platforms/Linux/LinuxWindow.h
)

# if(UNIX AND NOT APPLE)
find_package(glfw3 REQUIRED)
# endif(UNIX AND NOT APPLE)

find_package(OpenGL REQUIRED)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)

add_library( ${PROJECT_NAME} ${all_src} ${all_headers} )

if(UNIX AND NOT APPLE)
	target_link_libraries(
		${PROJECT_NAME}
		glfw
		${OPENGL_gl_LIBRARY}
		fmt::fmt
		glm::glm
		spdlog::spdlog
		glad::glad
	)
endif(UNIX AND NOT APPLE)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
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
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../include" PREFIX "include" FILES ${all_headers})

install(
	TARGETS ${PROJECT_NAME}
	EXPORT ${PROJECT_NAME}Config
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
	EXPORT ${PROJECT_NAME}Config
	NAMESPACE Engine3D::
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
