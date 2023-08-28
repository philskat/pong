#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "entity.hpp"

/**
 * Entity that represents the Camera of the game 
 */
class Camera : public Entity
{
public:
  /**
   * Create a Camera
   * 
   * \param position Position of the camera in the game world
   */
  Camera(glm::vec2 position);
};

#endif