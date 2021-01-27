#include "app.hpp"

namespace osc {
	void App::run() {
		while (!window.shouldClose()) {
			glfwPollEvents();
		}
	}
}