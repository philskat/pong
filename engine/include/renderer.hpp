#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "window.hpp"
#include "camera.hpp"

#include <vector>

class Renderer
{
protected:
  Camera& m_Camera;
  std::vector<std::weak_ptr<Entity>> m_Entities;

public:
  Renderer(Camera& camera);
  Renderer(const Renderer&) = delete;

  virtual void render() = 0;

  void addEntity(std::weak_ptr<Entity> entity);
};

#endif
