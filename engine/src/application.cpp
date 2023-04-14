#include "application.hpp"
#include "resourcemanager.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Application::Application()
{
  if (!glfwInit())
  {
    throw "Could not init GLFW";
  }
}

Application::~Application()
{
  ResourceManager::getInstance().cleanUp();

  glfwTerminate();
}

void Application::update()
{
  onUpdate();

  onRender();
}
