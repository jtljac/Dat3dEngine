#include <iostream>
#include <Engine/Utilities/Logging.h>
#include <Rendering/Vulkan/VulkanRenderer.h>
#include <Engine/AssetManager/AssetManager.h>
#include <Engine/AssetManager/Factories/VertShaderFactory.h>
#include <Engine/AssetManager/Factories/FragShaderFactory.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>

VulkanRenderer theRenderer;




int main() {
	AssetManager assMan;
	assMan.registerFactory<FragShader>(new FragShaderFactory());
	assMan.registerFactory<VertShader>(new VertShaderFactory());

	theRenderer.initialise(800, 600, "Vulkan Test", &assMan);

	// Main Loop
	while (!theRenderer.windowWantsToClose()) {
		glfwPollEvents();
		theRenderer.drawFrame();
	}

	theRenderer.cleanup();

	return 0;
}