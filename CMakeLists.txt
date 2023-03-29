cmake_minimum_required(VERSION 3.10)

Project(PongGame)
set(CXX_STANDARD 20)

option(PONGGAME_DEBUG "Enable Debug features of the game" OFF)

# Dependencies
include(FetchContent)

## OpenGL
find_package(OpenGL REQUIRED)

## GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW build Examples" FORCE)
set(GFLW_BUILD_TESTS OFF CACHE BOOL "GLFW build tests" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW build docs" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "GLFW install" FORCE)

FetchContent_Declare(
	glfw
	GIT_REPOSITORY		https://github.com/glfw/glfw.git
	GIT_TAG				3.3.8
	GIT_SHALLOW			ON
	FIND_PACKAGE_ARGS	NAMES glfw glfw3
)

## GLEW
set(glew-cmake_BUILD_SHARED OFF CACHE BOOL "GLEW build shared" FORCE)

FetchContent_Declare(
	glew
	GIT_REPOSITORY		https://github.com/Perlmint/glew-cmake.git
	GIT_TAG				glew-cmake-2.2.0
	GIT_SHALLOW			ON
	FIND_PACKAGE_ARGS
)

## GLM
FetchContent_Declare(
	glm
	GIT_REPOSITORY		https://github.com/g-truc/glm
	GIT_TAG				0.9.9.8
	GIT_SHALLOW			ON
	FIND_PACKAGE_ARGS
)

## ImGUI
if(PONGGAME_DEBUG)
	FetchContent_Declare(
		imgui
		GIT_REPOSITORY		https://github.com/ocornut/imgui
		GIT_TAG				v1.89.4
		GIT_SHALLOW			ON
	)
	
	FetchContent_MakeAvailable(imgui)

	add_custom_command(
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/imgui/include/imconfig.h
		       ${CMAKE_CURRENT_BINARY_DIR}/imgui/include/imgui.h
		       ${CMAKE_CURRENT_BINARY_DIR}/imgui/include/imgui_internal.h
			   ${CMAKE_CURRENT_BINARY_DIR}/imgui/include/backends/imgui_impl_glfw.h
			   ${CMAKE_CURRENT_BINARY_DIR}/imgui/include/backends/imgui_impl_opengl3.h
		COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/imgui/include/backends
		COMMAND ${CMAKE_COMMAND} -E copy ${imgui_SOURCE_DIR}/imconfig.h ${CMAKE_CURRENT_BINARY_DIR}/imgui/include
		COMMAND ${CMAKE_COMMAND} -E copy ${imgui_SOURCE_DIR}/imgui.h ${CMAKE_CURRENT_BINARY_DIR}/imgui/include
		COMMAND ${CMAKE_COMMAND} -E copy ${imgui_SOURCE_DIR}/imgui_internal.h ${CMAKE_CURRENT_BINARY_DIR}/imgui/include
		COMMAND ${CMAKE_COMMAND} -E copy ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h ${CMAKE_CURRENT_BINARY_DIR}/imgui/include/backends
		COMMAND ${CMAKE_COMMAND} -E copy ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h ${CMAKE_CURRENT_BINARY_DIR}/imgui/include/backends
		DEPENDS ${imgui_SOURCE_DIR}/imconfig.h
		        ${imgui_SOURCE_DIR}/imgui.h
		        ${imgui_SOURCE_DIR}/imgui_internal.h
				${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h
				${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h
	)

	add_library(imgui STATIC 
		${imgui_SOURCE_DIR}/imgui.cpp
		${imgui_SOURCE_DIR}/imgui_demo.cpp
		${imgui_SOURCE_DIR}/imgui_draw.cpp
		${imgui_SOURCE_DIR}/imgui_tables.cpp
		${imgui_SOURCE_DIR}/imgui_widgets.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
		${CMAKE_CURRENT_BINARY_DIR}/imgui/include/imconfig.h
		${CMAKE_CURRENT_BINARY_DIR}/imgui/include/imgui.h
		${CMAKE_CURRENT_BINARY_DIR}/imgui/include/imgui_internal.h
		${CMAKE_CURRENT_BINARY_DIR}/imgui/include/backends/imgui_impl_glfw.h
		${CMAKE_CURRENT_BINARY_DIR}/imgui/include/backends/imgui_impl_opengl3.h
	)
	target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/imgui/include)
	target_link_libraries(imgui PUBLIC glfw)
endif()

FetchContent_MakeAvailable(glfw glew glm)

# Engine
add_subdirectory(engine)

# Game
add_subdirectory(game)

