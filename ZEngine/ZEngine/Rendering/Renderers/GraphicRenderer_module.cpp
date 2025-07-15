module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Renderers.GraphicRenderer;

import std;
import :Cameras.Camera;
import :Textures.Texture;
import :Devices.VulkanDevice;
import ZEngine.Helpers.ThreadSafeQueue;
import ZEngine.Helpers.IntrusivePtr;


namespace ZEngine::Rendering::Renderers{
    struct RenderGraph;
    struct ImGUIRenderer;
}

namespace ZEngine::Rendering::Renderers::RenderPasses{
        struct RenderPass;
}

namespace ZEngine::Rendering::Scenes{
    struct SceneRawData;
}

namespace ZEngine::Rendering::Specifications{
    struct RenderPassSpecification;
}

export namespace ZEngine::Rendering::Renderers
{
    struct ResizeRequest
    {
        std::uint32_t Width;
        std::uint32_t Height;
    };

    struct UpdateTextureRequest
    {
        Textures::TextureHandle Handle;
        Textures::Texture*      Texture;
    };

    struct TextureFileRequest
    {
        std::string             Filename;
        Textures::TextureHandle Handle;
    };

    struct TextureUploadRequest
    {
        std::size_t                               BufferSize;
        Textures::TextureHandle              Handle;
        Specifications::TextureSpecification TextureSpec;
    };

    struct AsyncResourceLoader;
    struct GraphicRenderer
    {
        GraphicRenderer();
        ~GraphicRenderer();

        const char*                       FrameDepthRenderTargetName   = "g_frame_depth_render_target";
        const char*                       FrameColorRenderTargetName   = "g_frame_color_render_target";
        Devices::UniformBufferSetHandle   SceneCameraBufferHandle      = {};
        Textures::TextureHandle           FrameColorRenderTarget       = {};
        Textures::TextureHandle           FrameDepthRenderTarget       = {};
        Devices::VulkanDevice*            Device                       = nullptr;
        Renderers::ImGUIRenderer* ImguiRenderer                = nullptr;
        Renderers::RenderGraph* RenderGraph                    = nullptr;
        Renderers::AsyncResourceLoader* AsyncLoader            = nullptr;
        Helpers::ThreadSafeQueue<ResizeRequest> EnqueuedResizeRequests = {};

        void                                    Initialize(Devices::VulkanDevice* device);
        void                                    Deinitialize();
        void                                    Update();
        void                                    DrawScene(Devices::CommandBuffer* const command_buffer, Cameras::Camera* const camera, Scenes::SceneRawData* const scene);
        Textures::TextureHandle                 GetFrameOutput();

        RenderPasses::RenderPass* CreateRenderPass(const Specifications::RenderPassSpecification& spec);
        Textures::TextureHandle CreateTexture(const Specifications::TextureSpecification& spec);
        Textures::TextureHandle CreateTexture(std::uint32_t width, std::uint32_t height);
        Textures::TextureHandle CreateTexture(std::uint32_t width, std::uint32_t height, float r, float g, float b, float a);
    };

    struct AsyncResourceLoader
    {
        GraphicRenderer*        Renderer = nullptr;

        void                    Initialize(GraphicRenderer* renderer);
        void                    Run();
        void                    Shutdown();

        void                    EnqueueTextureRequest(std::string_view file, const Textures::TextureHandle& handle);
        Textures::TextureHandle LoadTextureFile(std::string_view filename);
        Textures::TextureHandle LoadTextureFileSync(std::string_view filename);

    private:
        std::atomic_bool                               m_cancellation_token{false};
        std::mutex                                     m_mutex;
        std::condition_variable                        m_cond;
        std::vector<std::uint8_t>                      m_temp_buffer{};
        Devices::CommandBufferManager                  m_buffer_manager{};
        Helpers::ThreadSafeQueue<UpdateTextureRequest> m_update_texture_request;
        Helpers::ThreadSafeQueue<TextureFileRequest>   m_file_requests;
        Helpers::ThreadSafeQueue<TextureUploadRequest> m_upload_requests;
    };
} // namespace ZEngine::Rendering::Renderers
