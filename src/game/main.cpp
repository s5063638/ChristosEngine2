#include <game_engine/Engine.h>

#include <memory>

using namespace game_engine;

int main()
{
	//Initialize engine
	std::shared_ptr<Engine> engine = Engine::Init();
	
	//Create a single in-game object
	std::shared_ptr<Entity> entity = engine->AddEntity();

	//Add a very simple component to it


	//Start the main loop
	engine->Start();

	return 0;
}