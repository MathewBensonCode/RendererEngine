module;
#include <vulkan/vulkan.hpp>

module ZEngine.Rendering;

import std;
import :Primitives.ImageMemoryBarrier;
import :Specifications.ImageMemoryBarrierSpecification;
import :Specifications.FormatSpecification;

namespace ZEngine::Rendering::Primitives
{
    ImageMemoryBarrier::ImageMemoryBarrier(const Specifications::ImageMemoryBarrierSpecification& specification) : m_specification(specification)
    {
        m_handle.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        m_handle.srcQueueFamilyIndex             = specification.SourceQueueFamily;
        m_handle.dstQueueFamilyIndex             = specification.DestinationQueueFamily;
        m_handle.subresourceRange.aspectMask     = specification.ImageAspectMask;
        m_handle.subresourceRange.baseMipLevel   = 0;
        m_handle.subresourceRange.baseArrayLayer = 0;
        m_handle.subresourceRange.layerCount     = m_specification.LayerCount;
        m_handle.subresourceRange.levelCount     = 1;
        m_handle.image                           = specification.ImageHandle;
        m_handle.oldLayout                       = Specifications::ImageLayoutMap[static_cast<std::uint32_t>(specification.OldLayout)];
        m_handle.newLayout                       = Specifications::ImageLayoutMap[static_cast<std::uint32_t>(specification.NewLayout)];
        m_handle.srcAccessMask                   = specification.SourceAccessMask;
        m_handle.dstAccessMask                   = specification.DestinationAccessMask;
    }

    const Specifications::ImageMemoryBarrierSpecification& ImageMemoryBarrier::GetSpecification() const
    {
        return m_specification;
    }

    const VkImageMemoryBarrier& ImageMemoryBarrier::GetHandle() const
    {
        return m_handle;
    }

} // namespace ZEngine::Rendering::Primitives
