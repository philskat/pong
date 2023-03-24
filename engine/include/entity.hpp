#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "model.hpp"
#include "glm/glm.hpp"

class Entity
{
private:
  Model* m_Model;
  glm::vec2 m_Position;

public:
  Entity(Model* model);
  Entity(Model* model, glm::vec2 position);

  Model* getModel() const;

  void setPosition(glm::vec2 position);
  glm::vec2 getPosition() const;
};

#endif