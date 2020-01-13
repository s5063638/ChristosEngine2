#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include "Engine.h"

namespace game_engine
{
	class Entity;
	class Engine;
	class Keyboard;
	class Transform;

	class Component
	{
		private:
			friend class Entity;
			std::weak_ptr<Entity> entity;
		public:
			virtual void OnInit(); /*!< Initialises the Component*/
			virtual void OnBegin(); 
			virtual void OnDisplay(); /*!< Used to display in the Renderer component*/
			virtual void OnUpdate(); /*!< Updates the Component*/

			std::shared_ptr<Entity> GetEntity(); /*!< Shortcut that returns the Entity that the current Component is attached to*/
			std::shared_ptr<Engine> GetEngine(); /*!< Shortcut that returns the Engine */
			std::shared_ptr<Keyboard> GetKeyboard(); /*!< Shortcut that returns the Keyboard*/
			std::shared_ptr<Entity> AddEntity(); /*!< Shortcut to add a new Entity to the game*/
			std::shared_ptr<Transform> GetTransform(); /*!< Shortcut that returns the Transform component of the current Entity*/
	};
}
#endif // !_COMPONENT_H_