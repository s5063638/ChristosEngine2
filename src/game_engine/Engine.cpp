#include "Engine.h"
#include "Entity.h"
#include "Resources.h"
#include "Transform.h"
#include "Keyboard.h"

namespace game_engine
{
	std::shared_ptr<Engine> Engine::Init()
	{
		std::shared_ptr<Engine> rtn = std::make_shared<Engine>();

		rtn->self = rtn;

		// Create SDL stuff
		rtn->window = SDL_CreateWindow("ChristosEngine2",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (!rtn->window)
		{
			throw rend::Exception("Failed to create window");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(rtn->window);

		if (!glContext)
		{
			throw rend::Exception("Failed to create OpenGL context");
		}

		rtn->context = rend::Context::initialize();

		rtn->resources = std::make_shared<Resources>();

		rtn->resources->engine = rtn;

		rtn->keyboard = std::make_shared<Keyboard>();

		return rtn;
	}

	std::shared_ptr<Entity> Engine::AddEntity()
	{
		std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();

		entities.push_back(newEntity);
		newEntity->engine = self;
		newEntity->self = newEntity;

		newEntity->AddComponent<Transform>();

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
			SDL_Event e;

			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					throw rend::Exception("TODO: Should running = false in engine");
				}
				if(e.type == SDL_KEYDOWN)
				{
					keyboard->AddKey(e.key.keysym.sym);
				}
				if (e.type == SDL_KEYUP)
				{
					keyboard->RemoveKey(e.key.keysym.sym);
				}
			}

			glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->Update();
				(*it)->Display();
			}

			SDL_GL_SwapWindow(window);
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

	std::shared_ptr<Resources> Engine::GetResources()
	{
		return resources;
	}

	std::shared_ptr<Camera> Engine::GetCamera()
	{
		return camera;
	}

	void Engine::SetCam(std::shared_ptr<Camera> _cam)
	{
		camera = _cam;
	}
}