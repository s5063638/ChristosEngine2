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
		void OnInit();
		void SetPosition(rend::vec3 _pos);
		void SetRotation(rend::vec3 _rot);
		void SetScale(rend::vec3 _scale);

		rend::vec3 GetPosition();
		rend::vec3 GetRotation();
		rend::vec3 GetScale();;
		
		void Translate(rend::vec4 _pos);
		void Rotate(rend::vec3 _rot);

	};
}
#endif // !_TRANSFORM_H_
