export module Tetragrama.Components.Events.SceneViewportUnfocusedEvent;

namespace Tetragrama::Components::Event
{

    class SceneViewportUnfocusedEvent : public UIComponentEvent
    {
    public:
        SceneViewportUnfocusedEvent()  = default;
        ~SceneViewportUnfocusedEvent() = default;

        EVENT_TYPE(SceneViewportUnfocused)

        virtual ZEngine::Core::EventType GetType() const override
        {
            return GetStaticType();
        }

        virtual int GetCategory() const override
        {
            return GetStaticCategory();
        }
    };
} // namespace Tetragrama::Components::Event
