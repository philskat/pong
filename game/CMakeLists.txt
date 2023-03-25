project(Pong VERSION 0.0.1)

set(GAME_SOURCES
	src/main.cpp
	src/staticrenderer.cpp
	src/staticrenderer.hpp
	src/staticshader.cpp
	src/staticshader.hpp
)

add_executable(${PROJECT_NAME} ${GAME_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE GameEngine)
if(PONGGAME_DEBUG)
	target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
	target_compile_definitions(${PROJECT_NAME} PRIVATE PONGGAME_DEBUG)
endif()

