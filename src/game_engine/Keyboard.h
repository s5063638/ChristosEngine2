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
			///Returns true if a specified key has been pressed
			bool GetKey(SDL_Keycode _keycode);
			///Returns true if a specified key has been pressed down
			bool GetKeyDown(SDL_Keycode _keycode);
			///Returns true if a specified key has been released
			bool GetKeyUp(SDL_Keycode _keycode);

			///Method that adds a specified key to the pressed keys vector
			void AddKey(SDL_Keycode _key);

			///Method that removes a specified key from the keys vector 
			void RemoveKey(SDL_Keycode _key);
	};
}

#endif // !_KEYBOARD_H_