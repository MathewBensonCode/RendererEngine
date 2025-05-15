#pragma once
#include <ZEngine/Event/MouseButtonMovedEvent.h>
#include <ZEngine/Event/MouseButtonPressedEvent.h>
#include <ZEngine/Event/MouseButtonReleasedEvent.h>
#include <ZEngine/Event/MouseButtonWheelEvent.h>

namespace ZEngine::Inputs
{

    struct IMouseEventCallback
    {
        IMouseEventCallback()  = default;
        ~IMouseEventCallback() = default;

        virtual bool OnMouseButtonPressed(ZEngine::Event::MouseButtonPressedEvent&)   = 0;
        virtual bool OnMouseButtonReleased(ZEngine::Event::MouseButtonReleasedEvent&) = 0;
        virtual bool OnMouseButtonMoved(ZEngine::Event::MouseButtonMovedEvent&)       = 0;
        virtual bool OnMouseButtonWheelMoved(ZEngine::Event::MouseButtonWheelEvent&)  = 0;
    };
} // namespace ZEngine::Inputs
