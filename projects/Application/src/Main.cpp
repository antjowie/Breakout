#include "Application.hpp"
#include "BreakoutGame.hpp"

int main()
{
	Application app;
	app.init(1280, 720, std::make_unique<BreakoutGame>());
	app.run();

	return 0;
}