#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <vector>
#include <SDL2/SDL.h>

namespace game_engine
{
	class Keyboard
	{
		private:
			std::vector<SDL_Keycode> keys;
		public:
			bool GetKey(SDL_Keycode _keycode);
			bool GetKeyDown(SDL_Keycode _keycode);
			bool GetKeyUp(SDL_Keycode _keycode);

			void AddKey(SDL_Keycode _key);
			void RemoveKey(SDL_Keycode _key);
	};
}

#endif // !_KEYBOARD_H_