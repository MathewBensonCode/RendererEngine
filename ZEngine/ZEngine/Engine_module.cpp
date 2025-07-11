export module ZEngine.Engine;

import std;
import ZEngine.EngineConfiguration;
import ZEngine.Event.EngineClosedEvent;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.Rendering;
import ZEngine.Core.Memory.Allocator;

namespace ZEngine
{
    export struct Engine
    {
        static void                 Initialize(ZEngine::Core::Memory::ArenaAllocator* arena, ZEngine::Rendering::Windows::CoreWindow*);
        static void                 Run();
        static Rendering::Windows::CoreWindow* GetWindow();
        static void                 Deinitialize();
        static void                 Dispose();
        static bool                 OnEngineClosed(Event::EngineClosedEvent&);

    private:
        Engine()              = delete;
        Engine(const Engine&) = delete;
        ~Engine()             = delete;
    };
} // namespace ZEngine
