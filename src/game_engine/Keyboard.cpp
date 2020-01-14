#include "Keyboard.h"

namespace game_engine
{
	//! \brief
	//! ```
	//!    if (GetKeyboard()->GetKeyUp(SDLK_w))
	//!    {
	//!        
	//!    }
	//! ```
	//! *An example of checking if the W key has been released*
	bool Keyboard::GetKeyUp(SDL_Keycode _keycode)
	{
		return true;
	}
	//! \brief
	//! ```
	//!    if (GetKeyboard()->GetKey(SDLK_w))
	//!    {
	//!        
	//!    }
	//! ```
	//! *An example of checking if the W key has been pressed*
	bool Keyboard::GetKey(SDL_Keycode _keycode)
	{
		return true;
	}
	//! \brief
	//! ```
	//!    if (GetKeyboard()->GetKeyDown(SDLK_w))
	//!    {
	//!        
	//!    }
	//! ```
	//! *An example of checking if the W key has been down*
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