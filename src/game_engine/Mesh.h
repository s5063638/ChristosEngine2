#ifndef _MESH_H_
#define _MESH_H_

#include <rend/rend.h>
#include "Resource.h"

namespace game_engine
{
	class Engine;
	class Renderer;

	class Mesh : public Resource
	{
	private:
		friend class Renderer;
		std::shared_ptr<rend::Mesh> internalMesh;
	public:
		///Method used to load a .obj file into the mesh
		void Load(std::string _path);
	};
}

#endif // !_MESH_H_
