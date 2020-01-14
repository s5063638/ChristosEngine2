#include "Component.h"
#include "Entity.h"
#include "Engine.h"
#include "Transform.h"

namespace game_engine
{
	void Component::OnInit()
	{

	}

	void Component::OnBegin()
	{

	}

	void Component::OnUpdate()
	{

	}

	void Component::OnDisplay()
	{

	}

	//! \brief
	//! ```
	//!    std::shared_ptr<Entity> ent = engine->AddEntity();
	//!
	//!    std::shared_ptr<Renderer> renderer = ent->AddComponent<Renderer>();
	//!
	//!    renderer->GetEntity()->GetEngine();
	//! ```
	//! *An example of using GetEntity() to access the engine*
	std::shared_ptr<Entity> Component::GetEntity()
	{
		return entity.lock();
	}

	//! \brief
	//! ```
	//!    std::shared_ptr<Entity> ent = engine->AddEntity();
	//!
	//!    std::shared_ptr<Renderer> renderer = ent->AddComponent<Renderer>();
	//!
	//!    renderer->GetEntity()->GetEngine()->GetContext();
	//! ```
	//! *An example of using GetEngine() to access the engine from a component*
	std::shared_ptr<Engine> Component::GetEngine()
	{
		return GetEntity()->GetEngine();
	}

	//! \brief
	//! ```
	//!    if (GetKeyboard()->GetKeyDown(SDLK_w))
	//!    {
	//!        //Move player forward
	//!    }
	//! ```
	//! *An example of using GetKeyboard() to check for inputs*
	std::shared_ptr<Keyboard> Component::GetKeyboard()
	{
		return GetEngine()->GetKeyboard();
	}

	//! \brief
	//! ```
	//!    //Initialize engine
	//!    std::shared_ptr<Engine> engine = Engine::Init();
	//!
	//!    //Create a single in-game object
	//!    std::shared_ptr<Entity> ent = engine->AddEntity();
	//! ```
	//! *An example of using AddEntity() to create another Entity in the engine*
	std::shared_ptr<Entity> Component::AddEntity()
	{
		return GetEngine()->AddEntity();
	}

	//! \brief
	//! ```
	//!    camera->GetTransform()->Translate(rend::vec4(0.0f, 0.0f, -0.25f, 0.0f));
	//! ```
	//! *An example of using GetTransform() to move a camera forward*
	std::shared_ptr<Transform> Component::GetTransform()
	{
		return GetEntity()->GetComponent<Transform>();
	}
}