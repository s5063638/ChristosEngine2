#include "Mesh.h"
#include "Engine.h"
#include <iostream>
#include <fstream>

namespace game_engine
{
	void Mesh::Load(std::string _path)
	{

		_path += ".obj";

		std::ifstream f(_path);

		if (!f.is_open())
		{
			throw rend::Exception("Failed to open model");
		}

		std::string obj;

		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		internalMesh = engine.lock()->GetContext()->createMesh();
		internalMesh->parse(obj);

	}
}