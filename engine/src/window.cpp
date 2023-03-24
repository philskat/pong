#include "window.hpp"
#include "resourcemanager.hpp"

Window::Window(unsigned int width, unsigned int height, const char* title)
  : m_Width(width), m_Height(height), m_Title(title)
{
  if (!glfwInit())
  {
    throw "Could not init GLFW";
  }

  m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
  if (!m_Window)
  {
    glfwTerminate();
    throw "Could not create window";
  }

  glfwMakeContextCurrent(m_Window);

  if (glewInit() != GLEW_OK)
  {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
    throw "Could not init GLEW";
  }
}

Window::~Window()
{
  if (m_Window)
  {
    glfwDestroyWindow(m_Window);

    ResourceManager::getInstance().cleanUp();

    glfwTerminate();
  }
}

bool Window::isOpen() const
{
  return !glfwWindowShouldClose(m_Window);
}

void Window::update()
{
  glfwSwapBuffers(m_Window);
  glfwPollEvents();
}

void Window::setWidth(unsigned int width)
{
  m_Width = width;

  updateWindowSize();
}

unsigned int Window::getWidth() const
{
  return m_Width;
}

void Window::setHeight(unsigned int height)
{
  m_Height = height;

  updateWindowSize();
}

unsigned int Window::getHeight() const
{
  return m_Height;
}

void Window::setTitle(const char* title)
{
  m_Title = title;

  glfwSetWindowTitle(m_Window, m_Title);
}

const char* Window::getTitle() const
{
  return m_Title;
}

void Window::updateWindowSize()
{
  glfwSetWindowSize(m_Window, m_Width, m_Height);
}