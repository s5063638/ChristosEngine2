#include "Engine.h"
#include "Entity.h"

namespace game_engine
{
	std::shared_ptr<Engine> Engine::Init()
	{
		std::shared_ptr<Engine> rtn = std::make_shared<Engine>();

		rtn->self = rtn;

		// Create SDL stuff
		window = SDL_CreateWindow("ChristosEngine2",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (!window)
		{
			throw rend::Exception("Failed to create window");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(window);

		if (!glContext)
		{
			throw rend::Exception("Failed to create OpenGL context");
		}

		context = rend::Context::initialize();

		return rtn;
	}

	std::shared_ptr<Entity> Engine::AddEntity()
	{
		std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();

		entities.push_back(newEntity);
		newEntity->engine = self;

		return newEntity;
	}

	std::shared_ptr<Keyboard> Engine::GetKeyboard()
	{
		return keyboard;
	}

	void Engine::Start()
	{
		isRunning = true;

		while(isRunning)
		{
			// Do the SDL event loop.. store keyboard keys in Keyboard class.
			// keyboard->keys.push_back, erase.
			// mouse
			// Resize events, screen size, useful for glm::perspective(w/h) glm::ortho

			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->Update();
				(*it)->Display();
			}
		}
	}

	SDL_Window* Engine::GetWindow()
	{
		return window;
	}

	std::shared_ptr<rend::Context> Engine::GetContext()
	{
		return context;
	}
}
