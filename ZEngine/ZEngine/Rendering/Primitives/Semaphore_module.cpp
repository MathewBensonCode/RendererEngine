module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Primitives.Semaphore;

import std;
import ZEngine.Helpers.IntrusivePtr;

namespace ZEngine::Rendering::Devices{
    struct VulkanDevice;
}

export namespace ZEngine::Rendering::Primitives
{
    enum class SemaphoreState
    {
        Idle,
        Submitted,
        Undefined,
    };

    struct Semaphore
    {
        Semaphore(Devices::VulkanDevice* const device);
        ~Semaphore();

        Devices::VulkanDevice* Device = nullptr;
        void                     Wait(const uint64_t value, const uint64_t timeout = UINT64_MAX);
        void                     Signal(const uint64_t value);
        VkSemaphore              GetHandle() const;

        void                     SetState(SemaphoreState state);
        SemaphoreState           GetState() const;

    private:
        SemaphoreState m_semaphore_state{SemaphoreState::Idle};
        VkSemaphore    m_handle{VK_NULL_HANDLE};
    };
} // namespace ZEngine::Rendering::Primitives
