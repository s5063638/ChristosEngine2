#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include <memory>

namespace game_engine
{
	class Engine;
	class Component;

	class Entity
	{
	private:
		friend class Engine;

		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Engine> engine;
		std::weak_ptr<Entity> self;
	public:
		void Display(); /*!< Method that runs OnDisplay on all Components attached to the current Entity*/
		void Update(); /*!< Method that runs OnDisplay on all Components attached to the current Entity*/

		std::shared_ptr<Engine> GetEngine(); /*!< Shortcut that returns the Engine*/

		///Method that returns a specified Component from the current Entity
		//! \brief
		//! ```
		//!    std::shared_ptr<Entity> ent = engine->AddEntity();
		//!
		//!    ent->GetComponent<Transform>()->SetPosition(rend::vec3(1.5f, 0.0f, -10.0f));
		//! ```
		//! *An example of using GetComponent() to set the position of an entity*
		template <typename T>
		std::shared_ptr<T> GetComponent() 
		{
			for (auto it = components.begin(); it != components.end(); it++) 
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
				if (*it && rtn != NULL)
				{
					return rtn;
				}
			}
		}

		template <typename T>
		bool CheckComponent()
		{
			for (auto it = components.begin(); it != components.end(); it++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
				if (*it == rtn)
				{
					return true;
				}
			}

			return false;
		}

		template <typename T>
		///Adds a specified Component to the current Entity
		//! \brief
		//! ```
		//!    std::shared_ptr<Entity> ent = engine->AddEntity();
		//!
		//!    std::shared_ptr<Renderer> renderer = ent->AddComponent<Renderer>();
		//! ```
		//! *An example of using AddComponent() to add a Renderer component to an entity*
		std::shared_ptr<T> AddComponent() 
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			t->entity = self;
			components.push_back(t);
			t->OnInit();

			return t;
		}
		
		template <typename T, typename A>
		///Adds a specified Component to the current Entity with one specified argument
		std::shared_ptr<T> AddComponent(A _a) 
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			t->entity = self;
			components.push_back(t);
			t->OnInit(_a);

			return t;
		}

		template <typename T, typename A, typename B>
		///Adds a specified Component to the current Entity with two specified arguments
		std::shared_ptr<T> AddComponent(A _a, B _b) 
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			t->entity = self;
			components.push_back(t);
			t->OnInit(_a, _b);

			return t;
		}

		template <typename T, typename A, typename B, typename C>
		///Adds a specified Component to the current Entity with three specified arguments
		std::shared_ptr<T> AddComponent(A _a, B _b, C _c) 
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			t->entity = self;
			components.push_back(t);
			t->OnInit(_a, _b, _c);

			return t;
		}
	};
}
#endif // !_ENTITY_H_
