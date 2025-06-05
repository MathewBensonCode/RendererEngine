module;
#include <vulkan/vulkan.hpp>

export module ZEngine.Rendering.Specifications.TextureSpecification;

import std;
import ZEngine.Rendering.Specifications.FormatSpecification;
import ZEngine.ZEngineDef;

export namespace ZEngine::Rendering::Specifications
{
    struct TextureSpecification
    {
        bool          IsUsageSampled    = true;
        bool          IsUsageStorage    = false;
        bool          IsUsageTransfert  = true;
        bool          PerformTransition = true;
        bool          IsCubemap         = false;
        std::uint32_t      Width             = 0;
        std::uint32_t      Height            = 0;
        std::uint32_t      BytePerPixel      = 4;
        std::uint32_t      LayerCount        = 1;
        ImageFormat   Format            = ImageFormat::UNDEFINED;
        LoadOperation LoadOp            = LoadOperation::CLEAR;
        const void*   Data              = nullptr;
    };

    enum class ImageBufferUsageType
    {
        CUBEMAP = 0,
        SINGLE_2D_IMAGE,
        SINGLE_3D_IMAGE,
        ARRAYOF_2D_IMAGE
    };

    struct Image2DBufferSpecification
    {
        std::uint32_t              Width;
        std::uint32_t              Height;
        ImageViewTypeEnum     ImageViewType = ImageViewTypeEnum::TYPE_2D;
        ImageBufferUsageType  BufferUsageType;
        VkFormat              ImageFormat;
        VkImageUsageFlags     ImageUsage;
        VkImageAspectFlagBits ImageAspectFlag;
        std::uint32_t              LayerCount      = 1U;
        ImageCreateFlagEnum   ImageCreateFlag = ImageCreateFlagEnum::NONE;
    };

} // namespace ZEngine::Rendering::Specifications
