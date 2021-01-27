#include "window.hpp"
#include "pipeline.hpp"
#include "device.hpp"
#include "SwapChain.hpp"


namespace osc {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		void run();
	private:
		OSCwindow window{ WIDTH, HEIGHT, "HelloVulkan" };
		Device device{ window };
		SwapChain swapChain{ device, window.getExtent() };
		OSCpipeline pipeline{
			device, 
			"simple_shader.vert.spv", 
			"simple_shader.frag.spv", 
			OSCpipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
	};
}