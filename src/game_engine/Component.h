#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include "Engine.h"

namespace game_engine
{
	class Entity;
	class Engine;
	class Keyboard;
	class Transform;

	class Component
	{
		private:
			friend class Entity;
			std::weak_ptr<Entity> entity;
		public:
			virtual void OnInit();
			virtual void OnBegin();
			virtual void OnDisplay();
			virtual void OnUpdate();

			std::shared_ptr<Entity> GetEntity();
			std::shared_ptr<Engine> GetEngine();
			std::shared_ptr<Keyboard> GetKeyboard();
			std::shared_ptr<Entity> AddEntity();
			std::shared_ptr<Transform> GetTransform();
	};
}
#endif // !_COMPONENT_H_