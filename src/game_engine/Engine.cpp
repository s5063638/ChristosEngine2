#include "Engine.h"
#include "Entity.h"

namespace game_engine
{
	std::shared_ptr<Engine> Engine::Init()
	{
		std::shared_ptr<Engine> rtn = std::make_shared<Engine>();

		return rtn;
	}

	std::shared_ptr<Entity> Engine::AddEntity()
	{
		std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();

		entities.push_back(newEntity);

		return newEntity;
	}

	std::shared_ptr<Keyboard> Engine::GetKeyboard()
	{
		return keyboard;
	}

	void Engine::Start()
	{
		isRunning = true;

		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->Update();
			(*it)->Display();
		}
	}
}