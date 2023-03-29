project(Pong VERSION 0.0.1)

set(GAME_SOURCES
	src/main.cpp
	src/staticrenderer.cpp
	src/staticrenderer.hpp
	src/staticshader.cpp
	src/staticshader.hpp
)

# Game assets
add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/assets/staticShader.fragment
	       ${CMAKE_CURRENT_BINARY_DIR}/assets/staticShader.vertex
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/assets/staticShader.fragment
			${CMAKE_CURRENT_SOURCE_DIR}/assets/staticShader.vertex
)

add_custom_target(game_assets
	DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/assets/staticShader.fragment
	        ${CMAKE_CURRENT_BINARY_DIR}/assets/staticShader.vertex
	SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/assets/staticShader.fragment
	        ${CMAKE_CURRENT_SOURCE_DIR}/assets/staticShader.vertex
)

add_executable(${PROJECT_NAME} ${GAME_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE GameEngine)
add_dependencies(${PROJECT_NAME} game_assets)

if(PONGGAME_DEBUG)
	target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
	target_compile_definitions(${PROJECT_NAME} PRIVATE PONGGAME_DEBUG)
endif()

