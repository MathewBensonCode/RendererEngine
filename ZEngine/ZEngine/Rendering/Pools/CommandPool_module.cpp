module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Pools.CommandPool;

import std;
import :ResourceTypes;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.ZEngineDef;

namespace ZEngine::Rendering::Devices{
    struct VulkanDevice;
}

export namespace ZEngine::Rendering::Pools
{
    struct CommandPool : public Helpers::RefCounted
    {
        Devices::VulkanDevice* Device = nullptr;

        CommandPool(Devices::VulkanDevice* device, Rendering::QueueType type);
        ~CommandPool();

        VkCommandPool        Handle{VK_NULL_HANDLE};
        Rendering::QueueType QueueType;
    };
} // namespace ZEngine::Rendering::Pools
