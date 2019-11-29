#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <iostream>

namespace game_engine
{
	class Engine;
	class Resources;

	class Resource
	{
	private:
		friend class Resources;
		std::string path;
	protected:
		std::weak_ptr<Engine> engine;
	};
}

#endif // !_RESOURCE_H_
