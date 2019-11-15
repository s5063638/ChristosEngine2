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
		void Display();
		void Update();

		std::shared_ptr<Engine> GetEngine();

		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			t->entity = self;
			components.push_back(t);
			t->OnInit();

			return t;
		}

		template <typename T, typename A>
		std::shared_ptr<T> AddComponent(A _a)
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			t->entity = self;
			components.push_back(t);
			t->OnInit(_a);

			return t;
		}

		template <typename T, typename A, typename B>
		std::shared_ptr<T> AddComponent(A _a, B _b)
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			t->entity = self;
			components.push_back(t);
			t->OnInit(_a, _b);

			return t;
		}

		template <typename T, typename A, typename B, typename C>
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
