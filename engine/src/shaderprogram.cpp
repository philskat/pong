#include "shaderprogram.hpp"
#include "resourcemanager.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>
#include <iostream>

ShaderProgram::ShaderProgram(const char* name, const char* vertexPath, const char* fragmentPath)
{
  m_ProgramID = glCreateProgram();

  m_VertexShader = loadShader(GL_VERTEX_SHADER, vertexPath);
  m_FragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentPath);

  glAttachShader(m_ProgramID, m_VertexShader);
  glAttachShader(m_ProgramID, m_FragmentShader);

  glLinkProgram(m_ProgramID);

  ResourceManager::getInstance().registerShader(name, this);
}

ShaderProgram::~ShaderProgram()
{
  glDetachShader(m_ProgramID, m_VertexShader);
  glDeleteShader(m_VertexShader);

  glDetachShader(m_ProgramID, m_FragmentShader);
  glDeleteShader(m_FragmentShader);

  glDeleteProgram(m_ProgramID);
}

void ShaderProgram::start()
{
  glUseProgram(m_ProgramID);
}

void ShaderProgram::stop()
{
  glUseProgram(0);
}

GLuint ShaderProgram::getUniformLocation(const char* variableName)
{
  return glGetUniformLocation(m_ProgramID, variableName);
}

void ShaderProgram::setUniformInt(GLuint location, int value)
{
  glUniform1i(location, value);
}

void ShaderProgram::setUniformFloat(GLuint location, float value)
{
  glUniform1f(location, value);
}

void ShaderProgram::setUniformVec2(GLuint location, glm::vec2 value)
{
  glUniform2f(location, value.x, value.y);
}

void ShaderProgram::setUniformVec3(GLuint location, glm::vec3 value)
{
  glUniform3f(location, value.x, value.y, value.z);
}

void ShaderProgram::setUnifromVec4(GLuint location, glm::vec4 value)
{
  glUniform4f(location, value.x, value.y, value.z, value.w);
}

void ShaderProgram::setUniformMatrix2(GLuint location, glm::mat2 value)
{
  glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::setUniformMatrix3(GLuint location, glm::mat3 value)
{
  glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::setUniformMatrix4(GLuint location, glm::mat4 value)
{
  glUniformMatrix4fv(location, 1, GL_TRUE, glm::value_ptr(value));
}

GLuint ShaderProgram::loadShader(GLenum type, const char* path)
{
  FILE* f = fopen(path, "rt");

  if (f == nullptr)
  {
    throw "Could not open file";
  }

  fseek(f, 0, SEEK_END);
  GLint length = ftell(f);
  fseek(f, 0, SEEK_SET);

  char* buffer = new char[length + 1];
  memset(buffer, 0, length + 1);

  fread(buffer, sizeof(char), length, f);

  fclose(f);

  GLuint shader = glCreateShader(type);

  glShaderSource(shader, 1, &buffer, &length);

  glCompileShader(shader);

  GLint value;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &value);

  if (value == GL_FALSE)
  {
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &value);
    char* msgBuffer = new char[value + 1];
    memset(msgBuffer, 0, value + 1);

    glGetShaderInfoLog(shader, value, NULL, msgBuffer);

    switch (type)
    {
    case GL_VERTEX_SHADER:
      std::cerr << "Vertex Error:" << std::endl;
      break;

    case GL_FRAGMENT_SHADER:
      std::cerr << "Fragment Error:" << std::endl;
    }

    std::cerr << msgBuffer << std::endl << std::endl;

    delete[] msgBuffer;
  }

  delete[] buffer;

  return shader;
}
