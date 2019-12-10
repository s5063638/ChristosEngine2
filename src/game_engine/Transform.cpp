#include "Transform.h"

namespace game_engine
{
	rend::mat4 Transform::GetModel()
	{

	}
	void Transform::SetPosition(rend::vec3 _pos)
	{
		position = _pos;
	}
	void Transform::SetRotation(rend::vec3 _rot)
	{
		rotation = _rot;
	}
	void Transform::SetScale(rend::vec3 _scale)
	{
		scale = _scale;
	}
}