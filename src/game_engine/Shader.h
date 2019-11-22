#ifndef _SHADER_H_
#define _SHADER_H_

#include <rend/rend.h>
#include "Resource.h"

#include <iostream>

namespace game_engine
{
	class Engine;

	class Shader : Resource
	{
	private:
		std::shared_ptr<rend::Shader> internalShader;
		std::shared_ptr<Shader> Load(std::string _path, std::shared_ptr<Engine> _engine);
	};
}

#endif // !_SHADER_H_