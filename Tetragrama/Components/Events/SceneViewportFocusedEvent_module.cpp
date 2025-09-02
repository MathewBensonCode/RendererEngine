export module Tetragrama.Components:Events.SceneViewportFocusedEvent;

import :Events.UIComponentEvent;

namespace Tetragrama::Components::Event
{

    class SceneViewportFocusedEvent : public UIComponentEvent
    {
    public:
        SceneViewportFocusedEvent()  = default;
        ~SceneViewportFocusedEvent() = default;

        EVENT_TYPE(SceneViewportFocused)

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
