#pragma once
#include <ZEngine/Core/Containers/Array.h>
#include <ZEngine/Core/Containers/HashMap.h>
#include <ZEngine/Rendering/Specifications/GraphicRendererPipelineSpecification.h>
#include <ZEngine/Rendering/Specifications/TextureSpecification.h>
#include <ZEngine/Rendering/Textures/Texture.h>

namespace ZEngine::Rendering::Specifications
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
