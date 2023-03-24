#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <GL/glew.h>
#include <map>
#include <string>
#include <vector>
#include <glm/glm.hpp>

#include "model.hpp"
#include "shaderprogram.hpp"

class ResourceManager
{
private:
  static ResourceManager m_Instance;

  std::map<std::string, Model*> m_Models;

  std::map<std::string, ShaderProgram*> m_Shaders;

public:
  static ResourceManager& getInstance();

  void cleanUp();

  Model* loadModelFromData(std::string name, std::vector<glm::vec2> positions, std::vector<glm::vec3> colors);
  Model* getModel(std::string name);

  ShaderProgram* registerShader(std::string name, ShaderProgram* shader);
  ShaderProgram* getShader(std::string name);

private:
  ResourceManager();
  ResourceManager(ResourceManager const&) = delete;
  ResourceManager operator=(ResourceManager const&) = delete;
};

#endif