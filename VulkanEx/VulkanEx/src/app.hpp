#include "window.hpp"
#include "pipeline.hpp"
#include "device.hpp"
#include "SwapChain.hpp"

//std
#include <memory>
#include<vector>


namespace osc {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		App();
		~App();

		App(const App&) = delete;
		App& operator=(const App&) = delete;

		void run();
	private:
	


		OSCwindow window{ WIDTH, HEIGHT, "HelloVulkan" };
		Device device{ window };
		SwapChain swapChain{ device, window.getExtent() };
		
		std::unique_ptr<OSCpipeline> pipeline;

		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers; 

		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();
	};
}