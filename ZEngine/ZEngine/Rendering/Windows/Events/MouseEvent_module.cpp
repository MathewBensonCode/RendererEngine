export module ZEngine.Rendering:Windows.Events.MouseEvent;

import std;
import :Windows.Inputs.KeyCode;
import ZEngine.Core.CoreEvent;
import ZEngine.ZEngineDef;

export namespace ZEngine::Rendering::Windows::Events
{

    class MouseEvent : public Core::CoreEvent
    {
    public:
        MouseEvent() = default;
        explicit MouseEvent(Inputs::GlfwKeyCode button) : m_button(button) {}

        Inputs::GlfwKeyCode GetButton() const
        {
            return m_button;
        }

    protected:
        Inputs::GlfwKeyCode m_button{0};
    };

    class MouseButtonPressedEvent : public MouseEvent
    {
    public:
        MouseButtonPressedEvent(Inputs::GlfwKeyCode button) : MouseEvent(button) {}

        virtual Core::EventType GetType() const override
        {
            return Core::EventType::MouseButtonPressed;
        }

        virtual int GetCategory() const override
        {
            return Core::EventCategory::Mouse | Core::EventCategory::Input;
        }

        virtual std::string ToString() const override
        {
            return std::format("MouseButtonPressedEvent : {0}", static_cast<int>(m_button));
        }
    };

    class MouseButtonReleasedEvent : public MouseEvent
    {
    public:
        explicit MouseButtonReleasedEvent(Inputs::GlfwKeyCode button) : MouseEvent(button) {}

        virtual Core::EventType GetType() const override
        {
            return Core::EventType::MouseButtonReleased;
        }

        virtual std::string ToString() const override
        {
            return std::format("MouseButtonReleasedEvent : {0}", static_cast<int>(m_button));
        }
    };

    class MouseButtonMovedEvent : public MouseEvent
    {
    public:
        MouseButtonMovedEvent(double xpos, double ypos) : m_xpos(xpos), m_ypos(ypos) {}

        double GetPosX() const
        {
            return m_xpos;
        }

        double GetPosY() const
        {
            return m_ypos;
        }

        virtual Core::EventType GetType() const override
        {
            return Core::EventType::MouseMoved;
        }

        virtual std::string ToString() const override
        {
            return std::format("MouseButtonMovedEvent");
        }

    private:
        double m_xpos{0};
        double m_ypos{0};
    };

    class MouseButtonWheelEvent : public MouseEvent
    {
    public:
        MouseButtonWheelEvent(double offset_x, double offset_y) : m_offset_x(offset_x), m_offset_y(offset_y) {}

        double GetOffetX() const
        {
            return m_offset_x;
        }

        double GetOffetY() const
        {
            return m_offset_y;
        }

        virtual Core::EventType GetType() const override
        {
            return Core::EventType::MouseWheel;
        }

        virtual std::string ToString() const override
        {
            return std::format("MouseWheelEvent : {0}", static_cast<std::int32_t>(m_button));
        }

    private:
        double m_offset_x{0};
        double m_offset_y{0};
    };
} // namespace ZEngine::Rendering::Windows::Events
