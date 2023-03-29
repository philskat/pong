#include "renderer.hpp"

Renderer::Renderer(Camera& camera)
  : m_Camera(camera)
{
}

void Renderer::addEntity(Entity* entity)
{
  m_Entities.push_back(entity);
}