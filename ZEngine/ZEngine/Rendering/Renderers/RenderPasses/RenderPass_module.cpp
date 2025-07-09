module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Renderers.RenderPasses.RenderPass;

import std;
import :Buffers.Framebuffer;
import :Renderers.Pipelines.RendererPipeline;
import :Specifications.RenderPassSpecification;
import :Textures.Texture;
import ZEngine.Core.Containers.Array;
import ZEngine.Helpers.IntrusivePtr;

namespace ZEngine::Rendering::Devices{
    struct VulkanDevice;
    struct UniformBufferSetHandle;
    struct StorageBufferSetHandle;
}                       


export namespace ZEngine::Rendering::Renderers::RenderPasses
{
    enum PassInputType
    {
        UNIFORM_BUFFER_SET,
        STORAGE_BUFFER_SET,
        BINDLESS_TEXTURE,
        UNIFORM_BUFFER,
        STORAGE_BUFFER,
        TEXTURE
    };

    struct RenderPass
    {
        RenderPass() {}
        ~RenderPass();

        std::uint32_t                                RenderAreaWidth  = 0;
        std::uint32_t                                RenderAreaHeight = 0;
        Specifications::RenderPassSpecification Specification    = {};
        std::set<std::string>                   Inputs           = {};
        Core::Containers::Array<uint32_t>       RenderTargets    = {};
        Renderers::RenderPasses::Attachment*    Attachment       = {nullptr};
        Pipelines::GraphicPipeline*             Pipeline         = {nullptr};

        void                                    Initialize(Devices::VulkanDevice* device, const Specifications::RenderPassSpecification& specification);
        void                                    Dispose();
        void                                    Bake();
        bool                                    Verify();
        void                                    SetInput(std::string_view key_name, const Devices::UniformBufferSetHandle& buffer);
        void                                    SetInput(std::string_view key_name, const Devices::StorageBufferSetHandle& buffer);
        void                                    SetInput(std::string_view key_name, const Textures::TextureHandle& texture);
        void                                    SetBindlessInput(std::string_view key_name);
        void                                    UpdateInputBinding();
        Renderers::RenderPasses::Attachment* GetAttachment() const;
        void     UpdateRenderTargets();
        std::uint32_t GetRenderAreaWidth() const;
        std::uint32_t GetRenderAreaHeight() const;

    private:
        std::pair<bool, Specifications::LayoutBindingSpecification> ValidateInput(std::string_view key);

    private:
        bool                     m_perform_update{false};
        Devices::VulkanDevice* m_device;
    };

    struct RenderPassBuilder
    {
        Core::Memory::ArenaAllocator*           Arena = nullptr;

        void                                    Initialize(Core::Memory::ArenaAllocator* arena);

        RenderPassBuilder&                      SetName(std::string_view name);
        RenderPassBuilder&                      SetPipelineName(std::string_view name);
        RenderPassBuilder&                      EnablePipelineBlending(bool value);
        RenderPassBuilder&                      EnablePipelineDepthTest(bool value);
        RenderPassBuilder&                      EnablePipelineDepthWrite(bool value);
        RenderPassBuilder&                      PipelineDepthCompareOp(std::uint32_t value);
        RenderPassBuilder&                      SetShaderOverloadMaxSet(std::uint32_t count);
        RenderPassBuilder&                      SetOverloadPoolSize(std::uint32_t count);

        RenderPassBuilder&                      SetInputBindingCount(std::uint32_t count);
        RenderPassBuilder&                      SetStride(std::uint32_t input_binding_index, std::uint32_t value);
        RenderPassBuilder&                      SetRate(std::uint32_t input_binding_index, std::uint32_t value);

        RenderPassBuilder&                      SetInputAttributeCount(std::uint32_t count);
        RenderPassBuilder&                      SetLocation(std::uint32_t input_attribute_index, std::uint32_t value);
        RenderPassBuilder&                      SetBinding(std::uint32_t input_attribute_index, std::uint32_t input_binding_index);
        RenderPassBuilder&                      SetFormat(std::uint32_t input_attribute_index, Specifications::ImageFormat value);
        RenderPassBuilder&                      SetOffset(std::uint32_t input_attribute_index, std::uint32_t offset);

        RenderPassBuilder&                      UseShader(std::string_view name);
        RenderPassBuilder&                      UseRenderTarget(const Textures::TextureHandle& target);
        RenderPassBuilder&                      AddRenderTarget(const Specifications::TextureSpecification& target_spec);
        RenderPassBuilder&                      AddInputAttachment(const Textures::TextureHandle& target);
        RenderPassBuilder&                      AddInputTexture(std::string_view key, const Rendering::Textures::TextureHandle& input);
        RenderPassBuilder&                      UseSwapchainAsRenderTarget();

        Specifications::RenderPassSpecification Detach();

    private:
        Specifications::RenderPassSpecification m_spec{};
    };
} // namespace ZEngine::Rendering::Renderers::RenderPasses
