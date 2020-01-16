#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"
#include <vector>

namespace game_engine
{
	void BoxCollider::OnInit()
	{
		size = rend::vec3(1.0f, 1.0f, 1.0f);
		moveable = false;
	}
	bool BoxCollider::IsColliding(rend::vec3 _position, rend::vec3 _size)
	{
		rend::vec3 a = GetTransform()->GetPosition() + offset;
		rend::vec3& as = size;
		rend::vec3& b = _position;
		rend::vec3& bs = _size;

		if (a.x > b.x) // a right of b
		{
			if (a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.x - bs.x > a.x + as.x)
			{
				return false;
			}
		}
		if (a.z > b.z) // a front of b
		{
			if (a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.z - bs.z > a.z + as.z)
			{
				return false;
			}
		}
		if (a.y > b.y) // a above b
		{
			if (a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.y - bs.y > a.y + as.y)
			{
				return false;
			}
		}

		return true;
	}
	rend::vec3 BoxCollider::GetCollisionResponse(rend::vec3 _position, rend::vec3 _size)
	{
		float amount = 0.1f;
		float step = 0.1f;

		while (true)
		{
			if (!IsColliding(_position, _size)) break;
			_position.x += amount;
			if (!IsColliding(_position, _size)) break;
			_position.x -= amount;
			_position.x -= amount;
			if (!IsColliding(_position, _size)) break;
			_position.x += amount;
			_position.z += amount;
			if (!IsColliding(_position, _size)) break;
			_position.z -= amount;
			_position.z -= amount;
			if (!IsColliding(_position, _size)) break;
			_position.z += amount;
			_position.y += amount;
			if (!IsColliding(_position, _size)) break;
			_position.y -= amount;
			_position.y -= amount;
			if (!IsColliding(_position, _size)) break;
			_position.y += amount;
			amount += step;
		}

		return _position;

	}
	void BoxCollider::OnUpdate()
	{
		Collide();
	}
	//! \brief
	//! ```
	//!    std::shared_ptr<BoxCollider> collider = entity->AddComponent<BoxCollider>();
	//!    collider->SetSize(rend::vec3(5.0f, 5.0f, 5.0f));
	//! ```
	//! *An example of how to set the size of a BoxCollider*
	void BoxCollider::SetSize(rend::vec3 _size)
	{
		size = _size;
	}
	//! \brief
	//! ```
	//!    std::shared_ptr<BoxCollider> collider = entity->AddComponent<BoxCollider>();
	//!    collider->SetOffset(rend::vec3(2.0f, 1.0f, 1.0f));
	//! ```
	//! *An example of how to set the offset of a BoxCollider*
	void BoxCollider::SetOffset(rend::vec3 _offset)
	{
		offset = _offset;
	}
	void BoxCollider::Collide()
	{
		std::vector<std::shared_ptr<Entity>> tempEntites = GetEngine()->GetEntites();
		std::vector<std::shared_ptr<Entity>> colliderEntites;

		rend::vec3 np = GetTransform()->GetPosition() + offset;

		for (auto it = tempEntites.begin(); it < tempEntites.end(); it++)
		{
			if ((*it)->CheckComponent<BoxCollider>() == true)
			{
				colliderEntites.push_back(*it);
			}
		}

		for (auto it = colliderEntites.begin(); it < colliderEntites.end(); it++)
		{
			if (*it == GetEntity())
			{
				continue;
			}

			std::shared_ptr<BoxCollider> box = (*it)->GetComponent<BoxCollider>();

			if (moveable == true)
			{
				rend::vec3 sp = box->GetCollisionResponse(np, size);
				np = sp;
				np -= offset;

				GetTransform()->SetPosition(np);
				lastPos = np;
			}
		}
	}
	//! \brief
	//! ```
	//!    std::shared_ptr<BoxCollider> collider = entity->AddComponent<BoxCollider>();
	//!    collider->SetMoveable(true);
	//! ```
	//! *An example of how to make the BoxCollider moveable*
	void BoxCollider::SetMoveable(bool _move)
	{
		moveable = _move;
	}
}