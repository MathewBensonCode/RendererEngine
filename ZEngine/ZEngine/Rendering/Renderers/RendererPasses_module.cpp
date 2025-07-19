module;

#define WRITE_BUFFERS_ONCE(frame_index, body)          \
    if (!m_write_once_control.contains(frame_index))   \
    {                                                  \
        body m_write_once_control[frame_index] = true; \
    }

export module ZEngine.Rendering:Renderers.RendererPasses;

import std;
import :Scenes.GraphicScene;
import :Renderers.RenderGraph;
import ZEngine.ZEngineDef;
import ZEngine.Core.Containers.Array;

namespace ZEngine::Rendering::Renderers::RenderPasses
{
    struct RenderPass;
}

export namespace ZEngine::Rendering::Renderers
{

    struct InitialPass : public IRenderGraphCallbackPass
    {
        virtual void Setup(std::string_view name, RenderGraph* const graph) override;
        virtual void Compile(RenderPasses::RenderPass** pass, RenderGraph* const graph, Rendering::Scenes::SceneRawData* const scene) override;
        virtual void Execute(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
        virtual void Render(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Buffers::FramebufferVNext* const framebuffer, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;

    private:
        Core::Containers::Array<float> m_vertex_data = {};
        Devices::VertexBufferSetHandle m_vb_handle   = {};
    };

    struct DepthPrePass : public IRenderGraphCallbackPass
    {
        virtual void Setup(std::string_view name, RenderGraph* const graph) override;
        virtual void Compile(RenderPasses::RenderPass** pass, RenderGraph* const graph, Rendering::Scenes::SceneRawData* const scene) override;
        virtual void Execute(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene_data, RenderPasses::RenderPass* const pass, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
        virtual void Render(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Buffers::FramebufferVNext* const framebuffer, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
    };

    struct SkyboxPass : public IRenderGraphCallbackPass
    {
        virtual void Setup(std::string_view name, RenderGraph* const graph) override;
        virtual void Compile(RenderPasses::RenderPass** pass, RenderGraph* const graph, Rendering::Scenes::SceneRawData* const scene) override;
        virtual void Execute(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene_data, RenderPasses::RenderPass* const pass, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
        virtual void Render(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Buffers::FramebufferVNext* const framebuffer, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;

    private:
        Devices::VertexBufferSetHandle         m_vb_handle   = {};
        Devices::IndexBufferSetHandle          m_ib_handle   = {};
        Textures::TextureHandle                m_env_map     = {};
        Core::Containers::Array<std::uint16_t> m_index_data  = {};
        Core::Containers::Array<float>         m_vertex_data = {};
    };

    struct GridPass : public IRenderGraphCallbackPass
    {
        virtual void Setup(std::string_view name, RenderGraph* const graph) override;
        virtual void Compile(RenderPasses::RenderPass** pass, RenderGraph* const graph, Rendering::Scenes::SceneRawData* const scene) override;
        virtual void Execute(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene_data, RenderPasses::RenderPass* const pass, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
        virtual void Render(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Buffers::FramebufferVNext* const framebuffer, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;

    private:
        Core::Containers::Array<std::uint16_t> m_index_data  = {};
        Core::Containers::Array<float>         m_vertex_data = {};
        Devices::VertexBufferSetHandle         m_vb_handle   = {};
        Devices::IndexBufferSetHandle          m_ib_handle   = {};
    };

    struct GbufferPass : public IRenderGraphCallbackPass
    {
        virtual void Setup(std::string_view name, RenderGraph* const graph) override;
        virtual void Compile(RenderPasses::RenderPass** pass, RenderGraph* const graph, Rendering::Scenes::SceneRawData* const scene) override;
        virtual void Execute(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene_data, RenderPasses::RenderPass* const pass, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
        virtual void Render(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Buffers::FramebufferVNext* const framebuffer, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
    };

    struct LightingPass : public IRenderGraphCallbackPass
    {
        virtual void Setup(std::string_view name, RenderGraph* const graph) override;
        virtual void Compile(RenderPasses::RenderPass** pass, RenderGraph* const graph, Rendering::Scenes::SceneRawData* const scene) override;
        virtual void Execute(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene_data, RenderPasses::RenderPass* const pass, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
        virtual void Render(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Buffers::FramebufferVNext* const framebuffer, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) override;
    };

} // namespace ZEngine::Rendering::Renderers
