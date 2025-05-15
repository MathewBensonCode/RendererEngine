#pragma once
#include <ZEngine/Rendering/Specifications/FormatSpecification.h>
#include <ZEngine/ZEngineDef.h>

namespace ZEngine::Rendering::Specifications
{
    struct TextureSpecification
    {
        bool          IsUsageSampled    = true;
        bool          IsUsageStorage    = false;
        bool          IsUsageTransfert  = true;
        bool          PerformTransition = true;
        bool          IsCubemap         = false;
        uint32_t      Width             = 0;
        uint32_t      Height            = 0;
        uint32_t      BytePerPixel      = 4;
        uint32_t      LayerCount        = 1;
        ImageFormat   Format            = ImageFormat::UNDEFINED;
        LoadOperation LoadOp            = LoadOperation::CLEAR;
        const void*   Data              = nullptr;
    };
} // namespace ZEngine::Rendering::Specifications
