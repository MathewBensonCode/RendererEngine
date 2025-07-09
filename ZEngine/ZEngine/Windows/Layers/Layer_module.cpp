export module ZEngine.Windows:Layers;

import std;
import :IUpdatable;
import :IEventable;
import ZEngine.Core.Memory.Allocator;
import ZEngine.Rendering;

namespace ZEngine::Windows
{
    struct CoreWindow;

    export struct Layer : public IUpdatable, public IEventable, public Rendering::IRenderable
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
