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
			void Start(); /*!< A method used to start and run the main game loop*/
			void End(); 
			void SetCam(std::shared_ptr<Camera> _cam); /*!< A method used to set the Main Camera for the game*/

			std::shared_ptr<Entity> AddEntity(); /*!< A method used to add an Entity to the game. Returns the Entity that has been added*/
			std::shared_ptr<Keyboard> GetKeyboard(); /*!< A method that returns the Keyboard for managing input*/
			static std::shared_ptr<Engine> Init(); /*!< A method used to initialise the Engine. Returns the initialised Engine. Should be the first thing done inside main.cpp*/
			SDL_Window* GetWindow(); /*!< Returns the window*/
			std::shared_ptr<rend::Context> GetContext(); /*!<Returns the drawing context */
			std::shared_ptr<Resources> GetResources(); /*!< Returns the engine's resources*/
			std::shared_ptr<Camera> GetCamera(); /*!< Returns the engine's main camera*/
			std::vector<std::shared_ptr<Entity>> GetEntites(); /*!< Returns the vector of entities within the engine*/
	};
}

#endif // !ENGINE_H_