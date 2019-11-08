#ifndef _TRIANGLE_RENDERER_H_
#define _TRIANGLE_RENDERER_H_

#include "Component.h"

#include <SDL2/SDL.h>
#include <rend/rend.h>

#include <memory>
#include <exception>

namespace game_engine
{
	class Renderer : public Component
	{
	private:
		SDL_Window* window;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Buffer> shape;

	public:
		void OnInit();
		void OnDisplay();

	};
}

#endif // !_TRIANGLE_RENDERER_H_
