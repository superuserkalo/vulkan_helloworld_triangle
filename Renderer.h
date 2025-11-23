#pragma once

namespace SDLManager {
    class SDL;
}

namespace Renderer {
    
    struct VulkanExtensionInfo {
        Uint32 extensionCount;
        const char* const* extensions;
    };


    class VulkanRenderer {
    public:
        int VulkanSetup(SDLManager::SDL& sdl);
        VulkanExtensionInfo GetExtensionInfo() const;
        VkInstance CreateVulkanInstance();
        VkSurfaceKHR CreateVulkanSurface();
        //int VulkanCleanUp();
   
    private:
        int GetVulkanExtensions(SDLManager::SDL& sdl);
        Uint32 extensionCount = 0;
        const char* const* extensions = nullptr;
        //vkDestroySurfaceKHR(instance, surface, nullptr);
        //vkDestroyInstance(instance, nullptr);
    };
}