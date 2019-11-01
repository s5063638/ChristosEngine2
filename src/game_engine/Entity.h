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
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Engine> engine;
	public:
		void Display();
		void Update();

		std::shared_ptr<Engine> GetEngine();

		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			components.push_back(t);

			return t;
		}

		template <typename T, typename A>
		std::shared_ptr<T> AddComponent(A _a)
		{
			std::shared_ptr<T> t = std::make_shared<T>(A _a);

			components.push_back(t);

			return t;
		}

		template <typename T, typename A, typename B>
		std::shared_ptr<T> AddComponent(A _a, B _b)
		{
			std::shared_ptr<T> t = std::make_shared<T>(A _a, B _b);

			components.push_back(t);

			return t;
		}

		template <typename T, typename A, typename B, typename C>
		std::shared_ptr<T> AddComponent(A _a, B _b, C _c)
		{
			std::shared_ptr<T> t = std::make_shared<T>(A _a, B _b, C _c);

			components.push_back(t);

			return t;
		}
	};
}
#endif // !_ENTITY_H_