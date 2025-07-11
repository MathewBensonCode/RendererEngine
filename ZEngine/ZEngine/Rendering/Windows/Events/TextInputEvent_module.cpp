export module ZEngine.Rendering:Windows.Events.TextInputEvent;

import std;
import ZEngine.Core.CoreEvent;

export namespace ZEngine::Rendering::Windows::Events
{

    class TextInputEvent : public Core::CoreEvent
    {
    public:
        TextInputEvent(std::string_view content) : m_text(content) {}

        virtual Core::EventType GetType() const override
        {
            return Core::EventType::TextInput;
        }

        virtual int GetCategory() const override
        {
            return Core::EventCategory::Keyboard | Core::EventCategory::Input;
        }

        virtual std::string ToString() const override
        {
            return std::format("TextInputEvent : {0}", m_text);
        }

        std::string_view GetText() const
        {
            return m_text;
        }

    protected:
        std::string m_text;
    };
} // namespace ZEngine::Windows::Events
