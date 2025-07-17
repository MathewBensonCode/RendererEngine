export module ZEngine.Rendering:Renderers.ImGUIRenderer;

import std;
import :Devices.VulkanDevice;
import :Renderers.RenderPasses.RenderPass;

namespace ZEngine::Rendering::Renderers
{
    struct PushConstantData
    {
        float    Scale[2]     = {0};
        float    Translate[2] = {0};
        std::uint32_t TextureId    = 0xFFFFFFFFu;
    };

    struct GraphicRenderer;
    struct RenderGraph;

    export struct ImGUIRenderer
    {
        void Initialize(GraphicRenderer* renderer);
        void Deinitialize();

        void StyleDarkTheme();

        void NewFrame();
        void DrawFrame(std::uint32_t frame_index, Devices::CommandBuffer* const command_buffer);

    private:
        GraphicRenderer*                 m_renderer;
        Devices::VertexBufferSetHandle m_vertex_buffer_handle;
        Devices::IndexBufferSetHandle  m_index_buffer_handle;
        RenderPasses::RenderPass*        m_ui_pass;
    };

} // namespace ZEngine::Rendering::Renderers
