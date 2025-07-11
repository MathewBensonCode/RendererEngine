module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Primitives.Fence;

import std;
import :Devices.VulkanDevice;
import ZEngine.Helpers.IntrusivePtr;

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
        Fence(Devices::VulkanDevice* const device, bool as_signaled = false);
        ~Fence();

        Devices::VulkanDevice* Device = nullptr;
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
}

namespace ZEngine::Rendering::Primitives
{
    Fence::Fence(Devices::VulkanDevice* const device, bool as_signaled)
    {
        Device                                    = device;
        VkFenceCreateInfo frame_fence_create_info = {};
        frame_fence_create_info.sType             = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        if (as_signaled)
        {
            frame_fence_create_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        }

        ZENGINE_VALIDATE_ASSERT(vkCreateFence(Device->LogicalDevice, &frame_fence_create_info, nullptr, &m_handle) == VK_SUCCESS, "Failed to create Fence")
    }

    Fence::~Fence()
    {
        if (!m_handle)
        {
            return;
        }

        Device->EnqueueForDeletion(Rendering::DeviceResourceType::FENCE, m_handle);
        m_handle      = VK_NULL_HANDLE;
        m_fence_state = FenceState::Idle;
    }

    bool Fence::IsSignaled()
    {
        return vkGetFenceStatus(Device->LogicalDevice, m_handle) == VK_SUCCESS;
    }

    bool Fence::Wait(std::uint64_t timeout)
    {
        auto wait = vkWaitForFences(Device->LogicalDevice, 1, &m_handle, VK_TRUE, timeout);
        return wait == VK_SUCCESS;
    }

    void Fence::Reset()
    {
        ZENGINE_VALIDATE_ASSERT(vkResetFences(Device->LogicalDevice, 1, &m_handle) == VK_SUCCESS, "Failed to reset Fence")
        m_fence_state = FenceState::Idle;
    }

    void Fence::SetState(FenceState state)
    {
        m_fence_state = state;
    }

    FenceState Fence::GetState() const
    {
        return m_fence_state;
    }

    VkFence Fence::GetHandle() const
    {
        return m_handle;
    }
} // namespace ZEngine::Rendering::Primitives
