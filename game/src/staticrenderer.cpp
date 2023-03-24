#include "staticrenderer.hpp"

StaticRenderer::StaticRenderer(Camera& camera)
  : Renderer(camera)
{
  m_Shader = new StaticShader();
}

void StaticRenderer::render()
{
  m_Shader->start();

  m_Shader->setViewMatrix(m_Camera);

  for (Entity* entity : m_Entities)
  {
    Model* model = entity->getModel();

    m_Shader->setTransformationMatrix(*entity);

    glBindVertexArray(model->getVao());

    glDrawArrays(GL_TRIANGLES, 0, model->getVertexCount());

    glBindVertexArray(0);
  }

  m_Shader->stop();
}