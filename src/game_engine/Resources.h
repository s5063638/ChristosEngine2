#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include "Resource.h"
#include <iostream>
#include <vector>

namespace game_engine
{
	class Engine;

	class Resources
	{
	private:
		friend class Engine;
		std::vector<std::shared_ptr<Resource>> resources;
		std::weak_ptr<Engine> engine;
	public:
		template <typename T>
		///Method that loads the specified Resource
		std::shared_ptr<T> Load(std::string _path)
		{
			std::shared_ptr<T> t = std::make_shared<T>();

			resources.push_back(t);

			t->engine = engine;
			t->Load(_path);

			return t;
		}
	};
}
#endif // !_RESOURCES_H_