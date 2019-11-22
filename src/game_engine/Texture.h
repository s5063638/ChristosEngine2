#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <rend/rend.h>
#include "Resource.h"

namespace game_engine
{
	class Engine;

	class Texture : public Resource
	{
	public:
		std::shared_ptr<rend::Texture> internalTexture;
	private:
		std::shared_ptr<Texture> Load(std::string _path, std::shared_ptr<Engine> _engine);
	};
}

#endif // !TEXTURE_H_