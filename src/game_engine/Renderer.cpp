#include "Renderer.h"

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

	void Renderer::OnInit()
	{
		window = GetEngine()->GetWindow();
		context = GetEngine()->GetContext();

		shader = context->createShader();
		shader->setSource(src);

		shape = context->createBuffer();

		shape->add(rend::vec2(0, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));
	}

	void Renderer::OnDisplay()
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

		// getTransform()
		//shader->setAttribute("u_Projection", getEntity()->getCore()->getWindow() / or getCamera()->getProjectionMatrix());
		//shader->setAttribute("u_Model", getEntity()->getComponent<Transform>()->getModelMatrix());
		shader->setAttribute("a_Position", shape);
		shader->render();

		SDL_GL_SwapWindow(window);
	}
}

