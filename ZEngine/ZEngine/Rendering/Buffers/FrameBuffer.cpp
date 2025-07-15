module ZEngine.Rendering;

import std;
import :Devices.VulkanDevice;

using namespace ZEngine::Helpers;
using namespace ZEngine::Rendering::Specifications;

namespace ZEngine::Rendering::Buffers
{
    FramebufferVNext::FramebufferVNext(Devices::VulkanDevice* device, const Specifications::FrameBufferSpecificationVNext& specification) : m_device(device), m_specification(specification)
    {
        Create();
    }

    FramebufferVNext::FramebufferVNext(Devices::VulkanDevice* device, Specifications::FrameBufferSpecificationVNext&& specification) : m_device(device), m_specification(std::move(specification))
    {
        Create();
    }

    FramebufferVNext::~FramebufferVNext()
    {
        Dispose();
    }

    std::uint32_t FramebufferVNext::GetWidth() const
    {
        return m_specification.Width;
    }

    std::uint32_t FramebufferVNext::GetHeight() const
    {
        return m_specification.Height;
    }

    FrameBufferSpecificationVNext& FramebufferVNext::GetSpecification()
    {
        return m_specification;
    }

    const FrameBufferSpecificationVNext& FramebufferVNext::GetSpecification() const
    {
        return m_specification;
    }

    void FramebufferVNext::Create()
    {
        auto                                 scratch = ZEngine::Core::Memory::BeginTempArena(m_device->Arena);

        size_t                               count   = m_specification.RenderTargets.size();
        Core::Containers::Array<VkImageView> views   = {};
        views.init(scratch.Arena, count, count);

        for (int i = 0; i < count; ++i)
        {
            auto index  = m_specification.RenderTargets[i];
            auto handle = m_device->GlobalTextures.ToHandle(index);
            views[i]    = m_device->GlobalTextures.Access(handle)->ImageBuffer->GetImageViewHandle();
        }
        Handle = m_device->CreateFramebuffer(views, m_specification.Attachment->GetHandle(), m_specification.Width, m_specification.Height, m_specification.Layers);

        ZEngine::Core::Memory::EndTempArena(scratch);
    }

    void FramebufferVNext::Resize(std::uint32_t width, std::uint32_t height)
    {
        m_specification.Width  = width;
        m_specification.Height = height;
        Dispose();
        Create();
    }

    void FramebufferVNext::Dispose()
    {
        if (Handle)
        {
            m_device->EnqueueForDeletion(Rendering::DeviceResourceType::FRAMEBUFFER, Handle);
            Handle = VK_NULL_HANDLE;
        }
    }
} // namespace ZEngine::Rendering::Buffers
