#include "entity.hpp"

Entity::Entity(Model* model)
{
  m_Model = model;
}

Entity::Entity(Model* model, glm::vec2 position)
{
  m_Model = model;
  m_Position = position;
}

Model* Entity::getModel() const
{
  return m_Model;
}

void Entity::setPosition(glm::vec2 position)
{
  m_Position = position;
}

glm::vec2 Entity::getPosition() const
{
  return m_Position;
}
