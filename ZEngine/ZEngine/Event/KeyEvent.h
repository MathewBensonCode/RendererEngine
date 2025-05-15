#pragma once
#include <ZEngine/Event/CoreEvent.h>
#include <ZEngine/Inputs/KeyCode.h>
#include <ZEngine/ZEngineDef.h>

namespace ZEngine::Event
{

    class KeyEvent : public CoreEvent
    {
    public:
        KeyEvent(ZENGINE_KEYCODE key) : m_keycode(key) {}

        ZENGINE_KEYCODE GetKeyCode() const
        {
            return m_keycode;
        }

        EVENT_CATEGORY(Keyboard | EventCategory::Input)

    protected:
        ZENGINE_KEYCODE m_keycode;
    };
} // namespace ZEngine::Event
