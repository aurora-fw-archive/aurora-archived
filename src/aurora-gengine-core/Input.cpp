#include <Aurora/GEngine/Input.h>

namespace Aurora {
	namespace GEngine {
		Input::Input(Window* parent) {
			for(int i = 0; i < AURORA_GENGINE_INPUT_MAX_KEYS; i++) {
				keys[i] = false;
			}

			for(int i = 0; i < AURORA_GENGINE_INPUT_MAX_BUTTONS; i++) {
				buttons[i] = false;
			}
		}

		Input::~Input() {}
	}
}
