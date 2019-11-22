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
		std::vector<std::shared_ptr<Resource>> resources;
	public:
		template <typename T>
		std::shared_ptr<T> Load(std::string _path, std::shared_ptr<Engine> _engine)
		{

		}
	};
}

#endif // !_RESOURCES_H_
