#include "entity.hpp"

Entity::Entity(Model* model)
{
  m_Model = model;
  m_Position = glm::vec2();
  m_Scale = glm::vec2(1.0f);
  m_Rotation = 0.0f;
}

Entity::Entity(Model* model, glm::vec2 position)
{
  m_Model = model;
  m_Position = position;
  m_Scale = glm::vec2(1.0f);
  m_Rotation = 0.0f;
}

Entity::Entity(Model* model, glm::vec2 position, glm::vec2 scale)
{
  m_Model = model;
  m_Position = position;
  m_Scale = scale;
  m_Rotation = 0.0f;
}

Entity::Entity(Model* model, glm::vec2 position, glm::vec2 scale, float rotation)
{
  m_Model = model;
  m_Position = position;
  m_Scale = scale;
  m_Rotation = rotation;
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

void Entity::setScale(glm::vec2 scale)
{
  m_Scale = scale;
}

glm::vec2 Entity::getScale() const
{
  return m_Scale;
}

void Entity::setRotation(float rotation)
{
  m_Rotation = rotation;
}

float Entity::getRotation() const
{
  return m_Rotation;
}
