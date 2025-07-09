module;

export module ZEngine.Rendering:Specifications.RenderPassSpecification;

import std;
import :Specifications.GraphicRendererPipelineSpecification;
import :Specifications.TextureSpecification;
import :Textures.Texture;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.HashMap;

export namespace ZEngine::Rendering::Specifications
{
    struct RenderPassSpecification
    {
        const char*                                                     DebugName               = {};
        bool                                                            SwapchainAsRenderTarget = false;
        Specifications::GraphicRendererPipelineSpecification            PipelineSpecification   = {};
        Core::Containers::Array<Textures::TextureHandle>                Inputs                  = {};
        Core::Containers::HashMap<const char*, Textures::TextureHandle> InputTextures           = {};
        Core::Containers::Array<Specifications::TextureSpecification>   Outputs                 = {};
        Core::Containers::Array<Textures::TextureHandle>                ExternalOutputs         = {};
    };
} // namespace ZEngine::Rendering::Specifications
