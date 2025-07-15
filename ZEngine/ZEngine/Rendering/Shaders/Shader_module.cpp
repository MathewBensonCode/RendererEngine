module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Shaders.Shader;

import std;
import :Specifications.ShaderSpecification;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.HashMap;
import ZEngine.Core.Memory.Allocator;
import ZEngine.ZEngineDef;


namespace ZEngine::Rendering::Shaders
{
    struct Shader
    {
        Shader();
        ~Shader();

        void                                                                                                     Initialize(Devices::VulkanDevice* device, const Specifications::ShaderSpecificationType& spec);
        void                                                                                                     Dispose();
        Specifications::LayoutBindingSpecification                                                               GetLayoutBindingSpecification(const char* name);

        VkDescriptorPool                                                                                         m_descriptor_pool             = VK_NULL_HANDLE;
        Specifications::ShaderSpecificationType                                                                      m_specification               = {};
        Core::Memory::ArenaAllocator                                                                             LocalArena                    = {};

        Core::Containers::Array<Specifications::PushConstantSpecification>                                       PushConstantSpecifications    = {};
        Core::Containers::Array<VkPipelineShaderStageCreateInfo>                                                 ShaderCreateInfos             = {};
        Core::Containers::Array<VkShaderModule>                                                                  ShaderModules                 = {};
        Core::Containers::Array<VkDescriptorSetLayout>                                                           SetLayouts                    = {};
        Core::Containers::Array<Specifications::LayoutBindingSpecification>                                      LayoutBindingSpections        = {};
        Core::Containers::Array<VkPushConstantRange>                                                             PushConstants                 = {};
        Core::Containers::HashMap<uint32_t, Core::Containers::Array<VkDescriptorSet>>                            DescriptorSetMap              = {}; //<set, vec<descriptorSet>>
        Core::Containers::HashMap<uint32_t, VkDescriptorSetLayout>                                               DescriptorSetLayoutMap        = {}; // <set, layout>
        Core::Containers::HashMap<uint32_t, Core::Containers::Array<Specifications::LayoutBindingSpecification>> LayoutBindingSpecificationMap = {};

    private:
        void CreateModule();
        void CreateDescriptorSetLayouts();
        void CreatePushConstantRange();

    private:
        Devices::VulkanDevice* m_device{nullptr};
    };

    Shader* CreateShader(const char* filename, bool defer_program_creation = false);
} // namespace ZEngine::Rendering::Shaders
