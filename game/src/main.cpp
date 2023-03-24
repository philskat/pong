#include <gameengine.hpp>
#include <iostream>

#ifdef PONGGAME_DEBUG
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <glm/gtc/type_ptr.hpp>
#endif

#include "staticrenderer.hpp"

int main()
{
	Window win(800, 600, "First window");

	std::vector<glm::vec2> positions({
		glm::vec2(-200.0f, -150.0f),
		glm::vec2( 200.0f, -150.0f),
		glm::vec2( 0.0f,    150.0f)
	});

	std::vector<glm::vec3> colors({
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	});

	ResourceManager& resourceManager = ResourceManager::getInstance();

	resourceManager.loadModelFromData("triangle", positions, colors);

	Camera camera(glm::vec2(0.0f, 0.0f));

	Entity triangle(resourceManager.getModel("triangle"), glm::vec2(400.0f, 300.0f));

	StaticRenderer renderer(camera);

	renderer.addEntity(&triangle);

#ifdef PONGGAME_DEBUG
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(win.getWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
#endif

	while (win.isOpen())
	{
		glClear(GL_COLOR_BUFFER_BIT);

#ifdef PONGGAME_DEBUG
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
#endif

		renderer.render();

#ifdef PONGGAME_DEBUG
		{
			glm::vec2 position = triangle.getPosition();
			glm::vec2 scale = triangle.getScale();
			float rotation = triangle.getRotation();

			ImGui::Begin("Triangle");

			ImGui::DragFloat2("Position", glm::value_ptr(position), 1.0f, 0.0f, 800.0f, "%.0f");

			ImGui::DragFloat2("Scale", glm::value_ptr(scale), 0.2f, 0.0f, 10.0f);
			
			ImGui::DragFloat("Rotation", &rotation, 1.0f, 0.0f, 360.0f);

			ImGui::End();

			triangle.setPosition(position);
			triangle.setScale(scale);
			triangle.setRotation(rotation);
		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif

		win.update();
	}

#ifdef PONGGAME_DEBUG
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
#endif

	return 0;
}

