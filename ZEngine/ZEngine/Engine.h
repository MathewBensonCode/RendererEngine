#pragma once
#include <ZEngine/EngineConfiguration.h>
#include <ZEngine/Event/EngineClosedEvent.h>
#include <ZEngine/Helpers/IntrusivePtr.h>
#include <ZEngine/Windows/CoreWindow.h>

namespace ZEngine
{
    struct Engine
    {
        static void                 Initialize(ZEngine::Core::Memory::ArenaAllocator* arena, ZRawPtr(ZEngine::Windows::CoreWindow) const);
        static void                 Run();
        static Windows::CoreWindow* GetWindow();
        static void                 Deinitialize();
        static void                 Dispose();
        static bool                 OnEngineClosed(Event::EngineClosedEvent&);

    private:
        Engine()              = delete;
        Engine(const Engine&) = delete;
        ~Engine()             = delete;
    };
} // namespace ZEngine
