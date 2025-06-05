module;
#include <vulkan/vulkan.h>

export module ZEngine.Rendering.Renderers.GraphicRenderer;

import std;
import ZEngine.Rendering.Cameras.Camera;
import ZEngine.Hardwares.VulkanDevice;
import ZEngine.Helpers.ThreadSafeQueue;
import ZEngine.Rendering.Primitives.Fence;
import ZEngine.Rendering.Primitives.Semaphore;
import ZEngine.Rendering.Renderers.RenderPasses.RenderPass;
import ZEngine.Rendering.Renderers.RenderGraph;
import ZEngine.Rendering.Textures.Texture;
import ZEngine.Rendering.Renderers.ImGUIRenderer;

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
        size_t                               BufferSize;
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
        Hardwares::UniformBufferSetHandle SceneCameraBufferHandle      = {};
        Textures::TextureHandle           FrameColorRenderTarget       = {};
        Textures::TextureHandle           FrameDepthRenderTarget       = {};
        Hardwares::VulkanDevice*          Device                       = nullptr;
        ZRawPtr(Renderers::ImGUIRenderer) ImguiRenderer                = nullptr;
        ZRawPtr(Renderers::RenderGraph) RenderGraph                    = nullptr;
        ZRawPtr(Renderers::AsyncResourceLoader) AsyncLoader            = nullptr;
        Helpers::ThreadSafeQueue<ResizeRequest> EnqueuedResizeRequests = {};

        void                                    Initialize(Hardwares::VulkanDevice* device);
        void                                    Deinitialize();
        void                                    Update();
        void                                    DrawScene(Hardwares::CommandBuffer* const command_buffer, Cameras::Camera* const camera, Scenes::SceneRawData* const scene);
        Textures::TextureHandle                 GetFrameOutput();

        ZRawPtr(RenderPasses::RenderPass) CreateRenderPass(const Specifications::RenderPassSpecification& spec);
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
        std::vector<uint8_t>                           m_temp_buffer{};
        Hardwares::CommandBufferManager                m_buffer_manager{};
        Helpers::ThreadSafeQueue<UpdateTextureRequest> m_update_texture_request;
        Helpers::ThreadSafeQueue<TextureFileRequest>   m_file_requests;
        Helpers::ThreadSafeQueue<TextureUploadRequest> m_upload_requests;
    };
} // namespace ZEngine::Rendering::Renderers
