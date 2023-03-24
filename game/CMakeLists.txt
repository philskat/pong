project(Pong VERSION 0.0.1)

set(GAME_SOURCES src/main.cpp)

if(PONGGAME_DEBUG)
	list(APPEND GAME_SOURCES 
		${imgui_SOURCE_DIR}/imgui.cpp
		${imgui_SOURCE_DIR}/imgui.h
		${imgui_SOURCE_DIR}/imgui_demo.cpp
		${imgui_SOURCE_DIR}/imgui_draw.cpp
		${imgui_SOURCE_DIR}/imgui_internal.h
		${imgui_SOURCE_DIR}/imgui_tables.cpp
		${imgui_SOURCE_DIR}/imgui_widgets.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h
		${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h
	)
endif()

add_executable(${PROJECT_NAME} ${GAME_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE GameEngine)
if(PONGGAME_DEBUG)
	target_include_directories(${PROJECT_NAME} PRIVATE ${imgui_SOURCE_DIR})
	target_compile_definitions(${PROJECT_NAME} PRIVATE PONGGAME_DEBUG)
endif()

add_subdirectory(src)

