#include "window.hpp"
#include <stdexcept>

namespace osc {
	OSCwindow::OSCwindow(int width = 800, int height = 600, std::string windowLabel = "VulkanWindow") :width{ width }, height{ height }, windowLabel{ windowLabel } {
		initWindow();
	}

	OSCwindow::~OSCwindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void OSCwindow::initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowLabel.c_str(), nullptr, nullptr);
	}

	void OSCwindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create window surface");
		}
	}
	
}