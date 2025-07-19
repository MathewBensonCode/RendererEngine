module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Textures.Texture;

import std;
import :Specifications.TextureSpecification;
import ZEngine.Helpers.HandleManager;
import ZEngine.Helpers.IntrusivePtr;

namespace ZEngine::Rendering::Devices
{
    struct Image2DBuffer;
}

namespace ZEngine::Rendering::Textures
{
    struct Texture
    {
        Texture() = default;
        ~Texture();

        void                                 Initialize(const Specifications::TextureSpecification& spec, Devices::Image2DBuffer* const buffer);

        bool                                 IsDepthTexture = false;
        std::uint32_t                        Width          = 1;
        std::uint32_t                        Height         = 1;
        std::uint32_t                        BytePerPixel   = 0;
        VkDeviceSize                         BufferSize     = 0;
        Specifications::TextureSpecification Specification  = {};
        Devices::Image2DBuffer*              ImageBuffer    = nullptr;

        void                                 Dispose();
    };

    using TextureHandle        = Helpers::Handle<Texture>;
    using TextureHandleManager = Helpers::HandleManager<Texture>;

    /*
     * To do : Should be deprecated
     */
    Texture* CreateTexture(const char* path);
    Texture* CreateTexture(unsigned int width, unsigned int height);
    Texture* CreateTexture(unsigned int width, unsigned int height, float r, float g, float b, float a);
} // namespace ZEngine::Rendering::Textures
