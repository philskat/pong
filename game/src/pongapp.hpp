#ifndef PONGAPP_HPP
#define PONGAPP_HPP

#include <gameengine.hpp>
#include "staticrenderer.hpp"

class PongApp : public Application
{
private:
  std::unique_ptr<Window> m_Window;

  Camera m_Camera;

  std::shared_ptr<Entity> m_Triangle;

  std::shared_ptr<StaticRenderer> m_Renderer;

public:
  PongApp();
  ~PongApp();

  virtual void onUpdate() override;
  virtual void onRender() override;
  virtual bool isRunning() override;

#ifdef PONGGAME_DEBUG
  void onGuiRender();
#endif
};

#endif
