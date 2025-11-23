#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <iostream>
#include <vector>
#include <vulkan/vulkan.h>

#include "SDLManager.h"
#include "Renderer.h"

using namespace SDLManager;
using namespace Renderer;

int VulkanRenderer::VulkanSetup(SDL& sdl) {
    if (GetVulkanExtensions(sdl) != 0) return 1;
    return 0;
}


VkInstance VulkanRenderer::CreateVulkanInstance(){
    VkInstance instance{};
    return instance;
}


VkSurfaceKHR VulkanRenderer::CreateVulkanSurface() {
    VkSurfaceKHR surface{};
    return surface;
}

//int VulkanRenderer::VulkanCleanUp() {}

int VulkanRenderer::GetVulkanExtensions(SDL& sdl) {
    extensions = SDL_Vulkan_GetInstanceExtensions(&extensionCount);
    return 0;
}
 
VulkanExtensionInfo VulkanRenderer::GetExtensionInfo() const {
    return { extensionCount, extensions };
}