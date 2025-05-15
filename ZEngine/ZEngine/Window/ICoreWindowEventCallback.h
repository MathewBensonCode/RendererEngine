#pragma once
#include <ZEngine/Event/WindowClosedEvent.h>
#include <ZEngine/Event/WindowMaximizedEvent.h>
#include <ZEngine/Event/WindowMinimizedEvent.h>
#include <ZEngine/Event/WindowResizedEvent.h>
#include <ZEngine/Event/WindowsRestoredEvent.h>

namespace ZEngine::Window
{
    struct ICoreWindowEventCallback
    {
        ICoreWindowEventCallback()  = default;
        ~ICoreWindowEventCallback() = default;

        virtual bool OnWindowClosed(Event::WindowClosedEvent&)       = 0;
        virtual bool OnWindowResized(Event::WindowResizedEvent&)     = 0;
        virtual bool OnWindowMinimized(Event::WindowMinimizedEvent&) = 0;
        virtual bool OnWindowMaximized(Event::WindowMaximizedEvent&) = 0;
        virtual bool OnWindowRestored(Event::WindowRestoredEvent&)   = 0;
    };
} // namespace ZEngine::Window
