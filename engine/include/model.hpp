#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/glew.h>
#include <vector>

class Model
{
private:
  GLuint m_VAO;
  std::vector<GLuint> m_VBOs;
  unsigned int m_VertexCount;

public:
  Model() = default;

  Model(GLuint vao, std::vector<GLuint> vbos, unsigned int vertexCount);
  virtual ~Model();
  Model(const Model&) = delete;
  Model operator=(const Model&) = delete;

  GLuint getVao() const;

  unsigned int getVertexCount() const;
};

#endif