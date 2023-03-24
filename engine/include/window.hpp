#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <gl/glew.h>
#include <GLFW/glfw3.h>

class Window
{
private:
  GLFWwindow* m_Window;

  unsigned int m_Width, m_Height;

  const char* m_Title;

public:
  Window(unsigned int width, unsigned int height, const char* title);
  virtual ~Window();
  Window(const Window&) = delete;
  Window operator=(const Window&) = delete;

  bool isOpen() const;

  void update();

  void setWidth(unsigned int width);
  unsigned int getWidth() const;

  void setHeight(unsigned int height);
  unsigned int getHeight() const;

  void setTitle(const char* title);
  const char* getTitle() const;

private:
  void updateWindowSize();
};

#endif