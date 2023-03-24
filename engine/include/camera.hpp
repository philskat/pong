#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "entity.hpp"

class Camera : public Entity
{
public:
  Camera(glm::vec2 position);
};

#endif