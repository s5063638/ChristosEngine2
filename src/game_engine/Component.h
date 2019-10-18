#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>

namespace game_engine
{
	class Entity;
	class Engine;
	class Keyboard;

	class Component
	{
		private:
			std::weak_ptr<Entity> entity;

			void OnInit();
			void onBegin();
			void OnDisplay();
			void OnUpdate();
		public:
			std::shared_ptr<Entity> GetEntity();
			std::shared_ptr<Engine> GetEngine();
			std::shared_ptr<Keyboard> GetKeyboard();
	};
}
#endif // !_COMPONENT_H_