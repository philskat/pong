#include "resourcemanager.hpp"

ResourceManager ResourceManager::m_Instance;

ResourceManager::ResourceManager()
{

}

ResourceManager& ResourceManager::getInstance()
{
  return m_Instance;
}

void ResourceManager::cleanUp()
{
  for (std::pair<std::string, Model*> value : m_Models)
  {
    delete value.second;
  }

  m_Models.clear();

  for (std::pair<std::string, ShaderProgram*> value : m_Shaders)
  {
    delete value.second;
  }

  m_Shaders.clear();
}

Model* ResourceManager::loadModelFromData(std::string name, std::vector<glm::vec2> positions, std::vector<glm::vec3> colors)
{
  GLuint vao;
  GLuint vbo;
  std::vector<GLuint> vbos;

  glCreateVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  vbos.push_back(vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * positions.size() * 2, positions.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);


  glGenBuffers(1, &vbo);
  vbos.push_back(vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * colors.size(), colors.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

  glBindVertexArray(0);

  Model* model = new Model(vao, vbos, positions.size());

  m_Models[name] = model;

  return model;
}

Model* ResourceManager::getModel(std::string name)
{
  return m_Models[name];
}

ShaderProgram* ResourceManager::registerShader(std::string name, ShaderProgram* shader)
{
  m_Shaders[name] = shader;

  return shader;
}

ShaderProgram* ResourceManager::getShader(std::string name)
{
  return m_Shaders[name];
}