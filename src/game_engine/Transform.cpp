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

	//! \brief
	//! ```
	//!    entity->GetComponent<Transform>()->SetPosition(rend::vec3(-1.5f, 0.0f, -10.0f));
	//! ```
	//! *An example of setting the position of an entity*
	void Transform::SetPosition(rend::vec3 _pos)
	{
		position = _pos;
	}

	//! \brief
	//! ```
	//!    entity->GetComponent<Transform>()->SetRotation(rend::vec3(0.0f, -4.5f, 0.0f));
	//! ```
	//! *An example of setting the rotation of an entity*
	void Transform::SetRotation(rend::vec3 _rot)
	{
		rotation = _rot;
	}

	//! \brief
	//! ```
	//!    entity->GetComponent<Transform>()->SetScale(rend::vec3(2.0f, 2.0f, 2.0f));
	//! ```
	//! *An example of setting the scale of an entity*
	void Transform::SetScale(rend::vec3 _scale)
	{
		scale = _scale;
	}

	//! \brief
	//! ```
	//!    if(entity->GetComponent<Transform>()->GetTransform()->GetPosition().x > 0.0f);
	//!    {
	//!
	//!    }
	//! ```
	//! *An example of how to get the position of an entity and check it*
	rend::vec3 Transform::GetPosition()
	{
		return position;
	}

	//! \brief
	//! ```
	//!    if(entity->GetComponent<Transform>()->GetTransform()->GetRotation().y < 5.0f);
	//!    {
	//!
	//!    }
	//! ```
	//! *An example of how to get the rotation of an entity and check it*
	rend::vec3 Transform::GetRotation()
	{
		return rotation;
	}

	//! \brief
	//! ```
	//!    if(entity->GetComponent<Transform>()->GetTransform()->GetScale().x <= 2.0f);
	//!    {
	//!
	//!    }
	//! ```
	//! *An example of how to get the scale of an entity and check it*
	rend::vec3 Transform::GetScale()
	{
		return scale;
	}

	//! \brief
	//! ```
	//!    //THIS
	//!    entity->GetComponent<Transform>()->Translate(rend::vec4(0.0f, -0.2f, 0.0f, 0.0f));
	//!
	//!    //OR
	//!    camera->GetTransform()->Translate(rend::vec4(0.0f, 0.0f, 0.25f, 0.0f));
	//! ```
	//! *Examples of how to translate an entity*
	void Transform::Translate(rend::vec4 _pos)
	{
		rend::mat4 modMat = GetModel();
		rend::vec4 movement = modMat * _pos;

		position += rend::vec3(movement.x, movement.y, movement.z);
	}

	//! \brief
	//! ```
	//!    //THIS
	//!    entity->GetComponent<Transform>()->Rotate(rend::vec4(0.0f, -0.2f, 0.0f, 0.0f));
	//!
	//!    //OR
	//!    camera->GetTransform()->Rotate(rend::vec4(0.0f, 0.2f, 0.0f, 0.0f));
	//! ```
	//! *Examples of how to rotate an entity*
	void Transform::Rotate(rend::vec3 _rot)
	{
		rotation += _rot;
	}
}