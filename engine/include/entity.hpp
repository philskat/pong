#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "model.hpp"
#include "glm/glm.hpp"

/**
 * Represents an Entity in the game world 
 */
class Entity
{
private:
  Model* m_Model;
  glm::vec2 m_Position,
            m_Scale;
  float m_Rotation;

public:
  /**
   * Create Entity from Model
   * 
   * \parm model Model that should be used for the Entity
   */
  Entity(Model* model);
  /**
   * Create Entity from Model and set Position
   *
   * \param model Model that should be used for the Entity
   * \param position Position of the Entity
   */
  Entity(Model* model, glm::vec2 position);
  /**
   * Create Entity from Model and set position and scale
   * 
   * \param model Model that should be used for the Entity
   * \param position Position of the Entity
   * \param scale Scale of the Entity
   */
  Entity(Model* model, glm::vec2 position, glm::vec2 scale);
  /**
   * Create Entity from Modle and set position, scale and rotation
   * 
   * \param model Model that should be used for the Entity
   * \param position Position of the Entity
   * \param scale Scale of the Entity
   * \param rotation Rotation of the Entity in degree
   */
  Entity(Model* model, glm::vec2 position, glm::vec2 scale, float rotation);

  /**
   * Return the Model used by the Entity
   *
   * \return Model used by the Entity
   */
  Model* getModel() const;

  /**
   * Set Position of the Entity
   *
   * \param position New position of the Entity
   */
  void setPosition(glm::vec2 position);
  /**
   * Get Position of the Entity
   *
   * \return Current position of the Entity
   */
  glm::vec2 getPosition() const;

  /**
   * Set Scale of the Entity
   *
   * \param New Scale of the Entity
   */
  void setScale(glm::vec2 scale);
  /**
   * Get Scale of the Entity
   *
   * \return Current scale of the Entity
   */
  glm::vec2 getScale() const;

  /**
   * Set Rotation of the Entity
   * 
   * \param rotation New Rotation of the Entity in degree
   */
  void setRotation(float rotation);
  /**
   * Get Rotation of the Entity 
   * 
   * \return Current Rotation of the Entity in degree
   */
  float getRotation() const;
};

#endif