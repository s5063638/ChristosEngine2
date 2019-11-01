#ifndef _TRIANGLE_RENDERER_H_
#define _TRIANGLE_RENDERER_H_

#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <exception>

#include "Component.h"

namespace game_engine
{
	class TriangleRenderer : public Component
	{
		private:
			GLuint positionsVboID;
			GLuint vaoID;
			
			void OnInit();
			void OnDisplay();
		public:

	};
}

#endif // !_TRIANGLE_RENDERER_H_