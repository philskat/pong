#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "window.hpp"
#include "camera.hpp"

#include <vector>

/**
 * This class is a superclass to create your own Renderer.
 * 
 * It handels all calls related to rendering the image
 */
class Renderer
{
protected:
  Camera& m_Camera;
  std::vector<Entity*> m_Entities;

public:
  /**
   * Create Renderer
   *
   * \param camera Camera used for the Renderer
   */
  Renderer(Camera& camera);
  Renderer(const Renderer&) = delete;
  Renderer operator=(const Renderer&) = delete;

  /**
   * Render a new image on the GPU 
   */
  virtual void render() = 0;

  /**
   * Add Entity to the current scene
   *
   * \param entity Entity to add to the world
   */
  void addEntity(Entity* entity);
};

#endif