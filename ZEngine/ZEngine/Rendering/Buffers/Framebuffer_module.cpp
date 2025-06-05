module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering.Buffers.Framebuffer;

import std;
import ZEngine.Rendering.Specifications.FrameBufferSpecification;
import ZEngine.Hardwares.VulkanDevice;

export namespace ZEngine::Rendering::Buffers
{
    struct FramebufferVNext
    {
        FramebufferVNext(Hardwares::VulkanDevice* device, const Specifications::FrameBufferSpecificationVNext&);
        FramebufferVNext(Hardwares::VulkanDevice* device, Specifications::FrameBufferSpecificationVNext&&);
        ~FramebufferVNext();

        VkFramebuffer                                        Handle{VK_NULL_HANDLE};

        void                                                 Create();
        void                                                 Resize(std::uint32_t width = 1, std::uint32_t height = 1);
        void                                                 Dispose();
        std::uint32_t                                             GetWidth() const;
        std::uint32_t                                             GetHeight() const;
        Specifications::FrameBufferSpecificationVNext&       GetSpecification();
        const Specifications::FrameBufferSpecificationVNext& GetSpecification() const;

    private:
        Specifications::FrameBufferSpecificationVNext m_specification{};
        Hardwares::VulkanDevice*                      m_device{nullptr};
    };
} // namespace ZEngine::Rendering::Buffers
