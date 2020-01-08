#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <rend/rend.h>
#include "Resource.h"

namespace game_engine
{
	class Engine;
	class Renderer;

	class Texture : public Resource
	{
	private:
		friend class Renderer;
		std::shared_ptr<rend::Texture> internalTexture;
	public:
		void Load(std::string _path);
	};
}

#endif // !TEXTURE_H_