#include "pongapp.hpp"

#ifdef PONGGAME_DEBUG
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#endif

#include <glm/gtc/type_ptr.hpp>

PongApp::PongApp()
  : m_Camera(glm::vec2(0.0f, 0.0f))
{
  m_Window = Window::createWindow(800, 600, "First window");

  if (!m_Window)
  {
    throw "Could not create Window";
  }

  std::vector<glm::vec2> positions({
    glm::vec2(-200.0f, -150.0f),
    glm::vec2(200.0f, -150.0f),
    glm::vec2(0.0f,    150.0f)
    });

  std::vector<glm::vec3> colors({
    glm::vec3(1.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 1.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 1.0f)
    });

  ResourceManager& resourceManager = ResourceManager::getInstance();

  resourceManager.loadModelFromData("triangle", positions, colors);

  m_Triangle = std::make_shared<Entity>(resourceManager.getModel("triangle"), glm::vec2(400.0f, 300.0f));

  m_Renderer = std::make_shared<StaticRenderer>(m_Camera);

  m_Renderer->addEntity(m_Triangle);

#ifdef PONGGAME_DEBUG
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(m_Window->getWindow(), true);
  ImGui_ImplOpenGL3_Init("#version 330 core");
#endif
}

PongApp::~PongApp()
{
#ifdef PONGGAME_DEBUG
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
#endif 
}

void PongApp::onUpdate()
{

}

void PongApp::onRender()
{
  glClear(GL_COLOR_BUFFER_BIT);

  m_Renderer->render();

#ifdef PONGGAME_DEBUG
  onGuiRender();
#endif

  m_Window->update();
}

bool PongApp::isRunning()
{
  return m_Window->isOpen();
}

#ifdef PONGGAME_DEBUG
void PongApp::onGuiRender()
{
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
  
  {
    glm::vec2 position = m_Triangle->getPosition();
    glm::vec2 scale = m_Triangle->getScale();
    float rotation = m_Triangle->getRotation();

    ImGui::Begin("Triangle");

    ImGui::DragFloat2("Position", glm::value_ptr(position), 1.0f, 0.0f, 800.0f, "%.0f");
    ImGui::DragFloat2("Scale", glm::value_ptr(scale), 0.2f, 0.0f, 10.0f);
    ImGui::DragFloat("Rotation", &rotation, 1.0f, 0.0f, 360.0f);

    ImGui::End();

    m_Triangle->setPosition(position);
    m_Triangle->setScale(scale);
    m_Triangle->setRotation(rotation);
  }

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
#endif
