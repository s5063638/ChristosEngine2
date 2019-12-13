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
	std::shared_ptr<Renderer> renderer = entity->AddComponent<Renderer>();

	//do get transform in entity
	entity->GetComponent<Transform>()->SetPosition(rend::vec3(0, 0, -10));

	std::shared_ptr<Mesh> mesh = engine->GetResources()->Load<Mesh>("../models/Cat");
	
	renderer->SetMesh(mesh);

	std::shared_ptr<Material> material = engine->GetResources()->Load<Material>("../shaders/ModelShader");

	renderer->SetMaterial(material);

	std::shared_ptr<Entity> camEntity = engine->AddEntity();
	std::shared_ptr<Camera> camera = camEntity->AddComponent<Camera>();
	
	////Start the main loop
	engine->Start();

	return 0;
}
