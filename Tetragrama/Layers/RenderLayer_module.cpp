import Tetragrama.Components.Events.SceneTextureAvailableEvent;
import Tetragrama.Components.Events.SceneViewportFocusedEvent;
import Tetragrama.Components.Events.SceneViewportResizedEvent;
import Tetragrama.Components.Events.SceneViewportUnfocusedEvent;
import Tetragrama.Controllers.EditorCameraController;
import Tetragrama.Messengers.Message;
#include <ZEngine/Serializers/GraphicSceneSerializer.h>

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
