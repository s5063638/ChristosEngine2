#include <game_engine/game_engine.h>

#include <memory>

using namespace game_engine;

int main()
{
	//Initialize engine
	std::shared_ptr<Engine> engine = Engine::Init();
	
	//Create a single in-game object
	std::shared_ptr<Entity> entity = engine->AddEntity();

	//Add a very simple component to it
	//std::shared_ptr<Component> c = entity->AddComponent<Component>();
	std::shared_ptr<Renderer> c = entity->AddComponent<Renderer>();

	std::shared_ptr<Mesh> mesh = engine->GetResources()->Load<Mesh>("../models/Cat");
	std::shared_ptr<Shader> shader = engine->GetResources()->Load<Shader>("../shaders/Source");
	
	////Start the main loop
	engine->Start();

	return 0;
}
