export module ZEngine.Event.EngineClosedEvent;

import std;
import ZEngine.Core.CoreEvent;

export namespace ZEngine::Event
{
    class EngineClosedEvent : public Core::CoreEvent
    {
    public:
        EngineClosedEvent(std::string_view r) : CoreEvent(), m_reason(r)
        {
            m_name = "EngineClosed";
        }
        ~EngineClosedEvent() = default;

        void SetReason(std::string_view value)
        {
            m_reason = value;
        }

        Core::EventType GetType() const override
        {
            return Core::EventType::EngineClosed;
        }

        int GetCategory() const override
        {
            return Core::EventCategory::Engine;
        }

        std::string ToString() const override
        {
            return std::format("{}: {}", m_name, m_reason);
        }

    private:
        std::string m_reason{};
    };
} // namespace ZEngine::Event
