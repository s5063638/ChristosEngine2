#ifndef _MESH_H_
#define _MESH_H_

#include <rend/rend.h>
#include "Resource.h"

namespace game_engine
{
	class Engine;

	class Mesh : public Resource
	{
	private:
		std::shared_ptr<rend::Mesh> internalMesh;
	public:
		void Load(std::string _path);
	};
}

#endif // !_MESH_H_
