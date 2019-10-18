#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <vector>

namespace game_engine
{
	class Keyboard
	{
		private:
			std::vector<int> keys;
		public:
			bool GetKey(int keycode);
			bool GetKeyDown(int keycode);
			bool GetKeyUp(int keycode);
	};
}

#endif // !_KEYBOARD_H_