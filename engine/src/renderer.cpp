#include "renderer.hpp"

Renderer::Renderer(Window& window, Camera& camera)
  : m_Window(window), m_Camera(camera)
{
}

void Renderer::addEntity(Entity* entity)
{
  m_Entities.push_back(entity);
}

void Renderer::swapBuffers()
{
  m_Window.update();
}