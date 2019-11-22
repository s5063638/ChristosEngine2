#include "Shader.h"
#include "Engine.h"

#include <fstream>

namespace game_engine
{
	std::shared_ptr<Shader> Shader::Load(std::string _path, std::shared_ptr<Engine> _engine)
	{
		std::shared_ptr<Shader> rtn;

		std::ifstream f(_path);

		std::string shdr;

		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			shdr += line + "\n";
		}

		rtn->internalShader = _engine->GetContext()->createShader();
		rtn->internalShader->parse(shdr);

		return rtn;
	}
}