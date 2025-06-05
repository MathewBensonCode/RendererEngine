module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering.Pools.CommandPool;

import std;
import ZEngine.Rendering.ResourceTypes;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.ZEngineDef;

namespace ZEngine::Hardwares
{
    struct VulkanDevice;
}

export namespace ZEngine::Rendering::Pools
{
    struct CommandPool : public Helpers::RefCounted
    {
        Hardwares::VulkanDevice* Device = nullptr;

        CommandPool(Hardwares::VulkanDevice* device, Rendering::QueueType type);
        ~CommandPool();

        VkCommandPool        Handle{VK_NULL_HANDLE};
        Rendering::QueueType QueueType;
    };
} // namespace ZEngine::Rendering::Pools
