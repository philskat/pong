#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "window.hpp"
#include "camera.hpp"

#include <vector>

class Renderer
{
protected:
  Camera& m_Camera;
  std::vector<Entity*> m_Entities;

public:
  Renderer(Camera& camera);
  Renderer(const Renderer&) = delete;
  Renderer operator=(const Renderer&) = delete;

  virtual void render() = 0;

  void addEntity(Entity* entity);
};

#endif