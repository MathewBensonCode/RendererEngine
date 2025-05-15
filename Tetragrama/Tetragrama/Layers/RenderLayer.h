#pragma once
#include <Tetragrama/Components/Events/SceneTextureAvailableEvent.h>
#include <Tetragrama/Components/Events/SceneViewportFocusedEvent.h>
#include <Tetragrama/Components/Events/SceneViewportResizedEvent.h>
#include <Tetragrama/Components/Events/SceneViewportUnfocusedEvent.h>
#include <Tetragrama/EditorCameraController.h>
#include <Tetragrama/Messengers/Message.h>
#include <ZEngine/ZEngine.h>
#include <mutex>
#include <queue>

namespace Tetragrama::Layers
{
    class RenderLayer : public ZEngine::Layers::Layer
    {
    public:
        RenderLayer(std::string_view name = "Rendering layer");

        virtual ~RenderLayer();

        virtual void Initialize() override;
        virtual void Deinitialize() override;
        virtual void Update(ZEngine::Core::TimeStep dt) override;

        virtual void Render() override;

        virtual bool OnEvent(ZEngine::Event::CoreEvent& e) override;

    public:
        std::future<void> SceneRequestResizeMessageHandlerAsync(Messengers::GenericMessage<std::pair<float, float>>&);
        std::future<void> SceneRequestFocusMessageHandlerAsync(Messengers::GenericMessage<bool>&);
        std::future<void> SceneRequestUnfocusMessageHandlerAsync(Messengers::GenericMessage<bool>&);
        std::future<void> SceneRequestNewSceneMessageHandlerAsync(Messengers::EmptyMessage&);
        std::future<void> SceneRequestSelectEntityFromPixelMessageHandlerAsync(Messengers::GenericMessage<std::pair<int, int>>&);

    private:
        ZEngine::Ref<ZEngine::Serializers::GraphicSceneSerializer> m_scene_serializer;
        ZEngine::Ref<EditorCameraController>                       m_editor_camera_controller;
        std::queue<std::function<void(void)>>                      m_deferral_operation;
        std::mutex                                                 m_message_handler_mutex;
        std::mutex                                                 m_mutex;
        std::queue<std::pair<float, float>>                        m_viewport_requested_size_collection;

    private:
        void HandleNewSceneMessage(const Messengers::EmptyMessage&);
        void HandleOpenSceneMessage(const Messengers::GenericMessage<std::string>&);
    };

} // namespace Tetragrama::Layers
