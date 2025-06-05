export module ZEngine.Rendering.Renderers.ImGUIRenderer;

import std;
import ZEngine.Rendering.Renderers.RenderGraph;
import ZEngine.Rendering.Renderers.RenderPasses.RenderPass;

export namespace ZEngine::Rendering::Renderers
{
    struct PushConstantData
    {
        float    Scale[2]     = {0};
        float    Translate[2] = {0};
        std::uint32_t TextureId    = 0xFFFFFFFFu;
    };

    struct GraphicRenderer;
    struct ImGUIRenderer
    {
        void Initialize(GraphicRenderer* renderer);
        void Deinitialize();

        void StyleDarkTheme();

        void NewFrame();
        void DrawFrame(std::uint32_t frame_index, Hardwares::CommandBuffer* const command_buffer);

    private:
        GraphicRenderer*                 m_renderer;
        Hardwares::VertexBufferSetHandle m_vertex_buffer_handle;
        Hardwares::IndexBufferSetHandle  m_index_buffer_handle;
        RenderPasses::RenderPass*        m_ui_pass;
    };

} // namespace ZEngine::Rendering::Renderers
