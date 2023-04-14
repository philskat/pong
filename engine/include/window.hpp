#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <memory>

class Window
{
private:
  GLFWwindow* m_Window;

  int m_Width, m_Height;

  const char* m_Title;

public:
  virtual ~Window();
  Window(const Window&) = delete;
  Window operator=(const Window&) = delete;

  static std::unique_ptr<Window> createWindow(unsigned int width, unsigned int height, const char* title);

  bool isOpen() const;

  void update();

  void setWidth(unsigned int width);
  unsigned int getWidth() const;

  void setHeight(unsigned int height);
  unsigned int getHeight() const;

  void setTitle(const char* title);
  const char* getTitle() const;

  GLFWwindow* getWindow() const;

private:
  Window(GLFWwindow* window);

  void updateWindowSize();
};

#endif