module;

#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Primitives.ImageMemoryBarrier;

import std;
import :Specifications.ImageMemoryBarrierSpecification;

export namespace ZEngine::Rendering::Primitives
{
    struct ImageMemoryBarrier
    {
    public:
        ImageMemoryBarrier(const Specifications::ImageMemoryBarrierSpecification& specification);

        const Specifications::ImageMemoryBarrierSpecification& GetSpecification() const;
        const VkImageMemoryBarrier&                            GetHandle() const;

    private:
        VkImageMemoryBarrier                            m_handle{};
        Specifications::ImageMemoryBarrierSpecification m_specification;
    };
} // namespace ZEngine::Rendering::Primitives
