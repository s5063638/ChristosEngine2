#ifndef _BOX_COLLIDER_H_
#define _BOX_COLLIDER_H_

#include "Component.h"
#include <rend/rend.h>

namespace game_engine
{
	class BoxCollider : public Component
	{
	private:
		rend::vec3 size;
		rend::vec3 offset;
		rend::vec3 lastPos;

		bool IsColliding(rend::vec3 _position, rend::vec3 _size);
		rend::vec3 GetCollisionResponse(rend::vec3 _position, rend::vec3 _size);
		void Collide();
	public:
		void OnUpdate();
		void OnInit();
		void SetSize(rend::vec3 _size);
		void SetOffset(rend::vec3 _offset);
	};
}
#endif // !_BOX_COLLIDER_H_