module ZEngine.Rendering;

import :Textures.Texture;
import :Textures.Texture2D;
import :Specifications.FormatSpecification;
import :Devices.VulkanDevice;

namespace ZEngine::Rendering::Textures
{
    void Texture::Initialize(const Specifications::TextureSpecification& spec, Hardwares::Image2DBuffer* const buffer)
    {
        Specification  = spec;
        ImageBuffer    = buffer;
        Width          = spec.Width;
        Height         = spec.Height;
        BytePerPixel   = spec.BytePerPixel;
        BufferSize     = spec.Width * spec.Height * spec.BytePerPixel * spec.LayerCount;
        IsDepthTexture = (spec.Format == Specifications::ImageFormat::DEPTH_STENCIL_FROM_DEVICE);
    }

    Texture::~Texture()
    {
        Dispose();
    }

    void Texture::Dispose()
    {
        if (ImageBuffer)
        {
            ImageBuffer->Dispose();
            ImageBuffer = nullptr;
        }
    }
} // namespace ZEngine::Rendering::Textures
