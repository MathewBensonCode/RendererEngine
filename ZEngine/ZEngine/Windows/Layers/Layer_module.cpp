export module ZEngine.Windows.Layers.Layer;

import std;
import ZEngine.Core.IEventable;
import ZEngine.Core.IRenderable;
import ZEngine.Core.IUpdatable;
import ZEngine.Core.Memory.Allocator;
import ZEngine.Windows.CoreWindow;

export namespace ZEngine::Windows::Layers
{

    struct Layer : public Core::IUpdatable, public Core::IEventable, public Core::IRenderable
    {
        Layer(const char* name = "default_layer")
        {
            Name = name;
        }

        virtual ~Layer()                                                                       = default;

        virtual void                           Initialize(Core::Memory::ArenaAllocator* arena) = 0;
        virtual void                           Deinitialize() {};

        ZEngine::Core::Memory::ArenaAllocator  LocalArena    = {};
        ZEngine::Core::Memory::ArenaAllocator* Arena         = nullptr;
        const char*                            Name          = nullptr;
        void*                                  ParentContext = nullptr;
        ZRawPtr(ZEngine::Windows::CoreWindow) ParentWindow   = nullptr;
    };
} // namespace ZEngine::Windows::Layers
