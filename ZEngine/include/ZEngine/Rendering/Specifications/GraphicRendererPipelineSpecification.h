#pragma once
#include <vulkan/vulkan.h>
#include <Rendering/Specifications/ShaderSpecification.h>
#include <Rendering/Buffers/Framebuffer.h>
#include <ZEngineDef.h>

namespace ZEngine::Rendering::Specifications
{
    struct GraphicRendererPipelineSpecification
    {
        bool                                      EnableBlending    = false;
        bool                                      EnableDepthTest   = true;
        bool                                      EnableStencilTest = false;
        std::string                               DebugName;
        ShaderSpecification                       GraphicRendererPipelineShaderSpecification;
        Ref<Rendering::Buffers::FramebufferVNext> TargetFrameBuffer;
    };
}
