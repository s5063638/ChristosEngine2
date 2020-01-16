#include <game_engine/game_engine.h>

#include <memory>

using namespace game_engine;

struct PlayerControl : public Component
{
	///Used to store the game's Camera
	//! \brief
	//! ```
	//!    std::shared_ptr<Entity> control = engine->AddEntity();
	//!    std::shared_ptr<PlayerControl> pl = control->AddComponent<PlayerControl>();
	//!    pl->camera = camera;
	//! ```
	//! *An example of how to set the camera in PlayerControl*
	std::shared_ptr<Camera> camera; 
	//std::shared_ptr<Entity> cat;

	//! \brief Method used to handle player inputs
	//! 
	//! ```
	//!     if (GetKeyboard()->GetKeyDown(SDLK_w))
	//!     {
	//!			camera->GetTransform()->Translate(rend::vec4(0.0f, 0.0f, -0.25f, 0.0f));
	//!     }
	//! ```
	//! *Moves the camera forward*
	void OnUpdate()
	{
		if (GetKeyboard()->GetKeyDown(SDLK_w))
		{
			camera->GetTransform()->Translate(rend::vec4(0.0f, 0.0f, -0.25f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_s))
		{
			camera->GetTransform()->Translate(rend::vec4(0.0f, 0.0f, 0.25f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_a))
		{
			camera->GetTransform()->Translate(rend::vec4(-0.25f, 0.0f, 0.0f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_d))
		{
			camera->GetTransform()->Translate(rend::vec4(0.25f, 0.0f, 0.0f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_LEFT))
		{
			camera->GetTransform()->Rotate(rend::vec3(0.0f, 0.02f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_RIGHT))
		{
			camera->GetTransform()->Rotate(rend::vec3(0.0f, -0.02f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_UP))
		{
			camera->GetTransform()->Translate(rend::vec4(0.0f, 0.2f, 0.0f, 0.0f));
		}
		if (GetKeyboard()->GetKeyDown(SDLK_DOWN))
		{
			camera->GetTransform()->Translate(rend::vec4(0.0f, -0.2f, 0.0f, 0.0f));
		}
	}
};

///Method used to create everything within game
int main()
{
	//Initialize engine
	std::shared_ptr<Engine> engine = Engine::Init();

	//Camera Setup
	std::shared_ptr<Entity> camEntity = engine->AddEntity();

	std::shared_ptr<Camera> camera = camEntity->AddComponent<Camera>();
	engine->SetCam(camera);

	std::shared_ptr<BoxCollider> camBox = camEntity->AddComponent<BoxCollider>();
	camBox->SetMoveable(true);

	camera->GetTransform()->SetPosition(rend::vec3(0.0f, 0.0f, 0.0f));
	camera->GetTransform()->SetRotation(rend::vec3(0.0f, 0.0f, 0.0f));

	std::shared_ptr<Entity> control = engine->AddEntity();
	std::shared_ptr<PlayerControl> pl = control->AddComponent<PlayerControl>();
	pl->camera = camera;

	//Create a single in-game object
	std::shared_ptr<Entity> cat1 = engine->AddEntity();

	std::shared_ptr<Renderer> renderer = cat1->AddComponent<Renderer>();

	std::shared_ptr<Mesh> catMesh = engine->GetResources()->Load<Mesh>("../models/Cat");
	renderer->SetMesh(catMesh);
	std::shared_ptr<Material> material = engine->GetResources()->Load<Material>("../shaders/ModelShader");
	renderer->SetMaterial(material);
	std::shared_ptr<Texture> catTexture = engine->GetResources()->Load<Texture>("../textures/Whiskers_diffuse");
	renderer->SetTexture(catTexture);

	std::shared_ptr<BoxCollider> cat1Box = cat1->AddComponent<BoxCollider>();
	cat1Box->SetSize(rend::vec3(1.0f, 4.0f, 1.0f));

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

	std::shared_ptr<BoxCollider> cat2Box = cat2->AddComponent<BoxCollider>();
	cat2Box->SetSize(rend::vec3(1.0f, 4.0f, 1.0f));

	cat2->GetComponent<Transform>()->SetPosition(rend::vec3(-1.5f, 0.0f, -10.0f));
	cat2->GetComponent<Transform>()->SetRotation(rend::vec3(0.0f, -4.5f, 0.0f));

	//Create the house
	std::shared_ptr<Entity> cottage = engine->AddEntity();

	std::shared_ptr<Renderer> cottageRenderer = cottage->AddComponent<Renderer>();

	std::shared_ptr<Mesh> cottageMesh = engine->GetResources()->Load<Mesh>("../models/Cottage");
	cottageRenderer->SetMesh(cottageMesh);
	cottageRenderer->SetMaterial(material);
	std::shared_ptr<Texture> cottageTexture = engine->GetResources()->Load<Texture>("../textures/CottageTexture");
	cottageRenderer->SetTexture(cottageTexture);

	std::shared_ptr<BoxCollider> houseCollider = cottage->AddComponent<BoxCollider>();
	houseCollider->SetSize(rend::vec3(35.0f, 35.0f, 25.0f));

	cottage->GetComponent<Transform>()->SetPosition(rend::vec3(5.0f, -4.5f, -40.0f));
	cottage->GetComponent<Transform>()->SetRotation(rend::vec3(0.0f, 0.0f, 0.0f));
	cottage->GetComponent<Transform>()->SetScale(rend::vec3(5.0f, 5.0f, 5.0f));

	//Create grass
	std::shared_ptr<Entity> grass = engine->AddEntity();

	std::shared_ptr<Renderer> grassRenderer = grass->AddComponent<Renderer>();

	std::shared_ptr<Mesh> grassMesh = engine->GetResources()->Load<Mesh>("../models/garden");
	grassRenderer->SetMesh(grassMesh);
	grassRenderer->SetMaterial(material);
	std::shared_ptr<Texture> grassTexture = engine->GetResources()->Load<Texture>("../textures/grass");
	grassRenderer->SetTexture(grassTexture);

	std::shared_ptr<BoxCollider> grassCollider = grass->AddComponent<BoxCollider>();
	grassCollider->SetSize(rend::vec3(75.0f, 0.1f, 75.0f));

	grass->GetComponent<Transform>()->SetPosition(rend::vec3(-0.0f, -4.0f, -50.0f));
	grass->GetComponent<Transform>()->SetRotation(rend::vec3(-4.7f, 0.0f, 0.0f));
	grass->GetComponent<Transform>()->SetScale(rend::vec3(1.0f, 1.0f, 0.001f));

	//Start the main loop
	engine->Start();

	return 0;
}
