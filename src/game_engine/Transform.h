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
		///Method that returns the model matrix of the current Entity's Transform component
		rend::mat4 GetModel();

		///Method that initialises the Transform component
		void OnInit();

		///Method used to set the Transform position
		void SetPosition(rend::vec3 _pos);

		///Method used to set the Transform rotation
		void SetRotation(rend::vec3 _rot);

		///Method used to set the Transform scale
		void SetScale(rend::vec3 _scale);

		///Method that returns the Transform position
		rend::vec3 GetPosition();

		///Method that returns the Transform position
		rend::vec3 GetRotation();

		///Method that returns the Transform position
		rend::vec3 GetScale();;
		
		///Method that translates the Transform component with a specified vector argument
		void Translate(rend::vec4 _pos);

		///Method that rotates the Transform component with a specified vectore argument
		void Rotate(rend::vec3 _rot);

	};
}
#endif // !_TRANSFORM_H_
