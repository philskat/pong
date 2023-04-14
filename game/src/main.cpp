#include "pongapp.hpp"

#include <iostream>

int main()
{
	try {
		PongApp app;

		while (app.isRunning())
		{
			app.update();
		}

	}
	catch (const char* error)
	{
		std::cerr << error << std::endl;
	}

	return 0;
}

