module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering.Renderers.RenderPasses.Attachment;

import std;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.Rendering.Specifications.AttachmentSpecification;

namespace ZEngine::Hardwares
{
    struct VulkanDevice;
}

export namespace ZEngine::Rendering::Renderers::RenderPasses
{
    struct Attachment
    {
        Attachment(Hardwares::VulkanDevice* device, const Specifications::AttachmentSpecification& spec);
        ~Attachment();
        void                                           Dispose();

        VkRenderPass                                   GetHandle() const;
        const Specifications::AttachmentSpecification& GetSpecification() const;

        std::uint32_t                                       GetColorAttachmentCount() const;
        std::uint32_t                                       GetDepthAttachmentCount() const;

    private:
        std::uint32_t                                m_color_attachment_count{0};
        std::uint32_t                                m_depth_attachment_count{0};
        Specifications::AttachmentSpecification m_specification;
        VkRenderPass                            m_handle{VK_NULL_HANDLE};
        Hardwares::VulkanDevice*                m_device{nullptr};
    };
} // namespace ZEngine::Rendering::Renderers::RenderPasses
