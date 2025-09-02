export module Tetragrama.Layers:RenderLayer;

import Tetragrama.Components;
import Tetragrama.Controllers;
import Tetragrama.Messengers;
import ZEngine;

namespace Tetragrama::Layers
{
    class RenderLayer : public ZEngine::Windows::Layers::Layer
    {
    public:
        RenderLayer(const char* name = "Rendering layer");

        virtual ~RenderLayer();

        virtual void Initialize(ZEngine::Core::Memory::ArenaAllocator* arena) override;
        virtual void Deinitialize() override;
        virtual void Update(ZEngine::Core::TimeStep dt) override;

        virtual void Render(ZEngine::Rendering::Renderers::GraphicRenderer* const renderer, ZEngine::Hardwares::CommandBuffer* const command_buffer) override;

        virtual bool OnEvent(ZEngine::Core::CoreEvent& e) override;

    private:
        ZEngine::Helpers::Ref<ZEngine::Serializers::GraphicSceneSerializer> m_scene_serializer;
    };

} // namespace Tetragrama::Layers
