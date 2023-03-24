cmake_minimum_required(VERSION 3.10)

Project(PongGame)
set(CXX_STANDARD 20)

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
	FIND_PACKAGE_ARGS	NAMES glfw glfw3
)

## GLEW
set(glew-cmake_BUILD_SHARED OFF CACHE BOOL "GLEW build shared" FORCE)

FetchContent_Declare(
	glew
	GIT_REPOSITORY		https://github.com/Perlmint/glew-cmake.git
	GIT_TAG				glew-cmake-2.2.0
	FIND_PACKAGE_ARGS
)

## GLM
FetchContent_Declare(
	glm
	GIT_REPOSITORY		https://github.com/g-truc/glm
	GIT_TAG				0.9.9.8
	FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(glfw glew glm)

# Engine
add_subdirectory(engine)

# Game
add_subdirectory(game)

