#include "Transform.h"

namespace game_engine
{
	void Transform::OnInit()
	{
		position = rend::vec3(0, 0, 0);
		rotation = rend::vec3(0, 0, 0);
		scale = rend::vec3(1, 1, 1);
	}
	rend::mat4 Transform::GetModel()
	{
		rend::mat4 rtn = rend::mat4(1.0f);

		rtn = rend::translate(rtn, position);

		rtn = rend::rotate(rtn, rotation.x, rend::vec3(1, 0, 0));
		rtn = rend::rotate(rtn, rotation.y, rend::vec3(0, 1, 0));
		rtn = rend::rotate(rtn, rotation.z, rend::vec3(0, 0, 1));

		rtn = rend::scale(rtn, scale);

		return rtn;
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
	rend::vec3 Transform::GetPosition()
	{
		return position;
	}
	rend::vec3 Transform::GetRotation()
	{
		return rotation;
	}
	rend::vec3 Transform::GetScale()
	{
		return scale;
	}
	void Transform::Translate(rend::vec4 _pos)
	{
		rend::mat4 modMat = GetModel();
		rend::vec4 movement = modMat * _pos;

		position += rend::vec3(movement.x, movement.y, movement.z);
	}
	void Transform::Rotate(rend::vec3 _rot)
	{
		rotation += _rot;
	}
}