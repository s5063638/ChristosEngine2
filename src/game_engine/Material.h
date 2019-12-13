#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include <rend/rend.h>
#include "Resource.h"

#include <iostream>

namespace game_engine
{
	class Engine;
	class Renderer;

	class Material : public Resource
	{
	private:
		friend class Renderer;
		std::shared_ptr<rend::Shader> internalShader;
	public:
		void Load(std::string _path);
	};
}

#endif // !_SHADER_H_