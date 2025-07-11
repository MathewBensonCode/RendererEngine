export module ZEngine.Rendering:Windows.Events.KeyEvent;

import std;
import ZEngine.Core.CoreEvent;
import :Windows.Inputs.KeyCode;
import ZEngine.ZEngineDef;

export namespace ZEngine::Rendering::Windows::Events
{

    class KeyEvent : public Core::CoreEvent
    {
    public:
        KeyEvent(Inputs::GlfwKeyCode key) : m_keycode(key) {}

        Inputs::GlfwKeyCode GetKeyCode() const
        {
            return m_keycode;
        }

    protected:
        Inputs::GlfwKeyCode m_keycode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(Inputs::GlfwKeyCode key, int repeat_count) : KeyEvent(key), m_repeat_count(repeat_count) {}


        virtual Core::EventType GetType() const override
        {
            return Core::EventType::KeyPressed;
        }

        virtual int GetCategory() const override
        {
            return Core::EventCategory::Keyboard | Core::EventCategory::Input;
        }

        virtual std::string ToString() const override
        {
            return std::format("KeyPressedEvent : {0}, repeated count : {1}", static_cast<int>(m_keycode), static_cast<int>(m_repeat_count));
        }

    protected:
        int m_repeat_count{0};
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(Inputs::GlfwKeyCode key) : KeyEvent(key) {}

        virtual Core::EventType GetType() const override
        {
            return Core::EventType::KeyReleased;
        }

        virtual int GetCategory() const override
        {
            return Core::EventCategory::Keyboard;
        }

        virtual std::string ToString() const override
        {
            return std::format("KeyReleasedEvent : {0}", static_cast<std::int32_t>(m_keycode));
        }
    };
} // namespace ZEngine::Windows::Events
