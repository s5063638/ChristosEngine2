#include "Texture.h"
#include <SDL2/SDL.h>
#include <sr1/memory>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Engine.h"

namespace game_engine
{
	//! \brief
	//! ```
	//!    std::shared_ptr<Texture> texture = engine->GetResources()->Load<Texture>("../textures/TextureName");
	//! ```
	//! *An example of loading a texture*
	void Texture::Load(std::string _path)
	{
		_path += ".png";

		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char *data = stbi_load(_path.c_str(), &w, &h, &bpp, 3);

		if (!data)
		{
			throw rend::Exception("Failed to open image");
		}

		internalTexture = engine.lock()->GetContext()->createTexture();
		internalTexture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)

			{
				int r = y * w * 3 + x * 3;

				internalTexture->setPixel(x, y, rend::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}

		stbi_image_free(data);
	}
}