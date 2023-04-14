#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/glew.h>
#include <vector>

/**
 * Represents a Model used for Objects.
 * This is used to store the relevant references to video memory and handles the cleanUp on exit
 */
class Model
{
private:
  GLuint m_VAO;
  std::vector<GLuint> m_VBOs;
  unsigned int m_VertexCount;

public:
  Model() = default;

  /**
   * Constructor
   * 
   * \param vao VAO id of the model in video memory
   * \param vbos VBOs used by the model
   * \param vertexCount Number of vertices of the Model
   */
  Model(GLuint vao, std::vector<GLuint> vbos, unsigned int vertexCount);
  virtual ~Model();
  /**
   * Deleted to prevent copying of model which results in two cleanUps in video memory 
   */
  Model(const Model&) = delete;
  Model operator=(const Model&) = delete;

  /**
   * Get VAO id of the Model
   *
   * \return ID of the VAO
   */
  GLuint getVao() const;

  /**
   * Get number of vertices of the Model
   * 
   * \return Number of vertices
   */
  unsigned int getVertexCount() const;
};

#endif