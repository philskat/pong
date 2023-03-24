#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "model.hpp"
#include "glm/glm.hpp"

class Entity
{
private:
  Model* m_Model;
  glm::vec2 m_Position,
            m_Scale;
  float m_Rotation;

public:
  Entity(Model* model);
  Entity(Model* model, glm::vec2 position);
  Entity(Model* model, glm::vec2 position, glm::vec2 scale);
  Entity(Model* model, glm::vec2 position, glm::vec2 scale, float rotation);

  Model* getModel() const;

  void setPosition(glm::vec2 position);
  glm::vec2 getPosition() const;

  void setScale(glm::vec2 scale);
  glm::vec2 getScale() const;

  void setRotation(float rotation);
  float getRotation() const;
};

#endif