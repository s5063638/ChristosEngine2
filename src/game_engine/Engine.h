#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include <rend/rend.h>

namespace game_engine
{
	class Entity;
	class Keyboard;

	class Engine
	{
		private:
			std::vector<std::shared_ptr<Entity>> entities;
			bool isRunning;
			std::shared_ptr<Keyboard> keyboard;
			std::weak_ptr<Engine> self;

			SDL_Window* window;
			std::shared_ptr<rend::Context> context;
		public:
			void Start();
			void End();
			std::shared_ptr<Entity> AddEntity();
			std::shared_ptr<Keyboard> GetKeyboard();
			static std::shared_ptr<Engine> Init();
			SDL_Window* GetWindow();
			std::shared_ptr<rend::Context> GetContext();
			
	};
}

#endif // !ENGINE_H_