#ifndef _MESH_H_
#define _MESH_H_

#include <rend/rend.h>

namespace game_engine
{
	class Face;

	class Mesh
	{
	private:
		std::vector<Face> faces;
		bool dirty;

		//std::shared_ptr<Mesh> Create();
		std::shared_ptr<Mesh> Load(std::string _path);
	public:
		~Mesh();
		void AddFace(Face &_face);
		GLuint GetID();
	};
}

#endif // !_MESH_H_
