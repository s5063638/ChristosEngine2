#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Component.h"

#include <SDL2/SDL.h>
#include <rend/rend.h>

namespace game_engine
{

	class Transform : public Component
	{
	private:
		rend::vec3 position;
		rend::vec3 rotation;
		rend::vec3 scale;
	public:
		rend::mat4 GetModel();
		void SetPosition(rend::vec3 _pos);
		void SetRotation(rend::vec3 _rot);
		void SetScale(rend::vec3 _scale);

	};
}
#endif // !_TRANSFORM_H_
