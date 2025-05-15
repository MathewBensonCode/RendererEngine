#pragma once
#include <ZEngine/Rendering/Specifications/GraphicRendererPipelineSpecification.h>
#include <ZEngine/Rendering/Specifications/TextureSpecification.h>
#include <ZEngine/Rendering/Textures/Texture.h>
#include <ZEngine/ZEngineDef.h>
#include <unordered_map>
#include <vector>

namespace ZEngine::Rendering::Specifications
{
    struct RenderPassSpecification
    {
        const char*                                             DebugName               = {};
        bool                                                    SwapchainAsRenderTarget = false;
        Specifications::GraphicRendererPipelineSpecification    PipelineSpecification   = {};
        std::vector<Ref<Textures::Texture>>                     Inputs                  = {};
        std::unordered_map<std::string, Ref<Textures::Texture>> InputTextures           = {};
        std::vector<Specifications::TextureSpecification>       Outputs                 = {};
        std::vector<Ref<Textures::Texture>>                     ExternalOutputs         = {};
    };
} // namespace ZEngine::Rendering::Specifications
