module;

export module ZEngine.Rendering.Specifications.GraphicRendererPipelineSpecification;

import std;

import ZEngine.Core.Containers.Array;
import ZEngine.Rendering.Buffers.Framebuffer;
import ZEngine.Rendering.Renderers.RenderPasses.Attachment;
import ZEngine.Rendering.Specifications.ShaderSpecification;

namespace ZEngine::Rendering::Specifications
{
    struct VertexInputBindingSpecification
    {
        std::uint32_t Stride  = 0;
        std::uint32_t Rate    = 0;
        std::uint32_t Binding = 0;
    };

    struct VertexInputAttributeSpecification
    {
        std::uint32_t    Location = 0;
        std::uint32_t    Binding  = 0;
        std::uint32_t    Offset   = 0;
        ImageFormat Format   = ImageFormat::UNDEFINED;
    };

    struct GraphicRendererPipelineSpecification
    {
        bool                                                       EnableBlending                     = false;
        bool                                                       EnableDepthTest                    = false;
        bool                                                       EnableDepthWrite                   = true;
        std::uint32_t                                                   DepthCompareOp                     = VK_COMPARE_OP_LESS_OR_EQUAL;
        bool                                                       EnableStencilTest                  = false;
        const char*                                                DebugName                          = {};
        ShaderSpecificationType                                        ShaderSpecification                = {};
        Rendering::Buffers::FramebufferVNext*                      TargetFrameBuffer                  = {};
        Renderers::RenderPasses::Attachment*                       Attachment                         = {};
        Core::Containers::Array<VertexInputBindingSpecification>   VertexInputBindingSpecifications   = {};
        Core::Containers::Array<VertexInputAttributeSpecification> VertexInputAttributeSpecifications = {};
    };
} // namespace ZEngine::Rendering::Specifications
