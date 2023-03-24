#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "window.hpp"
#include "camera.hpp"

#include <vector>

class Renderer
{
protected:
  Window& m_Window;
  Camera& m_Camera;
  std::vector<Entity*> m_Entities;

public:
  Renderer(Window& window, Camera& camera);
  Renderer(const Renderer&) = delete;
  Renderer operator=(const Renderer&) = delete;

  virtual void render() = 0;

  void addEntity(Entity* entity);

protected:
  void swapBuffers();
};

#endif