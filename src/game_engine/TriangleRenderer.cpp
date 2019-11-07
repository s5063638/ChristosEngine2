#include "TriangleRenderer.h"

namespace game_engine
{
	const char* src =
		"\n#ifdef VERTEX\n" \
		"attribute vec2 a_Position;" \
		"" \
		"void main()" \
		"{" \
		"  gl_Position = vec4(a_Position, 0, 1);" \
		"}" \
		"" \
		"\n#endif\n" \
		"\n#ifdef FRAGMENT\n" \
		"" \
		"void main()" \
		"{" \
		"  gl_FragColor = vec4(1, 0, 0, 1);" \
		"}" \
		"" \
		"\n#endif\n";

	void TriangleRenderer::OnInit()
	{
		window = SDL_CreateWindow("ChristosEngine2",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if(!window)
		{
			throw rend::Exception("Failed to create window");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(window);

		if(!glContext)
		{
			throw rend::Exception("Failed to create OpenGL context");
		}

		context = rend::Context::initialize();
		shader = context->createShader();
		shader->setSource(src);

		shape = context->createBuffer();
		shape->add(rend::vec2(0, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));
	}

	void TriangleRenderer::OnDisplay()
	{
		SDL_Event e = {0};

		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				throw rend::Exception("TODO: Should running = false in engine");
			}
		}

		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//shortcuts - getWindow(); getEntity()->getCore()->getWindow();
		// getTransform()
		//shader->setAttribute("u_Projection", getEntity()->getCore()->getWindow() / or getCamera()->getProjectionMatrix());
		//shader->setAttribute("u_Model", getEntity()->getComponent<Transform>()->getModelMatrix());
		shader->setAttribute("a_Position", shape);
		shader->render();

		SDL_GL_SwapWindow(window);
	}
}

