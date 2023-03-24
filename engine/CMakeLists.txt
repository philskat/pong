project(GameEngine VERSION 0.0.1)

add_library(${PROJECT_NAME} STATIC include/gameengine.hpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_gl_LIBRARY} libglew_static glfw glm)

add_subdirectory(include)
add_subdirectory(src)

