#include "staticrenderer.hpp"

StaticRenderer::StaticRenderer(Window& window, Camera& camera)
  : Renderer(window, camera)
{
  m_Shader = new StaticShader();
}

void StaticRenderer::render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  m_Shader->start();

  m_Shader->setViewMatrix(m_Camera);

  for (Entity* entity : m_Entities)
  {
    Model* model = entity->getModel();

    m_Shader->setTransformationMatrix(entity->getPosition());

    glBindVertexArray(model->getVao());

    glDrawArrays(GL_TRIANGLES, 0, model->getVertexCount());

    glBindVertexArray(0);
  }

  m_Shader->stop();
  swapBuffers();
}