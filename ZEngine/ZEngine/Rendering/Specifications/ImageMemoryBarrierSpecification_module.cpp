module;

#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Specifications.ImageMemoryBarrierSpecification;

import std;
import :Specifications.FormatSpecification;

export namespace ZEngine::Rendering::Specifications
{
    struct ImageMemoryBarrierSpecification
    {
        ImageLayout             OldLayout;
        ImageLayout             NewLayout;
        VkImage                 ImageHandle;
        VkAccessFlags           SourceAccessMask;
        VkAccessFlags           DestinationAccessMask;
        VkImageAspectFlagBits   ImageAspectMask;
        VkPipelineStageFlagBits SourceStageMask;
        VkPipelineStageFlagBits DestinationStageMask;
        std::uint32_t                LayerCount             = 1;
        std::uint32_t                SourceQueueFamily      = VK_QUEUE_FAMILY_IGNORED;
        std::uint32_t                DestinationQueueFamily = VK_QUEUE_FAMILY_IGNORED;
    };
} // namespace ZEngine::Rendering::Specifications
