#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Component.h"
#include <SDL2/SDL.h>
#include <rend/rend.h>

namespace game_engine
{
	class Camera : public Component
	{
	public:
		void OnInit(); 
		rend::mat4 GetProjection(); /*!< Returns the projection matrix of the Camera*/
		rend::mat4 GetView(); /*!< Returns the viewing matrix of the Camera*/
	};
}
#endif // !_CAMERA_H_