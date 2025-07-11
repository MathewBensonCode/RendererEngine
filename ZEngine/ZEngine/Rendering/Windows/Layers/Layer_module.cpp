export module ZEngine.Rendering:Windows.Layers;

import std;
import :Windows.IUpdatable;
import :Windows.IEventable;
import :IRenderable;
import ZEngine.Core.Memory.Allocator;

namespace ZEngine::Rendering::Windows
{
    struct CoreWindow;

    export struct Layer : public IUpdatable, public IEventable, public IRenderable
    {
        Layer(const char* name = "default_layer")
        {
            Name = name;
        }

        virtual ~Layer()                                                                       = default;

        virtual void                           Initialize(Core::Memory::ArenaAllocator* arena) = 0;
        virtual void                           Deinitialize() {};

        Core::Memory::ArenaAllocator  LocalArena    = {};
        Core::Memory::ArenaAllocator* Arena         = nullptr;
        const char*                            Name          = nullptr;
        void*                                  ParentContext = nullptr;
        CoreWindow* ParentWindow   = nullptr;
    };
} // namespace ZEngine::Windows::Layers
