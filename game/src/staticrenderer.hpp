#ifndef STATIC_RENDERER_HPP
#define STATIC_RENDERER_HPP

#include <gameengine.hpp>

#include "staticshader.hpp"

class StaticRenderer : public Renderer
{
private:
  StaticShader* m_Shader;

public:
  StaticRenderer(Window& window, Camera& camera);

  virtual void render() override;
};

#endif