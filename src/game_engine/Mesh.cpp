#include "Mesh.h"
#include "Engine.h"
#include <iostream>
#include <fstream>

namespace game_engine
{
	std::shared_ptr<Mesh> Mesh::Load(std::string _path, std::shared_ptr<Engine> _engine)
	{
		std::shared_ptr<Mesh> rtn;

		std::ifstream f(_path);

		std::string obj;

		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		rtn->internalMesh = _engine->GetContext()->createMesh();
		rtn->internalMesh->parse(obj);

		return rtn;
	}
}