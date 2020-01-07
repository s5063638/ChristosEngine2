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
	class Resources;
	class Camera;

	class Engine
	{
		private:
			friend class Camera;
			std::vector<std::shared_ptr<Entity>> entities;
			std::shared_ptr<Resources> resources;
			bool isRunning;
			std::shared_ptr<Keyboard> keyboard;
			std::weak_ptr<Engine> self;

			std::shared_ptr<Camera> camera;

			SDL_Window* window;
			std::shared_ptr<rend::Context> context;
		public:
			void Start();
			void End();
			void SetCam(std::shared_ptr<Camera> _cam);

			std::shared_ptr<Entity> AddEntity();
			std::shared_ptr<Keyboard> GetKeyboard();
			static std::shared_ptr<Engine> Init();
			SDL_Window* GetWindow();
			std::shared_ptr<rend::Context> GetContext();
			std::shared_ptr<Resources> GetResources();
			std::shared_ptr<Camera> GetCamera();
	};
}

#endif // !ENGINE_H_