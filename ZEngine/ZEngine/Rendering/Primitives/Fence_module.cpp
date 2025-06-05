module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering.Primitives.Fence;

import std;
import ZEngine.Helpers.IntrusivePtr;

namespace ZEngine::Hardwares
{
    struct VulkanDevice;
}

export namespace ZEngine::Rendering::Primitives
{
    enum class FenceState
    {
        Idle,
        Submitted,
        Undefined,
    };

    struct Fence
    {
        Fence(Hardwares::VulkanDevice* const device, bool as_signaled = false);
        ~Fence();

        Hardwares::VulkanDevice* Device = nullptr;
        bool                     IsSignaled();

        bool                     Wait(uint64_t timeout = 1000000000);
        void                     Reset();

        void                     SetState(FenceState state);
        FenceState               GetState() const;

        VkFence                  GetHandle() const;

    private:
        FenceState m_fence_state{FenceState::Idle};
        VkFence    m_handle{VK_NULL_HANDLE};
    };
} // namespace ZEngine::Rendering::Primitives
