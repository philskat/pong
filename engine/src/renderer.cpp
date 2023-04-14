#include "renderer.hpp"

Renderer::Renderer(Camera& camera)
  : m_Camera(camera)
{
}

void Renderer::addEntity(std::weak_ptr<Entity> entity)
{
  m_Entities.push_back(entity);
}