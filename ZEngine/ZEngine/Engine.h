#pragma once

#include <ZEngine/Core/IEventable.h>
#include <ZEngine/Core/IInitializable.h>
#include <ZEngine/Core/IRenderable.h>
#include <ZEngine/Core/IUpdatable.h>
#include <ZEngine/Core/TimeStep.h>
#include <ZEngine/EngineConfiguration.h>
#include <ZEngine/Event/EngineClosedEvent.h>
#include <ZEngine/Event/EventDispatcher.h>
#include <ZEngine/Event/KeyPressedEvent.h>
#include <ZEngine/Event/KeyReleasedEvent.h>
#include <ZEngine/Window/CoreWindow.h>
#include <ZEngine/ZEngineDef.h>

namespace ZEngine
{
    struct Engine
    {
        Engine()              = delete;
        Engine(const Engine&) = delete;
        ~Engine()             = delete;

        static void Initialize(const EngineConfiguration&);

        static void ProcessEvent();
        static void Update(Core::TimeStep delta_time);
        static void Render();

        static void Start();

        static Core::TimeStep                   GetDeltaTime();
        static Ref<ZEngine::Window::CoreWindow> GetWindow();

        static void Deinitialize();
        static void Dispose();

        static bool OnEngineClosed(Event::EngineClosedEvent&);

    private:
        static void                             Run();
        static bool                             m_request_terminate;
        static float                            m_last_frame_time;
        static Core::TimeStep                   m_delta_time;
        static Ref<ZEngine::Window::CoreWindow> m_window;
    };

    Engine* CreateEngine(const EngineConfiguration&);
} // namespace ZEngine
