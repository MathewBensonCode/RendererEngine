#pragma once
#include <ZEngine/Core/IEventable.h>
#include <ZEngine/Core/IRenderable.h>
#include <ZEngine/Core/IUpdatable.h>
#include <ZEngine/Core/Memory/Allocator.h>
#include <ZEngine/Windows/CoreWindow.h>

namespace ZEngine::Windows
{
    class CoreWindow;
}

namespace ZEngine::Windows::Layers
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
