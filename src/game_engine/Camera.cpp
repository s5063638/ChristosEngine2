#include "Camera.h"
#include "Transform.h"
#include "Entity.h"

namespace game_engine
{
	void Camera::OnInit()
	{
		//GetEngine()->camera = GetEntity()->GetComponent<Camera>();
	}
	rend::mat4 Camera::GetProjection()
	{
		rend::mat4 rtn = rend::perspective(rend::radians(45.0f), 1.0f, 0.01f, 500.0f);

		return rtn;
	}
	rend::mat4 Camera::GetView()
	{	
		rend::mat4 rtn = rend::inverse(GetTransform()->GetModel());

		return rtn;
	}
}