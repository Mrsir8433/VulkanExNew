#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace osc {
	class OSCwindow {
	public:
		OSCwindow(int width, int height, std::string windowLabel);
		~OSCwindow();

		OSCwindow(const OSCwindow&) = delete;
		OSCwindow& operator=(const OSCwindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }
		VkExtent2D getExtent() {
			return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) };
		}

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		void initWindow();
		

		const int width;
		const int height;

		std::string windowLabel;

		GLFWwindow* window;

	};
}