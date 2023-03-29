project(GameEngine VERSION 0.0.1)

set(GAMEENGINE_HEADER_FILES
  include/application.hpp
	include/camera.hpp
	include/entity.hpp
	include/gameengine.hpp
	include/model.hpp
	include/renderer.hpp
	include/resourcemanager.hpp
	include/shaderprogram.hpp
	include/window.hpp
)

set(GAMEENGINE_SOURCE_FILES
  src/application.cpp
	src/camera.cpp
	src/entity.cpp
	src/model.cpp
	src/renderer.cpp
	src/resourcemanager.cpp
	src/shaderprogram.cpp
	src/window.cpp
)

add_library(${PROJECT_NAME} STATIC ${GAMEENGINE_HEADER_FILES} ${GAMEENGINE_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_gl_LIBRARY} libglew_static glfw glm)

if(PONGGAME_BUILD_DOCS)
	add_custom_target(${PROJECT_NAME}_docs
		COMMAND doxygen
		DEPENDS ${GAMEENGINE_HEADER_FILES} 
		WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
	)
endif()
