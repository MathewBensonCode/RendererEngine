module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering.Renderers.Pipelines.RendererPipeline;

import std;

import ZEngine.Hardwares.VulkanDevice;
import ZEngine.Rendering.Shaders.Shader;
import ZEngine.Rendering.Specifications.GraphicRendererPipelineSpecification;

import ZEngine.ZEngineDef;

export namespace ZEngine::Rendering::Renderers::Pipelines
{
    struct GraphicPipeline
    {
    public:
        GraphicPipeline() {}
        ~GraphicPipeline() {}

        Specifications::GraphicRendererPipelineSpecification Specification = {};
        Shaders::Shader*                                     Shader        = nullptr;
        Hardwares::VulkanDevice*                             Device        = nullptr;
        VkPipeline                                           Handle        = VK_NULL_HANDLE;
        VkPipelineLayout                                     Layout        = VK_NULL_HANDLE;

        void                                                 Initialize(Hardwares::VulkanDevice* device, Specifications::GraphicRendererPipelineSpecification&& spec);
        void                                                 Bake();
        void                                                 Dispose();
    };
} // namespace ZEngine::Rendering::Renderers::Pipelines
