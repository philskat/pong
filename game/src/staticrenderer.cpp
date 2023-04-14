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

  for (auto weakEntity : m_Entities)
  {
    if (weakEntity.expired())
    {
      continue;
    }

    std::shared_ptr<Entity> entity = weakEntity.lock();

    Model* model = entity->getModel();

    m_Shader->setTransformationMatrix(*entity);

    glBindVertexArray(model->getVao());

    glDrawArrays(GL_TRIANGLES, 0, model->getVertexCount());

    glBindVertexArray(0);
  }

  m_Shader->stop();
}