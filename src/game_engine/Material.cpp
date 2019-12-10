#include "Material.h"
#include "Engine.h"

#include <fstream>

namespace game_engine
{
	void Material::Load(std::string _path)
	{
		_path += ".txt";

		std::ifstream f(_path);
		
		if (!f.is_open())
		{
			throw rend::Exception("Failed to open shader");
		}

		std::string shdr;

		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			shdr += line + "\n";
		}

		internalShader = engine.lock()->GetContext()->createShader();
		internalShader->parse(shdr);
	}
}