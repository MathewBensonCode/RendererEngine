module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Renderers.Pipelines.RendererPipeline;

import std;
import :Shaders.Shader;
import :Specifications.GraphicRendererPipelineSpecification;
import ZEngine.ZEngineDef;

namespace ZEngine::Rendering::Devices
{
    struct VulkanDevice;
}

export namespace ZEngine::Rendering::Renderers::Pipelines
{
    struct GraphicPipeline
    {
    public:
        GraphicPipeline() {}
        ~GraphicPipeline() {}

        Specifications::GraphicRendererPipelineSpecification Specification = {};
        Shaders::Shader*                                     Shader        = nullptr;
        Devices::VulkanDevice*                               Device        = nullptr;
        VkPipeline                                           Handle        = VK_NULL_HANDLE;
        VkPipelineLayout                                     Layout        = VK_NULL_HANDLE;

        void                                                 Initialize(Devices::VulkanDevice* device, Specifications::GraphicRendererPipelineSpecification&& spec);
        void                                                 Bake();
        void                                                 Dispose();
    };
} // namespace ZEngine::Rendering::Renderers::Pipelines
