export module ZEngine.Rendering:Windows.Events.WindowEvent;

import std;
import ZEngine.Core.CoreEvent;

export namespace ZEngine::Rendering::Windows::Events
{
    class WindowRestoredEvent : public Core::CoreEvent
    {
    public:
        WindowRestoredEvent()
        {
            m_name = "WindowRestored";
        }

        ~WindowRestoredEvent() = default;

        Core::EventType GetType() const override
        {
            return Core::EventType::WindowRestored;
        }

        int GetCategory() const override
        {
            return Core::EventCategory::Engine;
        }

        std::string ToString() const override
        {
            return std::format("WindowRestoredEvent");
        }
    };

    class WindowResizedEvent : public Core::CoreEvent
    {
    public:
        WindowResizedEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height)
        {
            m_name = "WindowResized";
        }

        ~WindowResizedEvent() = default;

        unsigned int GetWidth() const
        {
            return m_width;
        }
        unsigned int GetHeight() const
        {
            return m_height;
        }

        void SetWidth(unsigned int value)
        {
            m_width = value;
        }

        void SetHeight(unsigned int value)
        {
            m_height = value;
        }

        Core::EventType GetType() const override
        {
            return Core::EventType::WindowResized;
        }

        int GetCategory() const override
        {
            return Core::EventCategory::Engine;
        }

        std::string ToString() const override
        {
            return std::format("WindowResizeEvent X: {0}, Y: {1}", m_width, m_height);
        }

    private:
        unsigned int m_width{0};
        unsigned int m_height{0};
    };

    class WindowMinimizedEvent : public Core::CoreEvent
    {
    public:
        WindowMinimizedEvent()
        {
            m_name = "WindowMinimized";
        }
        ~WindowMinimizedEvent() = default;

        Core::EventType GetType() const override
        {
            return Core::EventType::WindowMinimized;
        }

        int GetCategory() const override
        {
            return Core::EventCategory::Engine;
        }

        std::string ToString() const override
        {
            return std::format("WindowMinimizedEvent");
        }
    };

    class WindowMaximizedEvent : public Core::CoreEvent
    {
    public:
        WindowMaximizedEvent()
        {
            m_name = "WindowMaximized";
        }
        ~WindowMaximizedEvent() = default;

        Core::EventType GetType() const override
        {
            return Core::EventType::WindowMaximized;
        }

        int GetCategory() const override
        {
            return Core::EventCategory::Engine;
        }

        std::string ToString() const override
        {
            return std::format("WindowMaximizedEvent");
        }
    };

    class WindowClosedEvent : public Core::CoreEvent
    {
    public:
        WindowClosedEvent()
        {
            m_name = "WindowClosed";
        }
        ~WindowClosedEvent() = default;

        Core::EventType GetType() const override
        {
            return Core::EventType::WindowClosed;
        }

        int GetCategory() const override
        {
            return Core::EventCategory::Engine;
        }

        std::string ToString() const override
        {
            return std::format("WindowClosedEvent");
        }
    };
} // namespace ZEngine::Rendering::Windows::Events
