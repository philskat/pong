#ifndef APPLICATION_HPP
#define APPLICATION_HPP

class Application
{
public:
  Application();
  Application(const Application& other) = delete;
  virtual ~Application();

  virtual void onUpdate() = 0;
  virtual void onRender() = 0;

  virtual bool isRunning() = 0;

  void update();
};

#endif
