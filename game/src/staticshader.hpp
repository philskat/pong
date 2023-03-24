#ifndef STATIC_SHADER_HPP
#define STATIC_SHADER_HPP

#include <gameengine.hpp>

class StaticShader : public ShaderProgram
{
private:
	GLuint m_UniformProjectionMatrix, 
		     m_UniformViewMatrix, 
		     m_UniformModelMatrix;

public:
	StaticShader();

	void setTransformationMatrix(glm::vec2 position);

	void setViewMatrix(const Camera& camera);
};

#endif