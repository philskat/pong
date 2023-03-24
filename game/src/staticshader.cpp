#include "staticshader.hpp"
#include <glm/gtc/matrix_transform.hpp>

StaticShader::StaticShader()
	: ShaderProgram("staticShader", "assets/staticShader.vertex", "assets/staticShader.fragment")
{
	m_UniformProjectionMatrix = getUniformLocation("projection_matrix");
	m_UniformViewMatrix = getUniformLocation("view_matrix");
	m_UniformModelMatrix = getUniformLocation("model_matrix");

	start();
	setUniformMatrix4(m_UniformProjectionMatrix, glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -10.0f, 10.0f));
	stop();
}

void StaticShader::setTransformationMatrix(const Entity& entity)
{
	glm::mat4 transform(1.0f);

	transform = glm::translate(transform, glm::vec3(entity.getPosition(), 0.0f));

	transform = glm::rotate(transform, glm::radians(entity.getRotation()), glm::vec3(0.0f, 0.0f, 1.0f));

	transform = glm::scale(transform, glm::vec3(entity.getScale(), 1.0f));

	setUniformMatrix4(m_UniformModelMatrix, transform);
}

void StaticShader::setViewMatrix(const Camera& camera)
{
	glm::mat4 viewMatrix(1.0f);
	glm::vec2 cameraPos = camera.getPosition();

	viewMatrix = glm::translate(viewMatrix, glm::vec3(-cameraPos.x, -cameraPos.y, 1.0f));

	setUniformMatrix4(m_UniformViewMatrix, viewMatrix);
}