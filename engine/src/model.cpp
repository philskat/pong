#include "model.hpp"
#include <iostream>

Model::Model(GLuint vao, std::vector<GLuint> vbos, unsigned int vertexCount)
{
  m_VAO = vao;
  m_VBOs = vbos;
  m_VertexCount = vertexCount;
}

Model::~Model()
{
  glDeleteVertexArrays(1, &m_VAO);

  glDeleteBuffers(m_VBOs.size(), m_VBOs.data());
}

GLuint Model::getVao() const
{
  return m_VAO;
}

unsigned int Model::getVertexCount() const
{
  return m_VertexCount;
}
