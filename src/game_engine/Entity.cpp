#include "Entity.h"
#include "Component.h"

namespace game_engine
{
	//! \brief
	//! ```
	//!    std::shared_ptr<Entity> ent = engine->AddEntity();
	//!
	//!    ent->GetEngine()->GetKeyboard();
	//! ```
	//! *An example of using GetEngine() to access the keyboard input*
	std::shared_ptr<Engine> Entity::GetEngine()
	{
		return engine.lock();
	}

	void Entity::Display()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			(*it)->OnDisplay();
		}

	}

	void Entity::Update()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			(*it)->OnUpdate();
		}
	}
}