#include "Keyboard.h"

namespace game_engine
{
	bool Keyboard::GetKeyUp(SDL_Keycode _keycode)
	{
		return true;
	}
	bool Keyboard::GetKey(SDL_Keycode _keycode)
	{
		return true;
	}
	bool Keyboard::GetKeyDown(SDL_Keycode _keycode)
	{
		for (auto it = keys.begin(); it != keys.end(); it++)
		{
			if (*it == _keycode)
			{
				return true;
			}
		}

		return false;
	}
	void Keyboard::AddKey(SDL_Keycode _key)
	{
		for (auto it = keys.begin(); it != keys.end(); it++)
		{
			if (*it == _key)
			{
				return;
			}
		}

		keys.push_back(_key);
	}
	void Keyboard::RemoveKey(SDL_Keycode _key)
	{
		for (auto it = keys.begin(); it != keys.end();)
		{
			if (*it == _key)
			{
				keys.erase(it);
				return;
			}

			it++;
		}
	}
}