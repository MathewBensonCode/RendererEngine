export module ZEngine.Rendering:Renderers.RenderGraph;

import std;
import :Buffers.Framebuffer;
import :Scenes.GraphicScene;
import :Specifications.TextureSpecification;
import :Textures.Texture;
import :Devices.VulkanBufferHandles;
import ZEngine.ZEngineDef;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.HashMap;


namespace ZEngine::Rendering::Devices{
    struct CommandBuffer;
}

namespace ZEngine::Rendering::Renderers::RenderPasses{
        struct RenderPass;
}

namespace ZEngine::Rendering::Renderers
{
    struct GraphicRenderer;
    struct RenderGraphBuilder;
    struct RenderPassBuilder;
}

export namespace ZEngine::Rendering::Renderers{
    enum RenderGraphResourceType
    {
        UNDEFINED = -1,
        BUFFER    = 0,
        BUFFER_SET,
        ATTACHMENT,
        TEXTURE,
        REFERENCE
    };

    enum BufferSetCreationType
    {
        INDIRECT,
        UNIFORM,
        STORAGE,
        VERTEX,
        INDEX
    };

    struct RenderGraphResourceInfo
    {
        bool                                 External = false;
        Specifications::TextureSpecification TextureSpec;
        union
        {
            Textures::TextureHandle            TextureHandle;
            Devices::UniformBufferSetHandle  UniformBufferSetHandle;
            Devices::StorageBufferSetHandle  StorageBufferSetHandle;
            Devices::IndirectBufferSetHandle IndirectBufferSetHandle;
            Devices::VertexBufferSetHandle   VertexBufferSetHandle;
            Devices::IndexBufferSetHandle    IndexBufferSetHandle;
        };
    };

    struct RenderGraphResource
    {
        const char*             Name;
        const char*             ProducerNodeName;
        RenderGraphResourceType Type;
        RenderGraphResourceInfo ResourceInfo;
    };

    struct RenderGraphRenderPassInputOutputInfo
    {
        const char*             Name;
        const char*             BindingInputKeyName;
        RenderGraphResourceType Type = RenderGraphResourceType::ATTACHMENT;
    };

    struct RenderGraphRenderPassCreation
    {
        const char*                                                   Name;
        Core::Containers::Array<RenderGraphRenderPassInputOutputInfo> Inputs;
        Core::Containers::Array<RenderGraphRenderPassInputOutputInfo> Outputs;
    };

    struct IRenderGraphCallbackPass
    {
        virtual void Setup(std::string_view name, RenderGraph* const graph)                                                                                                                                                                                   = 0;
        virtual void Compile(RenderPasses::RenderPass** const pass, RenderGraph* const graph, Rendering::Scenes::SceneRawData* const scene)                                                                                                                   = 0;
        virtual void Execute(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph)                                              = 0;
        virtual void Render(std::uint32_t frame_index, Rendering::Scenes::SceneRawData* const scene, RenderPasses::RenderPass* const pass, Buffers::FramebufferVNext* const framebuffer, Devices::CommandBuffer* const command_buffer, RenderGraph* const graph) = 0;
    };

    struct RenderGraphNode
    {
        bool                                 Enabled   = true;
        RenderGraphRenderPassCreation        Creation  = {};
        Core::Containers::Array<const char*> EdgeNodes = {};
        RenderPasses::RenderPass* Handle       = nullptr;
        Buffers::FramebufferVNext* Framebuffer = nullptr;
        IRenderGraphCallbackPass* CallbackPass = nullptr;
    };

    class RenderGraph
    {
    public:
        RenderGraph() {}
        ~RenderGraph() {}

        bool                               MarkAsDirty       = false;
        GraphicRenderer*                   Renderer          = nullptr;
        RenderGraphBuilder*                Builder           = nullptr;
        RenderPassBuilder*                 RenderPassBuilder = nullptr;

        void                               Initialize(Core::Memory::ArenaAllocator* arena, GraphicRenderer* renderer);

        void                               Setup();
        void                               Compile(Rendering::Scenes::SceneRawData* const scene_data);
        void                               Execute(std::uint32_t frame_index, Devices::CommandBuffer* const command_buffer, Rendering::Scenes::SceneRawData* const scene_data);
        void                               Resize(std::uint32_t width, std::uint32_t height);
        void                               Dispose();
        RenderGraphResource&               GetResource(const char*);
        Textures::TextureHandle            GetRenderTarget(const char*);
        Textures::TextureHandle            GetTexture(const char*);
        Devices::StorageBufferSetHandle  GetStorageBufferSet(const char*);
        Devices::VertexBufferSetHandle   GetVertexBufferSet(const char*);
        Devices::IndexBufferSetHandle    GetIndexBufferSet(const char*);
        Devices::UniformBufferSetHandle  GetBufferUniformSet(const char*);
        Devices::IndirectBufferSetHandle GetIndirectBufferSet(const char*);
        RenderGraphNode&                   GetNode(const char*);
        void                               AddCallbackPass(const char* pass_name, IRenderGraphCallbackPass* const pass_callback, bool enabled = true);

    private:
        Core::Containers::Array<const char*>                        m_sorted_nodes;
        Core::Containers::HashMap<const char*, RenderGraphNode>     m_node;
        Core::Containers::HashMap<const char*, RenderGraphResource> m_resource_map;
        friend struct RenderGraphBuilder;
    };

    struct RenderGraphBuilder
    {
        RenderGraphBuilder(RenderGraph& graph) : m_graph(graph) {}

        RenderGraphResource& CreateTexture(const char* name, const Specifications::TextureSpecification& spec);
        RenderGraphResource& CreateTexture(const char* name, const char* filename);
        RenderGraphResource& CreateRenderTarget(const char* name, const Specifications::TextureSpecification& spec);
        RenderGraphResource& AttachBuffer(const char* name, const Devices::StorageBufferSetHandle& buffer);
        RenderGraphResource& AttachBuffer(const char* name, const Devices::UniformBufferSetHandle& buffer);
        RenderGraphResource& AttachTexture(const char* name, const Textures::TextureHandle& texture);
        RenderGraphResource& AttachRenderTarget(const char* name, const Textures::TextureHandle& texture);
        void                 CreateRenderPassNode(const RenderGraphRenderPassCreation&);

        RenderGraphResource& CreateBuffer(const char* name) = delete;
        RenderGraphResource& CreateBufferSet(const char* name, BufferSetCreationType type = BufferSetCreationType::STORAGE);

    private:
        RenderGraph& m_graph;
    };

} // namespace ZEngine::Rendering::Renderers
