module;

export module ZEngine.Rendering:Specifications.FrameBufferSpecification;

import std;
import ZEngine.Core.Containers.Array;
import :Renderers.RenderPasses.Attachment;

export namespace ZEngine::Rendering::Specifications
{
    struct FrameBufferSpecificationVNext
    {
        float                                ClearColorValue[4] = {0.1f, 0.1f, 0.1f, 1.0f};
        float                                ClearDepthValue[2] = {1.0f, 0.0f};
        std::uint32_t                             Width              = 1;
        std::uint32_t                             Height             = 1;
        std::uint32_t                             Layers             = 1;
        Core::Containers::Array<std::uint32_t>    RenderTargets      = {};
        Renderers::RenderPasses::Attachment* Attachment         = {};
    };

} // namespace ZEngine::Rendering::Specifications
