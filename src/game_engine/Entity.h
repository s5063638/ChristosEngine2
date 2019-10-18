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

		void Displaty();
		void Update();
	public:
		std::weak_ptr<Engine> GetEngine();

		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			components.push_back(t);

			return t;
		}


		void Display();
	};
}
#endif // !_ENTITY_H_