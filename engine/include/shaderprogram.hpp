#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>

class ShaderProgram
{
private:
  GLuint m_ProgramID, m_VertexShader, m_FragmentShader;

public:
  ShaderProgram(const char* name, const char* vertexPath, const char* fragmentPath);
  virtual ~ShaderProgram();
  ShaderProgram(const ShaderProgram&) = delete;
  ShaderProgram operator=(const ShaderProgram&) = delete;

  void start();
  void stop();

protected:
  GLuint getUniformLocation(const char* variableName);

  void setUniformInt(GLuint location, int value);
  void setUniformFloat(GLuint location, float value);
  void setUniformVec2(GLuint location, glm::vec2 value);
  void setUniformVec3(GLuint location, glm::vec3 value);
  void setUnifromVec4(GLuint location, glm::vec4 value);

  void setUniformMatrix2(GLuint location, glm::mat2 value);
  void setUniformMatrix3(GLuint location, glm::mat3 value);
  void setUniformMatrix4(GLuint location, glm::mat4 value);

private:
  GLuint loadShader(GLenum type, const char* path);
};

#endif