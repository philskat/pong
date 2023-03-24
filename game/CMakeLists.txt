project(Pong VERSION 0.0.1)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE GameEngine)

add_subdirectory(src)

