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
			camera->GetTransform()->Translate(rend::vec4(0.0f, 0.0f, -0.1f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_s))
		{
			camera->GetTransform()->Translate(rend::vec4(0.0f, 0.0f, 0.1f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_a))
		{
			camera->GetTransform()->Translate(rend::vec4(-0.1f, 0.0f, 0.0f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_d))
		{
			camera->GetTransform()->Translate(rend::vec4(0.1f, 0.0f, 0.0f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_LEFT))
		{
			camera->GetTransform()->Rotate(rend::vec3(0.0f, 0.01f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_RIGHT))
		{
			camera->GetTransform()->Rotate(rend::vec3(0.0f, -0.01f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_UP))
		{
			camera->GetTransform()->Rotate(rend::vec3(0.01f, 0.0f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_DOWN))
		{
			camera->GetTransform()->Rotate(rend::vec3(-0.01f, 0.0f, 0.0f));
		}
	}
};


int main()
{
	//Initialize engine
	std::shared_ptr<Engine> engine = Engine::Init();

	//Create a single in-game object
	std::shared_ptr<Entity> cat1 = engine->AddEntity();

	std::shared_ptr<Renderer> renderer = cat1->AddComponent<Renderer>();

	std::shared_ptr<Mesh> catMesh = engine->GetResources()->Load<Mesh>("../models/Cat");
	renderer->SetMesh(catMesh);
	std::shared_ptr<Material> material = engine->GetResources()->Load<Material>("../shaders/ModelShader");
	renderer->SetMaterial(material);
	std::shared_ptr<Texture> catTexture = engine->GetResources()->Load<Texture>("../textures/Whiskers_diffuse");
	renderer->SetTexture(catTexture);

	cat1->GetComponent<Transform>()->SetPosition(rend::vec3(1.5f, 0.0f, -10.0f));
	cat1->GetComponent<Transform>()->SetRotation(rend::vec3(0.0f, 4.5f, 0.0f));

	//Add Second Cat
	std::shared_ptr<Entity> cat2 = engine->AddEntity();

	std::shared_ptr<Renderer> cat2Renderer = cat2->AddComponent<Renderer>();

	//std::shared_ptr<Mesh> mesh = engine->GetResources()->Load<Mesh>("../models/Cat");
	cat2Renderer->SetMesh(catMesh);
	//std::shared_ptr<Material> material = engine->GetResources()->Load<Material>("../shaders/ModelShader");
	cat2Renderer->SetMaterial(material);
	//std::shared_ptr<Texture> texture = engine->GetResources()->Load<Texture>("../textures/Whiskers_diffuse");
	cat2Renderer->SetTexture(catTexture);

	cat2->GetComponent<Transform>()->SetPosition(rend::vec3(-1.5f, 0.0f, -10.0f));
	cat2->GetComponent<Transform>()->SetRotation(rend::vec3(0.0f, -4.5f, 0.0f));
	//cat2->GetComponent<Transform>()->SetScale(rend::vec3(30.0f, 30.0f, 30.0f));

	//Add House
	std::shared_ptr<Entity> graveyard = engine->AddEntity();

	std::shared_ptr<Renderer> graveyardRenderer = graveyard->AddComponent<Renderer>();

	std::shared_ptr<Mesh> graveyardMesh = engine->GetResources()->Load<Mesh>("../models/graveyard");
	graveyardRenderer->SetMesh(graveyardMesh);
	graveyardRenderer->SetMaterial(material);
	std::shared_ptr<Texture> graveyardTexture = engine->GetResources()->Load<Texture>("../textures/graveyard");
	graveyardRenderer->SetTexture(graveyardTexture);

	graveyard->GetComponent<Transform>()->SetPosition(rend::vec3(0.0f, 0.0f, 0.0f));
	graveyard->GetComponent<Transform>()->SetRotation(rend::vec3(0.0f, 0.0f, 0.0f));
	graveyard->GetComponent<Transform>()->SetScale(rend::vec3(2.0f, 2.0f, 2.0f));

	//Camera Setup
	std::shared_ptr<Entity> camEntity = engine->AddEntity();

	std::shared_ptr<Camera> camera = camEntity->AddComponent<Camera>();
	engine->SetCam(camera);
	camera->GetTransform()->SetPosition(rend::vec3(0.0f, 0.0f, 0.0f));
	camera->GetTransform()->SetRotation(rend::vec3(0.0f, 0.0f, 0.0f));

	std::shared_ptr<Entity> control = engine->AddEntity();
	std::shared_ptr<PlayerControl> pl = control->AddComponent<PlayerControl>();
	pl->camera = camera;

	////Start the main loop
	engine->Start();

	return 0;
}
