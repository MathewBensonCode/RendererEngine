module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Specifications.AttachmentSpecification;

import std;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.HashMap;
import :Specifications.FormatSpecification;

export namespace ZEngine::Rendering::Specifications
{

    struct SubPassSpecification
    {
        VkAttachmentReference                          DepthStencilAttachementReference;
        VkSubpassDescription                           SubpassDescription;
        Core::Containers::Array<VkAttachmentReference> ColorAttachementReferences;
    };

    struct ColorAttachment
    {
        ImageFormat    Format;
        LoadOperation  Load;
        StoreOperation Store;
        ImageLayout    Initial;
        ImageLayout    Final;
        ImageLayout    ReferenceLayout;
    };

    struct AttachmentSpecification
    {
        PipelineBindPoint                                        BindPoint;
        Core::Containers::HashMap<uint32_t, ColorAttachment>     ColorsMap;
        Core::Containers::HashMap<uint32_t, VkSubpassDependency> DependenciesMap;
        Core::Containers::Array<VkAttachmentDescription>         ColorAttachements;
        Core::Containers::Array<SubPassSpecification>            SubpassSpecifications;
        Core::Containers::Array<VkSubpassDependency>             SubpassDependencies;
    };
} // namespace ZEngine::Rendering::Specifications
