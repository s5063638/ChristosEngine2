#include <game_engine/game_engine.h>

#include <memory>

using namespace game_engine;

struct PlayerControl : public Component
{
	std::shared_ptr<Camera> camera;

	void OnUpdate()
	{
		if (GetKeyboard()->GetKeyDown(SDLK_w))
		{
			camera->GetTransform()->Translate(rend::vec3(0.0f, 0.0f, -0.05f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_s))
		{
			camera->GetTransform()->Translate(rend::vec3(0.0f, 0.0f, 0.05f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_a))
		{
			camera->GetTransform()->Translate(rend::vec3(-0.05f, 0.0f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_d))
		{
			camera->GetTransform()->Translate(rend::vec3(0.05f, 0.0f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_LEFT))
		{
			camera->GetTransform()->Rotate(rend::vec3(0.0f, 0.01f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_RIGHT))
		{
			camera->GetTransform()->Rotate(rend::vec3(0.0f, -0.01f, 0.0f));
		}
	}
};


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

	//std::shared_ptr<Texture> texture = engine->GetResources()->Load<Texture>("../textures/Whiskers_diffuse");

	//renderer->SetTexture(texture);

	std::shared_ptr<Entity> camEntity = engine->AddEntity();

	std::shared_ptr<Camera> camera = camEntity->AddComponent<Camera>();
	engine->SetCam(camera);

	std::shared_ptr<Entity> control = engine->AddEntity();
	std::shared_ptr<PlayerControl> pl = control->AddComponent<PlayerControl>();
	pl->camera = camera;

	//camera->GetTransform()->SetPosition(rend::vec3(0.0f, 0.0f, -1.0f));
	//camera->GetTransform()->SetRotation(rend::vec3(0.2f, 0.0f, 0.0f));

	////Start the main loop
	engine->Start();

	return 0;
}
