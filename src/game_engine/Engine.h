#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <vector>
#include <memory>

namespace game_engine
{
	class Entity;
	class Keyboard;

	class Engine
	{
		private:
			std::vector<Entity> entities;
			bool isRunning;
			std::shared_ptr<Keyboard> keyboard;
		public:
			void Start();
			void End();
			std::shared_ptr<Entity> AddEntity();
			static std::shared_ptr<Engine> Init();
	};
}

#endif // !ENGINE_H_