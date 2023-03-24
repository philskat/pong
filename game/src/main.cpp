#include <gameengine.hpp>
#include <iostream>

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

	StaticRenderer renderer(win, camera);

	renderer.addEntity(&triangle);

	while (win.isOpen())
	{
		renderer.render();
	}

	return 0;
}

