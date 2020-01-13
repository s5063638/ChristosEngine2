#ifndef _TRIANGLE_RENDERER_H_
#define _TRIANGLE_RENDERER_H_

#include "Component.h"

#include <SDL2/SDL.h>
#include <rend/rend.h>

#include <memory>
#include <exception>

namespace game_engine
{
	class Mesh;
	class Material;
	class Texture;

	class Renderer : public Component
	{
	private:
		SDL_Window* window;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Material> material;
		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Texture> texture;
	public:
		///Method that initialises the Renderer
		void OnInit();

		///Method that displays the Renderer component of the Entity
		void OnDisplay();

		///Method that sets the Mesh
		void SetMesh(std::shared_ptr<Mesh> _mesh);

		///Method that sets the Material
		void SetMaterial(std::shared_ptr<Material> _mat);

		///Method that sets the Texture
		void SetTexture(std::shared_ptr<Texture> _texture);

		///Method that returns the current Mesh
		std::shared_ptr<Mesh> GetMesh();

	};
}

#endif // !_TRIANGLE_RENDERER_H_
