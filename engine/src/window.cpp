#include "window.hpp"
#include "resourcemanager.hpp"

Window::Window(GLFWwindow* window)
{
  m_Window = window;

  m_Width = 0;
  m_Height = 0;
  m_Title = nullptr;

  glfwGetWindowSize(m_Window, &m_Width, &m_Height);
}

Window::~Window()
{
  if (m_Window)
  {
    glfwDestroyWindow(m_Window);
  }
}

std::unique_ptr<Window> Window::createWindow(unsigned int width, unsigned int height, const char* title)
{
  GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

  if (!window)
  {
    return std::unique_ptr<Window>(nullptr);
  }

  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK)
  {
    glfwDestroyWindow(window);
    return std::unique_ptr<Window>(nullptr);
  }

  return std::unique_ptr<Window>(new Window(window));
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

GLFWwindow* Window::getWindow() const
{
  return m_Window;
}

void Window::updateWindowSize()
{
  glfwSetWindowSize(m_Window, m_Width, m_Height);
}